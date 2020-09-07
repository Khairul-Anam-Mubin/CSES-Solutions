#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);

    int x , n; cin >> x >> n ;
    set <int> st;
    st.insert(0);
    st.insert(x);
    map <int , int> mp;
    mp[x] = 1;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        auto it = st.lower_bound(a);
        int r = *it;
        it--;
        int l = *it;
        mp[r - l]--;
        if (mp[r - l] == 0) {
            mp.erase(r - l);
        }
        st.insert(a);
        mp[a - l]++;
        mp[r - a]++;
        cout << ((--mp.end())->first) << " ";
    }

    return 0;
}