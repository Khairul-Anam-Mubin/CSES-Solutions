#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    long long x; cin >> x;
    vector <pair <long long , int>> vec;
    for (int i = 0; i < n; i++) {
        int var; cin >> var;
        vec.emplace_back(var , i);
    }
    sort(vec.begin() , vec.end());
    vector <pair <long long , pair <int , int>>> v;
    map <long long , int> freq;
    map <long long , vector <int> > mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vec[i].first + vec[j].first < x) {
                freq[vec[i].first + vec[j].first]++;
                v.emplace_back(make_pair(vec[i].first + vec[j].first , make_pair(i , j)));
                mp[vec[i].first + vec[j].first].emplace_back(v.size() - 1);
            }
        }
    }
    bool flag = 0;
    for (auto it : v) {
        long long last = x - it.first;
        if (freq.find(last) == freq.end()) continue;
        for (int iit : mp[last]) {
            set <int> st;
            st.insert(it.second.first);
            st.insert(it.second.second);
            st.insert(v[iit].second.first);
            st.insert(v[iit].second.second);
            if (st.size() == 4) {
                for (int k : st) {
                    cout << vec[k].second + 1 << " ";
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}