#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    s += "$";
    int n = s.size();

    vector <int> p(n) , c(n);
    vector <int> cnt(256, 0) , pos(256);
    for (char ch : s) cnt[ch]++;
    pos[0] = 0;
    for (int i = 1; i < 256; i++) pos[i] = pos[i - 1] + cnt[i - 1];
    for (int i = 0; i < n; i++) {
        p[pos[s[i]]] = i;
        pos[s[i]]++;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        c[p[i]] = c[p[i - 1]];
        if (s[p[i]] != s[p[i - 1]]) c[p[i]]++;
    }
    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) p[i] = (p[i] - (1 << k) + n) % n;
        cnt.assign(n , 0);
        pos.resize(n);
        for (int x : c) cnt[x]++;
        pos[0] = 0;
        for (int i = 1; i < n; i++) pos[i] = pos[i - 1] + cnt[i - 1];
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
            pair <int , int> prev = {c[p[i - 1]] , c[(p[i - 1] + (1 << k)) % n]};
            pair <int , int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if (prev != cur) c_new[p[i]]++;
        }
        c = c_new;
    }
    vector <int> lcp(n);
    int k = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
        int pi = c[i];
        int j = p[pi - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[pi] = k;
        k = max(0 , k - 1);
    }
    /*
    for (int i = 1; i < n; i++) {
        cout << lcp[i] << " " << s.substr(p[i] , n - p[i]) << " " << n - p[i] - 1 << " " << p[i] << " " << c[p[i]] << "\n";
    }
    */
    vector <int> sorted_lcp;
    for (int i = 1; i < n; i++) {
        sorted_lcp.push_back(lcp[i]);
    }
    sort(sorted_lcp.begin() , sorted_lcp.end());
    //for (int x : sorted_lcp) cout << x << " ";
    //cout << "\n";
    for (int i = 1; i < n; i++) {
        int lo = 0, hi = sorted_lcp.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (sorted_lcp[mid] >= i) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        int ans = n - i - (n - lo - 1);
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}

/*
b a a b a a
0 1 2 3 4 5

0 a      5 -> 1 -> 1
1 aa     4 -> 2 -> 2
2 aabaa  1 -> 5 -> 5
1 abaa   2 -> 4 -> 8
0 baa    3 -> 3 -> 11
3 baabaa 0 -> 6 -> 14
*/

/*
a b a b
0 1 2 3

0 2 ab 2
2 0 abab 4
0 3 b 1
1 1 bab 3
for each len 1 to n:
    find the number of suffixes can be there 
    suppose its tot
    number of lcp greater or eq to len
*/
/*
4 - 2 = 2
3 - 1 = 2
2 - 0 = 2
1 - 0 = 1
*/