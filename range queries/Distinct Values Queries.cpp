#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
const int block = 500;
int ar[mxN + 5], br[mxN + 5] , ans[mxN + 5];
int freq[mxN + 5];
map <int , int> mp;
int cnt = 0;
struct node {
    int l , r , id;
} Q[mxN + 5];
bool Cmp(node a , node b) {
    if (a.l / block != b.l / block) return a.l / block < b.l / block;
    return a.r < b.r;
}
void Add(int pos) {
    freq[ar[pos]]++;
    if (freq[ar[pos]] == 1) cnt++;
}
void Remove(int pos) {
    freq[ar[pos]]--;
    if (freq[ar[pos]] == 0) cnt--;
}
void Compress(int a[] , int n ) {
    sort(br , br + n);
    int now = 1;
    for (int i = 0; i < n; i++) {
        if (mp[br[i]] == 0) 
            mp[br[i]] = now++;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n , q; cin >> n >> q;
    
    for (int i = 0; i < n; i++) { 
        cin >> ar[i];
        br[i] = ar[i];
    }
    Compress(br , n);
    for (int i = 0; i < n; i++) {
        ar[i] = mp[ar[i]];
    }
    for (int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
        Q[i].l--; Q[i].r--;
    }
    sort(Q , Q + q, Cmp);
    int ML = 0 , MR = -1;
    for (int i = 0; i < q; i++) {
        int L = Q[i].l;
        int R = Q[i].r;
        while (ML > L) Add(--ML);
        while (MR < R) Add(++MR);
        while (ML < L) Remove(ML++);
        while (MR > R) Remove(MR--);
        ans[Q[i].id] = cnt;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}