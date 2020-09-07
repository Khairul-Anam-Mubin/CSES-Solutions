#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ar[n + 1];
    memset(ar , 0 , sizeof(ar));
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        ar[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (ar[i] == 0) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}