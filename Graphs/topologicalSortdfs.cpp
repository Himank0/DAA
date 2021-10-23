#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class solution {
    void topoSort(int n, vector <int> adj[], vector <int> &vis, stack <int> &st) {
        vis[n] = 1;        
        for (auto it : adj[n]) {
            if (!vis[it]) {
                topoSort(it, adj, vis, st);
            }
        }
        st.push(n);
    }
public:
    vector <int> DFS(int n, vector <int> adj[]) {
        stack <int> st;
        vector <int> vis(n, 0);
        for(int i=0; i<n; i++) {
           if (!vis[i]) { 
               topoSort(i, adj, vis, st);
           }
        }
        vector <int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

};
int main() 
{
    int m,n;
    cin >> n >> m;
    vector <int> adj[n];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    solution s;
    vector <int> ans = s.DFS(n, adj);
    for(int i=0; i<n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}