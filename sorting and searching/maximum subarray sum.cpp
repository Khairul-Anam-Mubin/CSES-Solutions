#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long ar[n + 1];
    for (int i = 0; i < n; i++) cin >> ar[i];
    long long ans = ar[0] , sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[i];
        ans = max(ans , sum);
        if (sum < 0) sum = 0;
    }
    cout << ans << "\n";
    return 0;
}