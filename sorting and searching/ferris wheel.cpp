#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long x; cin >> x;
    long long p[n + 1];
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p , p + n);
    int ans = 0;
    int l = 0 , r = n - 1;
    for (int i = l; i < r; r--) {
        if (x - p[i] >= p[r]) {
            ans++;
            i++;
        }
    }
    long long now = n - (ans * 2);
    ans += now;
    cout << ans << "\n";
    return 0;
}