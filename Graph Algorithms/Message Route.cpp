#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
vector <int> g[mxN + 1];
vector <bool> vis(mxN + 1 , 0);
vector <int> path(mxN + 1 , -1) , dis(mxN + 1 , 0);
void Dfs(int u ) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (vis[v]) continue;
        Dfs(v);
    }
}
int BFS(int st , int ed) {
    vis[st] = 1;
    queue <int> q;
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop(); 
        if (u == ed) return dis[u];
        for (int v : g[u]) {
            if (vis[v] == 0) {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.push(v);
                path[v] = u;
            }
        }
    }
    return -1;
}
void PathPrint(int u) {
    vector <int> ans;
    while (u != -1) {
        ans.push_back(u);
        u = path[u];
    }
    reverse(ans.begin() , ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u , v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int res = BFS(1 , n);
    if (res == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        PathPrint(n);
    }
    return 0;
}