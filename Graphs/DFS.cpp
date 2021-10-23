// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
class solution {
    void DFS(int i, vector <int> &dfs, vector <int> &vis, vector <int> adj[]) {
        dfs.push_back(i);
        vis[i] = 1;
        for(auto it : adj[i]) {
            if (!vis[it]) {
                DFS(it, dfs, vis, adj);
            }
        }
    }
    public:
    vector <int> DFS(int no_of_nodes, vector <int> adj[]) {
        vector <int> dfs;
        vector <int> vis(no_of_nodes+1, 0);
        for(int i=1; i<=no_of_nodes; i++) {
            if(!vis[i]) {
                DFS(i, dfs, vis, adj);
            }
        }
        return dfs;
    }
};
int main() 
{
    int n,m;
    cin >> n >> m;
    vector <int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solution s;
    vector <int> ans = s.DFS(n, adj);
    for(int i=0; i<n; i++) {
        cout << ans[i] <<" ";
    }
    cout << endl;
    return 0;
}
