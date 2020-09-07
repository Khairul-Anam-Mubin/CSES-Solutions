#include <bits/stdc++.h>
using namespace std;

bool col[16] , diag1[16], diag2[16] , res[16][16];
int ans = 0;
void Ways(int r) {
    if (r == 8) {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (col[c] || diag1[r + c] || diag2[r - c + 7] || res[r][c]) 
            continue;
        col[c] = diag1[r + c] = diag2[r - c + 7] = true;
        Ways(r + 1);
        col[c] = diag1[r + c] = diag2[r - c + 7] = false;
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        string s; cin >> s;
        for (int j = 0; j < 8; j++) {
            res[i][j] = s[j] == '*';
        }
    }
    Ways(0);
    cout << ans << "\n";
    return 0;
}