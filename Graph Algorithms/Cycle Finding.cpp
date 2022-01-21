#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct edge{
    ll u , v , w;
};
int main() {
    cin.tie(0);
    cout.tie(0);
 
    int n , m; cin >> n >> m;
    edge edges[m];
    ll cost[n + 1];
    int parents[n + 1];
    for (int i = 0; i <= n; i++) {
        cost[i] = 1e18;
        parents[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    int flag = 0;
    cost[1] = 0; 
    for (int i = 0; i < n; i++) {
        flag = 0;
        for (auto it : edges) {
            if (cost[it.v] > cost[it.u] + it.w) {
                cost[it.v] = cost[it.u] + it.w;
                parents[it.v] = it.u;
                flag = it.v;
            }
        }
    }
    if (flag == 0) {
        cout << "NO\n";
    } else {
        for (int i = 0; i < n; i++) flag = parents[flag];
        int par = parents[flag];
        vector <int> ans;
        ans.push_back(flag);
        ans.push_back(par);
        while (par != flag) {
            par = parents[par];
            ans.push_back(par);
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        for (int u : ans) cout << u << " ";
    }
    return 0;
}