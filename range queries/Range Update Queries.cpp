#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
long long ar[mxN + 5] , seg[mxN << 2] , lazy[mxN << 2];

long long Merge(long long x ,long long y) {
    return x + y;
}
void PushDown(int cur , int left , int right) {
    if (lazy[cur] == 0) return;
    seg[cur] += (right - left + 1) * lazy[cur];
    if (left != right) {
        lazy[cur << 1] += lazy[cur];
        lazy[cur << 1 | 1] += lazy[cur];
    }
    lazy[cur] = 0;
}
void Build(int cur ,int left , int right) {
    lazy[cur] = 0;
    if (left == right) {
        seg[cur] = ar[left];
        return;
    }
    int mid = (left + right) >> 1;
    Build(cur << 1 ,left , mid);
    Build(cur << 1 | 1 , mid + 1, right);
    seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
}
void Update(int cur , int left , int right , int l , int r , int val) {
    if (lazy[cur] != 0) PushDown(cur , left , right);
    if (l > right || r < left) return;
    if (left >= l && right <= r) {
        lazy[cur] = val;
        PushDown(cur , left , right);
        return;
    }
    int mid = (left + right) >> 1;
    Update(cur << 1 , left , mid , l , r , val);
    Update(cur << 1 | 1 , mid + 1, right , l , r, val);
    seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
}
long long Query(int cur , int left , int right , int l , int r) {
    if (l > right || r < left) return 0;
    if (lazy[cur]) PushDown(cur , left , right);
    if (left >= l && right <= r) return seg[cur];
    int mid = (left + right) >> 1;
    return Merge(Query(cur << 1, left , mid , l , r), Query(cur << 1 | 1 , mid + 1 , right , l , r));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    Build(1 ,1, n);
    while (q--) {
        int typ; cin >> typ;
        if (typ == 1) {
            int l , r, val;
            cin >> l >> r >> val;
            Update(1 ,1 , n , l , r , val);
        } else {
            int pos; cin >> pos;
            cout << Query(1 , 1, n , pos , pos) << "\n";
        }
    }
    return 0;
}