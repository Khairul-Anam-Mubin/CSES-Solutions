#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    long long n , x; cin >> n >> x;
    long long ar[n + 1];
    for (int i = 0 ; i < n; i++) 
        cin >> ar[i];
    long long sum = 0, pre = 0 , ans = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[i];
        if (sum < x) continue;
        if (sum == x) {
            //cout << pre << " " << i << "\n";
            ans++;
            sum -= ar[pre];
            pre++;
            continue;
        }
        while (sum > x) {
            sum -= ar[pre];
            pre++;
        }
        if (sum == x) ans++;
    }
    cout << ans << "\n";
    return 0; 
}