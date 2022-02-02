#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s; cin >> s;
    s += "$";
    int n = s.size();

    vector <int> p(n), c(n), lcp(n);
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
        for (int i = 0; i < n; i++) {
            cnt[c[i]]++;
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
    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        int pi = c[i];
        int j = p[pi - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[pi] = k;
        k = max(0 , k - 1);
    }
    /*
    for (int i = 0; i < n; i++) {
        cout << lcp[i] << " " << p[i] << " " << s.substr(p[i], n - p[i]) << " " << c[p[i]] << "\n";
    }
    */
    int maxRepeatSubString = 0, id = 0;
    for (int i = 0; i < n; i++) {
        if (maxRepeatSubString < lcp[i]) {
            maxRepeatSubString = lcp[i];
            id = p[i];
        }
    }
    if (maxRepeatSubString == 0) {
        cout << "-1\n";
    } else {
        cout << s.substr(id , maxRepeatSubString) << "\n";
    }
    return 0;
}