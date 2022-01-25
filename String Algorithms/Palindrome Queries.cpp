#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e5;

ll base = 131, mod = 1e9 + 7;
ll po[mxN + 1] , inv[mxN + 1];

ll BigMod(ll b, ll p, ll m) {
    if (p == 0) return 1;
    if (p & 1) return b * BigMod(b , p - 1, m) % m;
    ll res = BigMod(b , p / 2, m) % m;
    return res * res % m;
}
void Generate() {
    po[0] = inv[0] = 1;
    ll modInv = BigMod(base , mod - 2, mod);
    for (int i = 1; i <= mxN; i++) {
        po[i] = po[i - 1] * base % mod;
        inv[i] = inv[i - 1] * modInv % mod;
    }
}
int n;
string s;
ll prehash[mxN << 2], sufhash[mxN << 2];

void Build(int cur, int left, int right) {
    if (left == right) {
        prehash[cur] = s[left] * po[left - 1] % mod;
        sufhash[cur] = s[left] * po[n - left] % mod;
        return;
    }
    int mid = (left + right) >> 1;
    Build(cur << 1 , left , mid);
    Build(cur << 1 | 1 , mid + 1, right);
    prehash[cur] = prehash[cur << 1] + prehash[cur << 1 | 1] % mod;
    sufhash[cur] = sufhash[cur << 1] + sufhash[cur << 1 | 1] % mod;
}
void Update(int cur, int left , int right, int pos, char ch) {
    if (right < pos || left > pos) return;
    if (left == pos && pos == right) {
        prehash[cur] = ch * po[left - 1] % mod;
        sufhash[cur] = ch * po[n - left] % mod;
        return;
    }
    int mid = (left + right) >> 1;
    Update(cur << 1, left, mid, pos, ch);
    Update(cur << 1 | 1, mid + 1, right, pos, ch);
    prehash[cur] = prehash[cur << 1] + prehash[cur << 1 | 1] % mod;
    sufhash[cur] = sufhash[cur << 1] + sufhash[cur << 1 | 1] % mod;
}
ll QueryPreHash(int cur, int left, int right, int l , int r) {
    if (right < l || left > r) return 0;
    if (left >= l && right <= r) {
        return prehash[cur];
    }
    int mid = (left + right) >> 1;
    ll q1 = QueryPreHash(cur << 1, left, mid, l, r);
    ll q2 = QueryPreHash(cur << 1 | 1, mid + 1, right, l, r);
    return (q1 + q2) % mod;}
ll QuerySufHash(int cur, int left, int right, int l , int r) {
    if (right < l || left > r) return 0;
    if (left >= l && right <= r) {
        return sufhash[cur];
    }
    int mid = (left + right) >> 1;
    ll q1 = QuerySufHash(cur << 1, left, mid, l, r);
    ll q2 = QuerySufHash(cur << 1 | 1, mid + 1, right, l, r);
    return (q1 + q2) % mod;
}
bool IsPalindrome(int l , int r) {
    ll ph = QueryPreHash(1 , 1 , n, l , r) * inv[l - 1] % mod;
    if (ph < 0) ph += mod;
    ll sf = QuerySufHash(1 , 1 , n, l , r) * inv[n - r] % mod;
    if (sf < 0) sf += mod;
    //cout << ph << " " << sf << "\n";
    return (ph == sf);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Generate();
    int k; 
    
    cin >> n >> k;
    cin >> s;
    s = "#" + s;
    
    Build(1 , 1, n);
    
    while (k--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int pos;
            char ch;
            cin >> pos >> ch;
            Update(1 ,1 ,n , pos , ch);
        } else {
            int l , r; cin >> l >> r;
            if (IsPalindrome(l , r)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}