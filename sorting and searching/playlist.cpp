#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ar[n + 1];
    for (int i = 1; i <= n; i++) cin >> ar[i];
    map <int , int> mp;
    int l = 1;
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
        if (mp[ar[i]] == 0) {
            ans = max(ans , i - l + 1);
            mp[ar[i]] = i;
        } else {
            int cur = l;
            l = mp[ar[i]] + 1;
            for (int j = cur; j <= mp[ar[i]]; j++) {
                mp[ar[j]] = 0;
            }
            mp[ar[i]] = i;
        }
    }
    cout << ans << "\n";
    return 0;
}