#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    s += "$";
    int n = s.size();

    vector <int> p(n), c(n);
    vector <int> cnt(256 , 0), pos(256);
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
        if (s[p[i - 1]] != s[p[i]]) {
            c[p[i]]++;
        }
    }
    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        cnt.assign(n , 0);
        for (int x : c) {
            cnt[x]++;
        }
        pos.resize(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        vector <int> p_new(n);
        for (int x : p) {
            int i = c[x];
            p_new[pos[i]] = x;
            pos[i]++;
        }
        p = p_new;
        vector <int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair <int , int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]}; 
            pair <int , int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            c_new[p[i]] = c_new[p[i - 1]];
            if (prev != cur) {
                c_new[p[i]]++;
            }
        }
        c = c_new;
    }
    
    int sptab[20][n + 1];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            sptab[i][j] = 1e9;
        }
    }
    for (int i = 0; i < n; i++) sptab[0][i] = p[i];
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j + (1 << (i - 1)) < n; j++) {
            sptab[i][j] = min(sptab[i - 1][j] , sptab[i - 1][j + (1 << (i - 1))]);
        }
    } 
    int q; cin >> q;
    while (q--) {
        string ptr; cin >> ptr;
        int plen = ptr.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (s.substr(p[mid], min(plen, n - p[mid])) >= ptr) {
                hi = mid - 1; 
            } else {
                lo = mid + 1;
            }
        }
        if (s.substr(p[lo], min(plen, n - p[lo])) != ptr) {
            cout << "-1\n";
            continue;
        }
        int left = lo;
        lo = 0 , hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (s.substr(p[mid], min(plen, n - p[mid])) <= ptr) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        int right = lo - 1;
        int mxBit = log2(right - left + 1);
        int rmq = min(sptab[mxBit][left], sptab[mxBit][right - (1 << mxBit) + 1]);
        cout << rmq + 1 << "\n";
    }
    return 0;
}