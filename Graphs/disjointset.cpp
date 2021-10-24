#include <iostream>
using namespace std;

class disjointSet {
    int *parent, *rank, n;
public:
    disjointSet(int n) {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeset();
    }
    void makeset() {
        for(int i=1; i<=n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    int findparent(int node) {
        if (parent[node] == node) {
            return node;
        }
        parent[node] = findparent(parent[node]);
        return parent[node];
    }
    void makeunion(int u, int v) {
        u = findparent(u);
        v = findparent(v);
        
        if (rank[u] > rank[v]) {
            parent[v] = u;
        }
        else if (rank[v] > rank[u]) {
            parent[u] = v;
        }
        else {
            parent[v] = u;
            rank[u]++;
         }
    }    
    void display() {
        for(int i=1; i<=n; i++) {
            cout << parent[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    disjointSet dis(7);
    dis.makeunion(1,2);
    dis.makeunion(2,3);
    dis.makeunion(4,5);
    dis.makeunion(6,7);
    dis.makeunion(5,6);
    // dis.makeunion(3,7);
    dis.display();
    
    int a = 2, b = 6;
    if (dis.findparent(a) == dis.findparent(b)) {
        cout << "both have same parent ,that is, both are same components" << endl;
        // cout << "parent of " << a << " is " << dis.findparent(a) << endl;
        // cout << "parent of " << b <<" is " << dis.findparent(b) << endl;
    }
    else {
        cout << "both have different parents ,that is, both are different components" << endl;
        // cout << "parent of " << a << " is " << dis.findparent(a) << endl;
        // cout << "parent of " << b <<" is " << dis.findparent(b) << endl;
    }
    return 0;
}
