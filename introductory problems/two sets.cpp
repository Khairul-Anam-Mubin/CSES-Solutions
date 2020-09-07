#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long sum = (n * (n + 1)) / 2;
    if (sum & 1) {
        cout << "NO\n";
    } else {
        int taken[n + 1];
        memset(taken , 0 , sizeof(taken));
        sum /= 2;
        int cnt = 0;
        for (int i = n; i >= 1; i--) {
            if (sum >= i) {
                sum -= i;
                taken[i] = 1;
                cnt++;
            }
            if (sum == 0) break;
        }
        if (sum != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << cnt << "\n";
            for (int i = 1; i <= n; i++) {
                if (taken[i]) cout << i << " ";
            }
            cout << "\n";
            cout << n - cnt << "\n";
            for (int i = 1; i <= n; i++) {
                if (!taken[i]) cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}