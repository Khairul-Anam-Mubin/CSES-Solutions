#include <bits/stdc++.h>
using namespace std;

long long dv[1000010];

int main() {
    for (int i = 1; i <= 1000000 ; i++) {
        for (int j = i; j <= 1000000; j += i) {
            dv[j]++;
        }
    }
    int n; cin >> n;
    while (n--) {
        int k ; cin >> k; 
        cout << dv[k] << "\n";
    }
    return 0;
}