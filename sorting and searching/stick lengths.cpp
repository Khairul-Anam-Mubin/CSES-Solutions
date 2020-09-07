#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long ar[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar , ar + n);
    long long mid = ar[n / 2];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(mid - ar[i]);
    }
    cout << ans << "\n";
    return 0;
}