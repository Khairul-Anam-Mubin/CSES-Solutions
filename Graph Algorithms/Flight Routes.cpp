#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define inf18 1e18
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m, k;
    cin >> n >> m >> k;
    vector <pair <int , int>> g[n + 1];
    for (int i = 0; i < m; i++) {
        int u , v, w; cin >> u >> v >> w;
        g[u].push_back({v , w});
    }
    ll track[n + 1];
    memset(track, 0, sizeof(track));
    priority_queue <pair <ll , ll>> pq;
    pq.push({0 , 1});
    while (!pq.empty()) {
        ll wu = -pq.top().first;
        ll u = pq.top().second;
        track[u]++;
        pq.pop();
        if (u == n) cout << wu << " ";
        if (u == n && track[u] == k) return 0;
        if (track[u] <= k) {
            for (auto it : g[u]) {
                pq.push({-(wu + it.second), it.first});
            }
        }
    }
    return 0;
}