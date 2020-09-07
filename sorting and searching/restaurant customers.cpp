#include <bits/stdc++.h>
using namespace std;

bool cmp(pair <int , int> a, pair <int , int> b) {
    if (a.first != b.first) 
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector <pair <int , int>> v;
    while (n--) {
        int a , b; cin >> a >> b;
        v.emplace_back(a , 1);
        v.emplace_back(b , -1);
    }
    sort(v.begin() , v.end(), cmp);
    int ans = 0 , cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        cnt += v[i].second;
        ans = max(ans , cnt);
    }
    cout << ans << "\n";
    return 0;
}