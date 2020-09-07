#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5;
ll ar[mxN + 5];

struct node {
    ll sum,prfx,sufx,maxsub;
}seg[mxN << 2];

node Make_data(ll x) {
    node now;
    now.sum = x;
    now.prfx = now.sufx = now.maxsub = max(0LL , x);
    return now;
}
node Merge(node &l, node &r) {
    node res;
    res.sum = l.sum + r.sum;
    res.prfx = max(l.prfx , l.sum + r.prfx);
    res.sufx = max(r.sufx , r.sum + l.sufx);
    res.maxsub = max(max(l.maxsub , r.maxsub) , l.sufx + r.prfx);
    return res;
}
void Build(int cur, int left, int right) {
    if (left == right) {
        seg[cur] = Make_data(ar[left]);
        return;
    }
    int mid = (left + right) >> 1;
    Build(cur << 1, left , mid);
    Build(cur << 1 | 1, mid + 1, right);
    seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
}
void Update(int cur, int left, int right, int pos, ll val) {
    if (pos > right || pos < left) return;
    if (left >= pos && right <= pos) {
        seg[cur] = Make_data(val);
        return;
    }
    int mid = (left + right) >> 1;
    Update(cur << 1, left , mid , pos , val);
    Update(cur << 1 | 1, mid + 1, right, pos , val);
    seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , m ; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    Build(1 ,1 ,n);
    
    while (m--) {
        int pos; cin >> pos;
        ll val; cin >> val;
        Update(1 , 1, n , pos , val);
        cout << seg[1].maxsub << "\n";
    }
    return 0;
}