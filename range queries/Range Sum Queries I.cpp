#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n , q; cin >> n >> q;
    long long ar[n + 1];
    for (int i = 1; i <= n; i++) cin >> ar[i];
    long long dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + ar[i];
    }
    while (q--) {
        int l , r ; cin >> l >> r;
        cout << dp[r] - dp[l - 1] << "\n";
    }
    return 0;
}