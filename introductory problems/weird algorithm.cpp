#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    long long n; cin >> n;
    while (n > 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n *= 3;
            n++;
        }
    }	
    cout << "1\n";
	return 0;
}