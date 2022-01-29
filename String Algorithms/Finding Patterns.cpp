#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s; cin >> s;
    s = s + "$";
    int n = s.size();
    
    vector <int> sufar(n) , eqclass(n);
    vector <pair<char, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = {s[i], i};
    }
    sort(a.begin() , a.end());
    for (int i = 0; i < n; i++) {
        sufar[i] = a[i].second;
    }
    eqclass[sufar[0]] = 0;
    for (int i = 1; i < n; i++) {
        eqclass[sufar[i]] = eqclass[sufar[i - 1]];
        if (a[i].first != a[i - 1].first) {
            eqclass[sufar[i]]++;
        }
    }
    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) {
            sufar[i] = (sufar[i] - (1 << k) + n) % n;
        }
        vector <int> cnt(n , 0);
        for (int i = 0; i < n; i++) {
            cnt[eqclass[i]]++;
        }
        vector <int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        vector <int> sufar_new(n);
        for (int i = 0; i < n; i++) {
            int x = eqclass[sufar[i]];
            sufar_new[pos[x]] = sufar[i];
            pos[x]++;
        }
        sufar = sufar_new;
        vector <int> eqclass_new(n);
        eqclass_new[sufar[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair <int , int> prev = {eqclass[sufar[i - 1]], eqclass[(sufar[i - 1] + (1 << k)) % n]};
            pair <int , int> cur = {eqclass[sufar[i]], eqclass[(sufar[i] + (1 << k)) % n]};
            if (prev != cur) eqclass_new[sufar[i]] = eqclass_new[sufar[i - 1]] + 1;
            else eqclass_new[sufar[i]] = eqclass_new[sufar[i - 1]];
        }
        eqclass = eqclass_new;
    }
    
    int q; cin >> q;
    while (q--) {
        string p; cin >> p;
        int lo = 0 , hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (s.substr(sufar[mid], min((int)p.size(), n - sufar[mid])) <= p) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (s.substr(sufar[lo - 1], min((int)p.size(), n - sufar[lo - 1])) == p) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}