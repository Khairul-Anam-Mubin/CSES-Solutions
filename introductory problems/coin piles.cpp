#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        long long a, b; cin >> a >> b;
        if ((a + b) % 3 == 0 && a * 2 >= b && b * 2 >= a) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } 
    return 0;
}