#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
vector <int> g[mxN + 5];
vector <int> depth(mxN + 5 , 0);

int mx = 0;
int node = 0;

void Dfs(int u,int cnt, int par = -1) {
    if (mx < cnt) {
        node = u;
        mx = cnt;
    }
    for (int v : g[u]) {
        if (v == par) continue;
        Dfs(v , cnt + 1, u);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    Dfs(1 , 1);
    Dfs(node , 1);
    cout << mx - 1 << "\n";
    return 0;
}