#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
long long ar[mxN + 5] , seg[mxN << 2];

long long Merge(long long x , long long y) {
    return x + y;
}
void Build(int cur, int left , int right) {
    if (left == right) {
        seg[cur] = ar[left];
        return ;
    }
    int mid = (left + right) >> 1;
    Build(cur << 1 , left , mid);
    Build(cur << 1 | 1, mid + 1, right);
    seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
}
void Update(int cur , int left , int right , int pos , int val) {
    if (right < pos || pos < left) return;
    if (pos <= left && right <= pos) {
        seg[cur] = val;
        return;
    }
    int mid = (left + right) >> 1;
    Update(cur << 1 , left , mid , pos , val);
    Update(cur << 1 | 1 , mid + 1 , right , pos , val);
    seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
}
long long Query(int cur , int left , int right , int l , int r) {
    if (right < l || r < left ) return 0;
    if (l <= left && right <= r) return seg[cur];
    int mid = (left + right) / 2;
    return Merge(Query(cur << 1 , left , mid , l , r) , Query(cur << 1 | 1 , mid + 1, right , l , r));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    Build(1 , 1 , n);
    while (q--) {
        int typ; cin >> typ;
        if (typ == 1) {
            int pos , val; cin >> pos >> val;
            Update(1 , 1, n , pos , val);
        } else if (typ == 2) {
            int l , r; cin >> l >> r;
            cout << Query(1 , 1, n , l , r) << "\n";
        }
    }    
    return 0;
}