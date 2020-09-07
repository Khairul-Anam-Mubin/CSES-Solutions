#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long y , x; cin >> y >> x;
        long long mx = max(x , y);
        if (mx == x) {
            if (x & 1) {
                y--;
                cout << (x * x) - y << "\n";
            } else {
                x--;
                cout << (x * x) + y << "\n";
            }
        } else {
            if (y & 1) {
                y--;
                cout << (y * y) + x << "\n";
            } else {
                x--;
                cout << (y * y) - x << "\n";
            }
        }
    }    
    return 0;
}