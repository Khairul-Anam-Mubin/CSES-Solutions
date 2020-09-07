#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    long long n , t; 
    cin >> n >> t;
    long long ar[n + 2];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    long long low = 1 , high = 1e18;
    long long res = high;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += min(mid / ar[i] , (long long)1e9);
        }
        if (cur >= t) {
            res = min(res , mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << res << "\n";
    return 0;
}