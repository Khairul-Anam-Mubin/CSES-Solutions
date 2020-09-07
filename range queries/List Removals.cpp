#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int ar[mxN + 5];
int seg[mxN << 2];
int ans = 0;

void Build(int cur, int left , int right) {
    if (left == right) {
        seg[cur] = 1;
        return ;
    }
    int mid = (left + right) >> 1;
    Build(cur << 1, left , mid);
    Build(cur << 1| 1, mid + 1, right);
    seg[cur] = seg[cur << 1] + seg[cur << 1 | 1];
}
void Query(int cur, int left, int right,int pos) {
    if (left == right && pos == 1) {
        seg[cur] = 0;
        ans = ar[left];
        pos = 0;
        return;
    }
    int mid = (left + right) >> 1;
    if (seg[cur << 1] >= pos) {
        if (pos > 0)
            Query(cur << 1 , left , mid, pos);
    } else {
        pos -= seg[cur << 1];
        if (pos > 0)
            Query(cur << 1 | 1, mid + 1 , right , pos);
    }
    seg[cur] = seg[cur << 1] + seg[cur << 1 | 1];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    Build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int pos; cin >> pos;
        Query(1 , 1, n , pos);
        cout << ans << " ";
    }
    return 0;
}