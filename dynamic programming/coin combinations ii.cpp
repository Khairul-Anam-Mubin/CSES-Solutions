#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x; cin >> n >> x;
    int coin[n + 2];
    for (int i = 1; i <= n; i++) cin >> coin[i];
    int dp[x + 5];
    memset(dp , 0 , sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - coin[i] >= 0) {
                dp[j] += dp[j - coin[i]];
                dp[j] %= mod;
            } 
        }
    }
    cout << dp[x] << "\n";
    return 0;
}