#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector <pair <int , int>> v;
    while (n--) {
        int a , b; cin >> a >> b;
        v.emplace_back(b , a);
    }
    sort(v.begin() , v.end());
    int ans = 0 , ok = 0;
    for (auto i : v) {
        if (i.second >= ok) {
            ok = i.first;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}