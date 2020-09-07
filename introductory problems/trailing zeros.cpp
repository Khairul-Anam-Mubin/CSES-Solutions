#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long ans = 0;
    long long ok = 5;
    while (n / ok) {
        ans += n / ok;
        ok *= 5;
    }
    cout << ans << "\n";
    return 0;
}