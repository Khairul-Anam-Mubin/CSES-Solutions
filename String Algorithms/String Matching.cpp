#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1e6;

/****************KMP*******************/
int pfix_array[mxN + 1];
void BuildPrefixArray(string &t) {
    int tlen = t.size();
    pfix_array[0] = 0;
    for (int i = 1, j = 0; i < tlen; ) {
        if (t[i] == t[j]) pfix_array[i++] = ++j; 
        else if (j != 0) j = pfix_array[j - 1];
        else pfix_array[i++] = 0;        
    }
} 
int NumOfOccurancesKMP(string &s , string &t) {
    BuildPrefixArray(t);
    int slen = s.size();
    int tlen = t.size();
    int cnt = 0;
    for (int i = 0, j = 0; i < slen; ) {
        if (s[i] == t[j]) i++ , j++;
        else if (j == 0) i++;
        else j = pfix_array[j - 1];
        if (j == tlen) cnt++, j = pfix_array[j - 1];
    }
    return cnt;
}
/*************************Rabin Karp (Hashing)*****************************/

ll mod = 1e9 + 7;
ll base = 31;
ll po[mxN + 1] , inv[mxN + 1];
ll prefix_hash[mxN + 1];

ll BigMod(ll b , ll p , ll m) {
    if (p == 0) return 1;
    if (p & 1) return (b * BigMod(b , p - 1, m)) % m;
    ll res = BigMod(b , p / 2, m) % m;
    return (res * res) % m;
}
void Generate() {
    po[0] = inv[0] = 1;
    ll modInv = BigMod(base , mod - 2 , mod);
    for (int i = 1; i <= mxN; i++) {
        po[i] = po[i - 1] * base % mod;
        inv[i] = inv[i - 1] * modInv % mod;
    }
}
ll GetHash(string &s) {
    ll hash = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        hash += s[i] * po[i] % mod;
        hash %= mod;
    }
    return hash;
}
void ComputePrefixHash(string &s) {
    int n = s.size();
    prefix_hash[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix_hash[i] = prefix_hash[i - 1] + s[i - 1] * po[i - 1] % mod;
        prefix_hash[i] %= mod;
    }
}
ll GetSubStrHash(int l , int r) {
    ll hash = (prefix_hash[r + 1] - prefix_hash[l]) * inv[l] % mod;
    hash += mod;
    hash %= mod;
    return hash;
}
int NumOfOccurancesRabinKarp(string &s, string &t) {
    Generate();
    ComputePrefixHash(s);
    ll Pattern_hash = GetHash(t);
    int tlen = t.size();
    int slen = s.size();
    int cnt = 0;
    for (int i = 0; i < slen - tlen + 1; i++) {
        int l = i;
        int r = i + tlen - 1;
        if (GetSubStrHash(l , r) == Pattern_hash) cnt++;
    }
    return cnt;
}
int main() {
    string s; cin >> s;
    string t; cin >> t;
    int ans1 = NumOfOccurancesKMP(s , t);
    int ans2 = NumOfOccurancesRabinKarp(s , t);
    assert(ans1 == ans2);
    cout << ans1 << "\n";
    return 0;
}