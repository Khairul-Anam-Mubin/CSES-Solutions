#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , m , k; cin >> n >> m >> k;
    long long ar[n + 1] , br[m + 1];
    for (int i = 0; i < n; i++) cin >> ar[i];
    for (int i = 0; i < m; i++) cin >> br[i];
    sort(ar , ar + n);
    sort(br , br + m);
    int cnt = 0;
    for (int i = 0 , j = 0; i < n && j < m; i++) {
        if (ar[i] - k <= br[j] && br[j] <= ar[i] + k) {
            j++;
            cnt++;
        } else {
            if (ar[i] - k > br[j]) {
                j++;
                i--;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}