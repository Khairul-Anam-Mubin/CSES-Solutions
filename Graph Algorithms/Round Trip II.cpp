#include  <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
vector <int> g[mxN + 1];
int n , m;
bool vis[mxN + 1];
int color[mxN + 1];
int parent[mxN + 1];
vector <int> ans;
void Dfs(int u) {
    if (ans.size()) return;
    if (color[u] == 0) {
        color[u] = 1;
    } else if (color[u] == 2) {
        return;
    } else if (color[u] == 1) {
        //cycle
        int now = u;
        ans.push_back(now);
        now = parent[now];
        while (now != u) {
            ans.push_back(now);
            now = parent[now];
        }
        ans.push_back(now);
        return;
    }
    for (int v : g[u]) {
        parent[v] = u;
        Dfs(v);
    }
    color[u] = 2; 
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
    reverse(ans.begin(), ans.end());
    if (ans.size()) {
        cout << ans.size() << "\n";
        for (int x : ans) cout << x << " ";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}