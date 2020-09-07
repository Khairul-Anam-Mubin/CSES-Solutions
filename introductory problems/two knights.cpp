#include <bits/stdc++.h>
using namespace std;

long long Ways(long long n) {
    long long res = ((n * n) * ((n * n) - 1)) - 8 - 24 - ((n - 4) * 16) - 16 - ((n - 4) * 24) - ((n - 4) * (n - 4) * 8);
    return res / 2;
}

int main() {
    long long n; cin >> n;
    for (long long i = 1; i <= n; i++) {
        long long ans = Ways(i);
        cout << ans << "\n";
    }
    return 0;
}