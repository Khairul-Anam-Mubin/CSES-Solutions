#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n, x; cin >> n >> x;
    int c[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int dp[n + 2][x + 2];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) dp[i][j] = 1e9;
    }
    for (int i = 0; i <= n; i++) dp[i][0] = 0;  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (c[i] <= j) {
                dp[i][j] = min(dp[i - 1][j] , 1 + dp[i][j - c[i]]);
            } else {
                dp[i][j] = min(dp[i][j] , dp[i - 1][j]);
            }
        }
    }
    if (dp[n][x] == 1e9) dp[n][x] = -1;
    cout << dp[n][x] << "\n";
    return 0;
}