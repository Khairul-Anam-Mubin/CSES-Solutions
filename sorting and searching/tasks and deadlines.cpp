#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    array <int , 2> ar[n + 1];
    for (int i = 0; i < n; i++) 
        cin >> ar[i][0] >> ar[i][1];
    sort(ar , ar + n);
    long long ans = 0 , t = 0;
    for (int i = 0; i < n; i++) {
        t += ar[i][0];
        ans += ar[i][1] - t;
    }
    cout << ans << "\n";
    return 0;
}