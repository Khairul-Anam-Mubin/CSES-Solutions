#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int mp[26];
    memset(mp , 0 , sizeof(mp));
    int len = s.size();
    for (int i = 0; i < len; i++) {
        char ch = s[i] - 'A';
        mp[ch]++;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (mp[i] % 2 == 1) cnt++;
    }
    if (cnt > 1) {
        cout << "NO SOLUTION\n";
    } else {
        s.clear();
        int have = -1;
        for (int i = 0; i < 26; i++) {
            int ok = mp[i] / 2;
            while (ok) {
                s.push_back(char(i + 'A'));
                ok--;
            }
            if (mp[i] % 2 == 1) have = i;
        }
        if (have != -1) s.push_back(char(have + 'A'));
        for (int i = 25; i >= 0; i--) {
            int ok = mp[i] / 2;
            while (ok) {
                s.push_back(char(i + 'A'));
                ok--;
            }
        }
        cout << s << "\n";
    }
    return 0;
}