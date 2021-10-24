#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class solution {
public:
    vector <int> BFS(int n, vector <int> adj[]) {
        queue <int> q;
        vector <int> count(n, 0);
        for (int i=0; i<n; i++) {
            for(auto it : adj[i]) {
                count[it]++;
            }
        }
        for(int i=0; i<n; i++) {
            if (count[i] == 0) {
                q.push(i);
            }
        }
        vector <int> ans;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto it : adj[x]) {
                count[it]--;
                if (count[it] == 0) {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> adj[n];
    for(int i=0; i<n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    solution s;
    vector <int> ans = s.BFS(n, adj);
    for(int i=0; i<n; i++) 
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}