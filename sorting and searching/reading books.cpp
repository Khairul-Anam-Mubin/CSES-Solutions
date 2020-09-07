#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);

    int n ; cin >> n;
    int ar[n + 1];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }
    sort(ar , ar + n);
    cout << max(ar[n - 1] * 2LL , sum) << "\n";
    return 0;
}