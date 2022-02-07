#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar, ar + n);
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (ar[i] > ans) {
            break;
        }
        ans += ar[i];
    }
    cout << ans << "\n";
    return 0;
}