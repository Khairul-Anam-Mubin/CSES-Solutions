#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int up = upper_bound(v.begin() , v.end() , x) - v.begin();
        //cout << up << "\n";
        if (up < v.size()) {
            v[up] = x;
        } else {
            v.emplace_back(x);
        }
    }
    cout << v.size() << "\n";
    return 0;
}