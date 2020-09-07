#include <bits/stdc++.h>
using namespace std;

vector <pair <int , int>> v;
map <int , int> mp;
int BinarySearch(int low , int high , int x) {
    while (low < high) {
        int mid = (high + low) / 2;
        if (x == v[mid].first) {
            high = mid;
        } else if (x < v[mid].first) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n , x; cin >> n >> x;
    for (int i = 0; i < n ; i++) {
        int k; cin >> k;
        mp[k]++;
        v.emplace_back(k , i);
    }

    sort(v.begin() , v.end());
    
    pair <int , int> ans = make_pair(-1 , -1);
    
    for (int i = 0; i < n ; i++) {
        int one = v[i].first;
        if (one >= x) continue;
        int two = x - v[i].first;
        //cout << one << " " << two << "\n";
        if (one == two) {
            if (mp[one] <= 1) {
                continue;
            } else {
                int cur = BinarySearch(0 , n - 1 , two);
                ans.first = v[cur].second;
                ans.second = v[cur + 1].second;
                break;
            }
        } else {
            int cur = BinarySearch(0 , n - 1 , two);
            //cout << cur << "\n";
            if (two == v[cur].first) {
                ans.first = v[i].second;
                ans.second = v[cur].second;
                break;
            }
        }
    }
    if (ans.first == -1 || ans.second == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans.first + 1 << " " << ans.second + 1 << "\n";
    }
    return 0;
}