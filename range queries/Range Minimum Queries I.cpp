#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
const int INF = 2e9;
int ar[mxN + 5];
int seg[mxN * 4];

int Merge(int x , int y) {
    return min(x , y);
}
void Build(int cur , int left , int right) {
    if (left == right) {
        seg[cur] = ar[left];
        return;
    }
    int mid = (left + right) >> 1;
    Build(cur << 1, left , mid);
    Build(cur << 1 | 1, mid + 1 , right);
    seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
}
int Query(int cur , int left , int right , int l , int r) {
    if (l > right || r < left) return INF;
    if (l <= left && right <= r) return seg[cur];
    int mid = (left + right) >> 1;
    return Merge(Query(cur << 1 , left , mid , l , r) , Query(cur << 1 | 1, mid + 1 , right , l , r));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    Build(1 , 1 , n);
    while (q--) {
        int l , r; cin >> l >> r;
        cout << Query(1 , 1 , n , l , r) << "\n";
    }
    return 0;
}