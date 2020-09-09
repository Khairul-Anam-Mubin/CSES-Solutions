#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 2e5;
vector <int> adj[mxN + 5];
int mx, mxid;
void Dfs(int u, int cnt, int par = -1) {
    for (int v : adj[u]) {
        if (v == par) continue;
        Dfs(v , cnt + 1, u);
    }
    if (cnt > mx) {
        mx = cnt;
        mxid = u;
    }
}
struct BinaryLifting{
    vector <vector <int>> parents;
    vector <int> depth;
    int root , po , nodes;
    void Init(int _nodes) {
        Init(_nodes, 0);
    }
    void Init(int _nodes, int _root) {
        nodes = _nodes;
        root = _root;
        po = log2(nodes);
        parents.assign(nodes + 1, vector <int> (po + 1));
        depth.assign(nodes + 1 , 0);
        Dfs(root , 0);
    } 
    void Dfs(int u, int par) {
        parents[u][0] = par;
        depth[u] = depth[par] + 1;
        for (int i = 1; i <= po; i++) 
            parents[u][i] = parents[parents[u][i - 1]][i - 1];
        for (int v: adj[u]) {
            if (v == par) continue;
            Dfs(v , u);
        }
    }
    int LCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u , v);
        for (int i = po; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v])
                u = parents[u][i];
        }
        if ( u == v) return u;
        for (int i = po; i >= 0; i--) {
            if (parents[u][i] != parents[v][i]) { 
                u = parents[u][i];
                v = parents[v][i];
            }
        }
        return parents[u][0];
    }
    int GetDistance(int u , int v) {
        return (depth[u] + depth[v] - (2 * depth[LCA(u , v)]));
    }
}lca;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u , v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    lca.Init(n , 1);
    mx = -1, mxid = 0;
    Dfs(1 , 0);
    int fst = mxid;
    mx = -1, mxid = 0;
    Dfs(fst , 0);
    int sec = mxid;
    for (int i = 1; i <= n; i++) {
        cout << max(lca.GetDistance(i, fst) , lca.GetDistance(i, sec)  ) << " ";
    }
    return 0;
}