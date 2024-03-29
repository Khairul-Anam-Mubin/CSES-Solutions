#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s; cin >> s;
    int n = s.size();
    vector <int> z(n);
    z[0] = 0;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i , r = i + z[i] - 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << z[i] << " ";
    }
    cout << "\n";
    vector <int> pi(n);
    pi[0] = 0;
    for (int i = 1, j = 0; i < n && j < n; ) {
        if (s[i] == s[j]) {
            pi[i++] = ++j;
        } else if (j != 0) {
            j = pi[j - 1];
        } else {
            pi[i++] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << pi[i] << " ";
    }
    cout << "\n";
    return 0;
}