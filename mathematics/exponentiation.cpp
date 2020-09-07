#include <bits/stdc++.h>
using namespace std;

long long BigMod(long long base , long long po , long long m) {
    if (po == 0) return 1;
    if (po % 2 == 0) {
        long long r = BigMod(base , po / 2 , m);
        return ((r % m) * (r % m)) % m;
    } else {
        return ((base % m) * (BigMod(base , po - 1 , m) % m)) % m;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    while (n--) {
        long long a , b;
        cin >> a >> b;
        long long m = 1e9 + 7;
        cout << BigMod(a , b , m) << "\n";
    }
    return 0;
}