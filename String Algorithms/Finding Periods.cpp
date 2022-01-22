#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1e6;

ll base = 31 , mod = 1e9 + 7;
ll po[mxN + 1] , inv[mxN + 1];
ll prefix_hash[mxN + 1];

ll BigMod(ll b , ll p , ll m) {
    if (p == 0) return 1;
    if (p & 1) return b * BigMod(b , p - 1, m) % m;
    ll res = BigMod(b , p / 2 , m) % m;
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
    for (int i = 1; i <= n; i++) {
        prefix_hash[i] = (prefix_hash[i - 1] + (s[i - 1] * po[i - 1])) % mod;
    }
}
ll GetSubStrHash(int l , int r) {
    ll hash = (prefix_hash[r + 1] - prefix_hash[l]) * inv[l] % mod;
    if (hash < 0) hash += mod;
    return hash;
}
vector <int> FindingPeriodsHashing(string &s) {
    ComputePrefixHash(s);
    int n = s.size();
    vector <int> ans;
    for (int len = 1; len <= n; len++) {
        int cnt = 0;
        for (int i = 0; i + len - 1 < n; i += len) {
            int l = i;
            int r = l + len - 1;
            if (GetSubStrHash(l , r) == prefix_hash[len]) {
                cnt++;
            } else break;
        }
        if (cnt != 0) {
            int res = n % len;
            if (((n - res) / len) == cnt) {
                if (res == 0)
                    ans.push_back(len);
                else {
                    if (prefix_hash[res] == GetSubStrHash(n - res ,n - 1)) {
                        ans.push_back(len);
                    }
                }
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    vector <int> ans = FindingPeriodsHashing(s);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}