#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
vector <int> adj[mxN + 5];
int cnt[mxN + 5];
int ans[mxN + 5];

struct BinaryLifting_2{
    vector <vector <int>> parents;
    vector <int> depth;
    int root , po , nodes;
    // if nodes are 0 indexed then set root 0 else set 1
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
void Dfs(int u, int par) {
    for (int v : adj[u]) {
        if (v == par) continue;
        Dfs(v , u);
        ans[u] += ans[v];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m; cin >> n >> m;
    for (int i = 1; i <= n - 1; i++) {
        int u , v ; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    lca.Init(n , 1);
    while (m--) {
        int u , v; cin >> u >> v;
        int Lca = lca.LCA(u , v);
        ans[u]++;
        ans[v]++;
        ans[Lca]--;
        ans[lca.parents[Lca][0]]--;
    }
    Dfs(1 , 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}