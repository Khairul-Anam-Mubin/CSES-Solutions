#include  <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
vector <int> g[mxN + 1];
int n , m;
bool vis[mxN + 1];
int color[mxN + 1];
int parent[mxN + 1];
vector <int> orders;
bool isCycle = 0;

void Dfs(int u) {
    if (isCycle) return;
    if (color[u] == 0) {
        color[u] = 1;
    } else if (color[u] == 2) {
        return;
    } else if (color[u] == 1) {
        isCycle = 1;
        return;
    }
    for (int v : g[u]) {
        parent[v] = u;
        Dfs(v);
    }
    color[u] = 2; 
}
void dfs2(int u) {
    vis[u] = 1 ;
    for(int i = 0 ; i < g[u].size() ; i++) {
        int v = g[u][i] ;
        if(!vis[v])
            dfs2(v) ;
    }
    orders.push_back(u) ;
}
void topsort(int nodes) {
    for(int i = 0 ; i <= nodes ; i++)
        vis[i] = 0 ;
    for(int i = 1 ; i <= nodes ; i++) 
        if(!vis[i]) 
            dfs2(i) ;
    reverse(orders.begin() , orders.end()) ; // reversing the list to simply find the topological order
}
int main() {
    cin >> n >> m;
    for (int i = 0 ; i < m; i++) {
        int u , v; cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            parent[i] = i;
            Dfs(i);
        }
    }
    if (isCycle) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    topsort(n);
    for (int x : orders) cout << x << " ";
    return 0;
}