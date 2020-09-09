#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x; cin >> n >> x;

    int price[n + 2] , pages[n + 2];
    for (int i = 1; i <= n; i++) cin >> price[i];
    for (int i = 1; i <= n; i++) cin >> pages[i];
    int dp[n + 2][x + 2];   
    memset(dp , 0 , sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            if (j >= price[i]) {
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - price[i]] + pages[i]);
            }
        }
    }
    cout << dp[n][x] << '\n';
    return 0;
}