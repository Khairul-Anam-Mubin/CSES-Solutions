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
    vector <pair <int , int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = {s[i] , i};
    }
    sort(a.begin() , a.end());
    for (int i = 0; i < n; i++) {
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        c[p[i]] = c[p[i - 1]];
        if (a[i].first != a[i - 1].first) {
            c[p[i]]++;
        }
    }
    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        vector <int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            cnt[c[i]]++;
        }
        vector <int> pos(n) , p_new(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int x = c[p[i]];
            p_new[pos[x]] = p[i];
            pos[x]++;
        }
        p = p_new;
        vector <int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair <int , int> prev = {c[p[i - 1]] , c[(p[i - 1] + (1 << k)) % n]};
            pair <int , int> cur = {c[p[i]] , c[(p[i] + (1 << k)) % n]};
            c_new[p[i]] = c_new[p[i - 1]];
            if (prev != cur) {
                c_new[p[i]]++;
            }
        }
        c = c_new;
    }

    int q; cin >> q;
    while (q--) {
        string ptr; cin >> ptr;
        int plen = ptr.size();

        int lowerbound = 0;
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (s.substr(p[mid], min(plen, n - p[mid])) >= ptr) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        lowerbound = lo;
        int upperbound = n;
        lo = 0 , hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (s.substr(p[mid], min(plen , n - p[mid])) <= ptr) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        upperbound = lo;
        //cout << upperbound << " " << lowerbound << "\n";
        int ans = upperbound - lowerbound;
        cout << ans << "\n";
    }
    return 0;
}