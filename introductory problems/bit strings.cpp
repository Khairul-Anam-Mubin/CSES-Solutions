#include <bits/stdc++.h>
using namespace std;

long long BigMod(long long base , long long po, long long mod = 1000000007) {
    if (po == 0) return 1;
    if (po % 2 == 0) {
        long long rem = BigMod(base , po / 2 , mod);
        return ((rem % mod) * (rem % mod) % mod);
    }
    return (((base % mod) * BigMod(base , po - 1, mod)) % mod);
}
int main() {
    long long n; cin >> n;
    long long ans = BigMod(2LL , n);
    cout << ans << "\n";
    return 0;
}