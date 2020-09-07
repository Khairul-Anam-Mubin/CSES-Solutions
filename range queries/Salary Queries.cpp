#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 6e5;
 
struct node {
    char c;
    int f, s;
} qr[mxN]; 
 
int ar[mxN];  
int seg[mxN << 2];
 
int id = 1;
vector <int> vec, v, all;
int mapp(int x) {
    int ind = lower_bound(v.begin() , v.end(), x) - v.begin();
    return vec[ind];
}
void Compress() {  
    sort(all.begin() , all.end());
    for (int i = 0; i < (int)all.size(); ) {
        int x = all[i];
        v.emplace_back(x);
        while (i < (int)all.size() && x == all[i] ) i++;
        vec.emplace_back(id);
        id++;
    }
}
void Update(int cur, int left, int right ,int idx, int val) {
    if (idx > right || idx < left) return;
    if (left >= idx && right <= idx) {
        seg[cur] += val;
        return;
    } 
    int mid = (left + right) >> 1;
    Update(cur << 1 , left , mid , idx , val);
    Update(cur << 1 | 1 , mid + 1, right, idx, val);
    seg[cur] = seg[cur << 1] + seg[cur << 1 | 1];
}
int Query(int cur, int left, int right, int l, int r) {
    if (l > right || r < left) return 0;
    if (left >= l && right <= r) return seg[cur];
    int mid = (left + right) >> 1;
    int q1 = Query(cur << 1, left , mid , l , r);
    int q2 = Query(cur << 1 | 1, mid + 1, right, l , r);
    return q1 + q2;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, q; cin >> n >> q;
 
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        all.emplace_back(ar[i]);
    }
 
    for (int i = 0; i < q; i++) {
        char ch; cin >> ch;
        int a , b;
        cin >> a >> b;
        if (ch == '!') a--;        
        qr[i] = {ch ,a, b};
        if (ch == '?') all.emplace_back(a);
        all.emplace_back(b);
    }
 
    Compress();
    for (int i = 0; i < q; i++) {
        if (qr[i].c == '?') 
            qr[i].f = mapp(qr[i].f); 
        qr[i].s = mapp(qr[i].s);
    }
    for (int i = 0 ; i < n; i++) ar[i] = mapp(ar[i]);
 
    for (int i = 0; i < n; i++) Update(1 , 1, id + 2, ar[i], 1);
    for (int i = 0; i < q; i++) {
        if (qr[i].c == '?') {
            cout << Query(1 , 1, id + 2, qr[i].f, qr[i].s) << "\n";
        } else {
            if (ar[qr[i].f] == qr[i].s) continue;
            Update(1 , 1, id + 2, ar[qr[i].f], -1);
            Update(1 , 1, id + 2, qr[i].s, 1);
            ar[qr[i].f] = qr[i].s;
        }
    }
    return 0;
}