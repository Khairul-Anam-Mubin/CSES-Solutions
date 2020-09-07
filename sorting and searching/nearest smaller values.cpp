#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    int ar[n + 5];
    for (int i = 1; i <= n; i++) cin >> ar[i];
    int save[n + 5];
    for (int i = 1; i <= n; i++) save[i] = i - 1;
    save[0] = 0;
    ar[0] = -1;
    for (int i = 1; i <= n; i++) {
        int j = save[i];
        while (ar[i] <= ar[j]) j = save[j];
        save[i] = j;
    }    
    for (int i = 1; i <= n; i++) cout << save[i] << " ";
    return 0;
}