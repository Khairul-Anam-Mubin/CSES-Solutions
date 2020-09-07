#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long ar[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    long long ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (ar[i] > ar[i + 1]) {
            ans += (ar[i] - ar[i + 1]);
            ar[i + 1] = ar[i];
        }
    }
    cout << ans << "\n";
    return 0;
}