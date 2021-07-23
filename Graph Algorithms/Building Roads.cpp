#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
vector <int> g[mxN + 1];
vector <bool> vis(mxN + 1 , 0);
void Dfs(int u ) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (vis[v]) continue;
        Dfs(v);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u , v; cin >> u >> v;
        u-- , v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            Dfs(i);
            ans.push_back(i);
        }
    }
    cout << int(ans.size()) - 1 << "\n";
    for (int i = 0; i + 1 < ans.size(); i++) {
        cout << ans[i] + 1 << " " << ans[i + 1] + 1 << "\n";
    }
    return 0;
}