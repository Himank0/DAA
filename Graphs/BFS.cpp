// #include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class solution {
    void BreathFirstSearch(int i, vector<int> &vis, vector <int> adj[], vector <int> &bfs) {
        queue <int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : adj[node]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
public:
    vector <int> BFS(int no_of_nodes, vector <int> adj[]) {
        vector <int> bfs;
        vector <int> vis(no_of_nodes+1, 0);
        for(int i=1; i <= no_of_nodes; i++) {
            if(!vis[i]) {
               BreathFirstSearch(i, vis, adj, bfs);
            }
        }
        return bfs;
    }
};
int main() 
{
    int no_of_nodes, no_of_edges;
    cin >> no_of_nodes >> no_of_edges;
    vector <int> adj[no_of_nodes+1];
    for(int i=0; i<no_of_edges; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solution s;
    vector <int> ans = s.BFS(no_of_nodes, adj);
    for(int i=0; i<no_of_nodes; i++) 
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}