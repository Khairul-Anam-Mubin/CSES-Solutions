#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 2e6 + 1;
ll base = 1949313259, mod = 2091573227;
ll po[mxN + 1] , inv[mxN + 1];
ll prefix_hash[mxN + 1];

ll BigMod(ll b, ll p , ll m) {
    if (p == 0) return 1;
    if (p & 1) return b * BigMod(b , p - 1, m) % m;
    ll res = BigMod(b , p / 2, m) % m;
    return res * res % m;
}
void Generate() {
    po[0] = inv[0] = 1;
    ll modInv = BigMod(base , mod - 2 , mod);
    for (int i = 1; i <= mxN; i++) {
        po[i] = po[i - 1] * base % mod;
        inv[i] = inv[i - 1] * modInv % mod;
    }
}
void ComputePrefixHash(string &s) {
    Generate();
    int n = s.size();
    prefix_hash[0] = 0;
    for (int i = 1; i <= n; i++) 
        prefix_hash[i] = (prefix_hash[i - 1] + (s[i - 1] * po[i - 1])) % mod;
}
ll GetSubStrHash(int l , int r) {
    ll hash = (prefix_hash[r + 1] - prefix_hash[l]) * inv[l] % mod;
    if (hash < 0) hash += mod;
    return hash;
}
string LexicographicalMinimalRotation(string s) {
    s += s;
    ComputePrefixHash(s);
    int n = s.size();
    n /= 2;
    int k = 0;
    for (int i = 1; i < n; i++) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (GetSubStrHash(i , i + mid - 1) == GetSubStrHash(k , k + mid - 1)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (lo <= n - 1) {
            if (s[i + lo - 1] < s[k + lo - 1]) {
                k = i;
            }
        }
    }
    return s.substr(k , n);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    string ans = LexicographicalMinimalRotation(s);
    cout << ans << "\n";
    return 0;
}
