#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    ll kth; cin >> kth;
    s += "$";
    int n = s.size();

    vector <int> p(n) , c(n);
    vector <int> cnt(256, 0), pos(256);
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    pos[0] = 0;
    for (int i = 1; i < 256; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        p[pos[s[i]]] = i;
        pos[s[i]]++;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        c[p[i]] = c[p[i - 1]];
        if (s[p[i]] != s[p[i - 1]]) {
            c[p[i]]++;
        }
    }
    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        cnt.assign(n , 0);
        pos.resize(n);
        for (int x : c) {
            cnt[x]++;
        }
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        vector <int> p_new(n);
        for (int i = 0; i < n; i++) {
            p_new[pos[c[p[i]]]] = p[i];
            pos[c[p[i]]]++;
        }
        p = p_new;
        vector <int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            c_new[p[i]] = c_new[p[i - 1]];
            pair <int , int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair <int , int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if (prev != cur) {
                c_new[p[i]]++;
            }
        }
        c = c_new;
    }
    vector <int> lcp(n);
    lcp[0] = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        int pi = c[i];
        int j = p[pi - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
            k++;
        }
        lcp[pi] = k;
        k = max(0 , k - 1);
    }
    vector <ll> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {   
        dp[i] = dp[i - 1] + n - p[i] - 1 - lcp[i];
        //cout << lcp[i] << " " << s.substr(p[i], n - p[i] - 1)  << " " << p[i] << " " << dp[i] << "\n";
    }
    for (int i = 1; i < n; i++) {
        if (kth == dp[i]) {
            cout << s.substr(p[i], n - p[i] - 1) << "\n";
            break;
        } else if (dp[i] > kth) {
            ll len = kth - dp[i - 1] + lcp[i];
            cout << s.substr(p[i] , len) << "\n";
            break;
        }
    }
    return 0;
}

/*
b a a b a a
0 1 2 3 4 5

0 a      5 -> 1 -> 1
1 aa     4 -> 1 -> 2
2 aabaa  1 -> 3 -> 5
1 abaa   2 -> 3 -> 8
0 baa    3 -> 3 -> 11
3 baabaa 0 -> 3 -> 14
*/