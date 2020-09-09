#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
int dp[mxN + 5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= 9; i++) dp[i] = 1;
    for (int i = 10; i <= n; i++) {
        dp[i] = 1e9;
        int x = i;
        while (x) {
            int r = x % 10;
            if (r) {
                dp[i] = min(dp[i - r] + 1 , dp[i]);
            }
            x /= 10;
        }
    }
    cout << dp[n] << '\n';
    return 0;   
}