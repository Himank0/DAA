#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n];
    int u, v, wt;
    for(int i=0; i<m; i++) {
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    int *parent = new int[n];
    int *key = new int[n];
    bool *mst = new bool[n];

    for(int i=0; i<n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    key[0] = 0;
    pq.push({0,0}); // pq.push({keyvalue, keyindex})


    // tc = n + e + nlogn ===> O(nlogn)
    for(int count = 0; count < n-1; count++) {
        // int minWeight = INT_MAX, u;
       
        // for(int i=0; i<n; i++) {
        //     if (!mst[i] && key[i] < minWeight) {
        //         minWeight = key[i];
        //         u = i;
        //     }
        // }
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;
        for(auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (!mst[v] and key[v] > weight) {
                parent[v] = u;
                pq.push({key[v], v});
                key[v] = weight;
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << parent[i] << " - " << i << endl;
    }

    return 0;
}