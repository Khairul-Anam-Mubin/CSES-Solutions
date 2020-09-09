#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int val[n + 2];
    for (int i = 1; i <= n; i++) cin >> val[i];
    int tot = 0;
    for (int i = 1; i <= n; i++) tot += val[i];
    sort(val + 1, val + n + 1);    
    bool dp[tot + 2][n + 2];
    memset(dp , 0 , sizeof(dp));
    for (int i = 1; i <= tot; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] |= dp[i][j - 1];
            if (i == val[j]) dp[i][j] = 1;
            else if (!dp[i][j] && i >= val[j]) {
                dp[i][j] |= dp[i - val[j]][j - 1];
            }
        }
    } 
    for (int i = 1; i <= tot; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] |= dp[i][j - 1];
        }
    }
    vector <int> ans;
    for (int i = 1; i <= tot; i++) {
        if (dp[i][n]) ans.emplace_back(i);
    }
    cout << ans.size() << '\n';
    for (int x : ans ) cout << x << " ";
    return 0;
}