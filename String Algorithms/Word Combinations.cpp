#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 5000;

ll mod = 1e9 + 7;
ll base = 31;
ll po[mxN + 1] , inv[mxN + 1];
ll pre_hash[mxN + 1];

ll BigMod(ll b , ll p , ll m) {
    if (p == 0) return 1;
    if (p & 1) return ((b % m) * (BigMod(b , p - 1 , m) % m)) % m; 
    ll res = BigMod(b , p / 2 , m) % m;
    return (res * res) % m;
}
void Generate() {
    po[0] = 1;
    inv[0] = 1;
    ll modInv = BigMod(base , mod - 2 , mod);
    for (int i = 1; i <= mxN; i++) {
        po[i] = po[i - 1] * base % mod;
        inv[i] = inv[i - 1] * modInv % mod;
    }
}
ll GetHash(string &s) {
    ll hash = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        hash = hash + (s[i] * po[i]) % mod;
        hash %= mod;
    }
    return hash;
}
void ComputePrefixHash(string &s) {
    int len = s.size();
    pre_hash[0] = 0;
    for (int i = 1; i <= len; i++) {
        pre_hash[i] = pre_hash[i - 1] + ((s[i - 1] * po[i - 1]) % mod);
        pre_hash[i] %= mod;
    }
}
ll GetSubStrHash(int l , int r) {
    ll hash = (((pre_hash[r + 1] - pre_hash[l]) % mod) * inv[l]) % mod;
    hash += mod;
    hash %= mod;
    return hash;
}
ll ways[mxN + 1];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Generate();
    string s; cin >> s;
    ComputePrefixHash(s);
    int k; cin >> k;
    vector <pair<int , ll>> dict_hashes[26];
    while (k--) {
        string t; cin >> t;
        if (t.size() > s.size()) continue;
        dict_hashes[t.back() - 'a'].push_back({t.size() , GetHash(t)});
    }
    for (int i = 0; i < 26; i++)
        sort(dict_hashes[i].begin() , dict_hashes[i].end());
    memset(ways , 0 , sizeof(ways));
    int n = s.size();
    ways[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (auto it : dict_hashes[s[i - 1] - 'a']) {
            if (it.first > i) break;
            if (i - it.first == 0 || ways[i - it.first] != 0) {
                if (GetSubStrHash(i - it.first , i - 1) == it.second) {
                    ways[i] += ways[i - it.first];
                    ways[i] %= mod;
                }
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        cout << ways[i] << " ";
    }
    cout << "\n";
    */
    cout << ways[n] << "\n";
    return 0;
}