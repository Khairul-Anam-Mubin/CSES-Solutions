#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
    } else {
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
    }
    return 0;
}
// 1
// 1

// 2
// 2 , 1

// 3
// 2 , 1 , 3

// 4
// 2 , 4, 1 , 3

// 5
// 2 , 4 , 1 , 5 , 3 , 

// 5
// 2 , 4 , 1 , 3 , 5

// 6
// 2 , 4 , 6 , 1 , 3 , 5

// 7
// 2 , 4 , 6 , 1 , 3 , 5 , 7

// 8
// 2 , 4 , 6 , 8 , 1 , 3 , 5 , 7