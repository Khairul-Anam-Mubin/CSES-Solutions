#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5;
ll ar[mxN + 5];
vector <int> g[mxN + 5];
vector <int> sub(mxN + 5) , tin(mxN + 5), flat(mxN + 5);
int timer = 1;

ll seg[mxN << 2];

void Build(int cur, int left, int right) {
    if (left == right) {
        seg[cur] = ar[flat[left]];
        return;
    }
    int mid = (right + left) >> 1;
    Build(cur << 1 , left , mid);
    Build(cur << 1 | 1, mid + 1, right);
    seg[cur] = seg[cur << 1] + seg[cur << 1 | 1];
}
void Update(int cur, int left, int right , int pos, int val) {
    if (pos > right || pos < left) return;
    if (left >= pos && right <= pos) {
        seg[cur] = val;
        return;
    }
    int mid = (right + left) >> 1;
    Update(cur << 1, left , mid , pos , val);
    Update(cur << 1 | 1, mid + 1, right , pos , val);
    seg[cur] = seg[cur << 1] + seg[cur << 1 | 1];
}
ll Query(int cur, int left , int right, int l , int r) {
    if (l > right || r < left) return 0;
    if (left >= l && right <= r) return seg[cur];
    int mid = (left + right) >> 1;
    return Query(cur << 1, left, mid , l , r) + Query(cur << 1 | 1, mid + 1, right , l , r);
}
void Dfs(int u , int par = -1) {
    sub[u] = 1;
    tin[u] = timer;
    flat[timer] = u;
    timer++;
    for (int v: g[u]) {
        if (v == par) continue;
        Dfs(v , u);
        sub[u] += sub[v];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    for (int i = 1; i <= n - 1; i++) {
        int u , v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    Dfs(1);
    Build(1 , 1, n);
    while (q--) {
        int typ ; cin >> typ;
        if (typ == 1) {
            int pos, val;
            cin >> pos >> val;
            Update(1 , 1, n , tin[pos] , val);
        } else {
            int pos; cin >> pos;
            cout << Query(1 ,1 , n, tin[pos], tin[pos] + sub[pos] - 1) << "\n";
        }
    }
    return 0;
}