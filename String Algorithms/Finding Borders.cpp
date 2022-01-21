#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mxN = 1e6;
/**************************KMP******************************/
int prefix_array[mxN + 1];
void BuildPrefixArray(string &s) {
    prefix_array[0] = 0;
    int n = s.size();
    for (int i = 1, j = 0; i < n; ) {
        if (s[i] == s[j]) {
            prefix_array[i++] = ++j;
        } else if (j != 0) {
            j = prefix_array[j - 1];
        } else {
            i++;
        }
    }
}
vector <int> FindingBordersKMP(string &s) {
    BuildPrefixArray(s);
    int n = s.size();
    vector <int> ans;
    for (int j = prefix_array[n - 1]; j != 0; ) {
        ans.push_back(j);
        j = prefix_array[j - 1];
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
/***********************(Hashing)**************************/
ll base = 31, mod = 1e9 + 7;
ll po[mxN + 1] , inv[mxN + 1];
ll prefix_hash[mxN + 1];

ll BigMod(ll b, ll p , ll m) {
    if (p == 0) return 1;
    if (p & 1) return (b * BigMod(b , p - 1, m)) % m;
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
void ComputePrefixHash(string &s) {
    Generate();
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        prefix_hash[i] = prefix_hash[i - 1] + s[i - 1] * po[i - 1] % mod;
        prefix_hash[i] %= mod;
    }
}
ll GetSubStrHash(int l, int r) {
    ll hash = (prefix_hash[r + 1] - prefix_hash[l]) * inv[l] % mod;
    hash += mod;
    hash %= mod;
    return hash;
} 
vector <int> FindingBordersHashing(string &s) {
    ComputePrefixHash(s);
    int len = s.size();
    vector <int> ans1;
    for (int i = 1; i < len; i++) {
        if (prefix_hash[i] == GetSubStrHash(len - i , len - 1)) {
            ans1.push_back(i);
        }
    }    
    return ans1;
}   
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    vector<int> ans1 = FindingBordersHashing(s);
    vector<int> ans2 = FindingBordersKMP(s);
    assert(ans1 == ans2);
    for (int i = 0; i < (int)ans2.size(); i++) {
        cout << ans2[i] << " ";
    }
    cout << "\n";
    return 0;   
}