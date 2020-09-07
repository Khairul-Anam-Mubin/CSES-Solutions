#include <bits/stdc++.h>
using namespace std;

array <int , 3> v[200010];
int main() {
    int n; cin >> n;    
    for (int i = 0; i < n; i++) {
        int a , b; cin >> a >> b;
        v[i][1] = a;
        v[i][0] = b;
        v[i][2] = i;
    }
    sort(v , v + n);
    set <array<int , 2>> st;
    int ans[n + 1];
    for (int i = 0;i < n; i++) {
        auto it = st.lower_bound({v[i][1]});
        if (it != st.begin()) {
            it--;
            ans[v[i][2]] = (*it)[1];
            st.erase(it);
        } else {
            ans[v[i][2]] = st.size();
        }
        st.insert({v[i][0] , ans[v[i][2]]});
    }
    cout << st.size() << '\n';
    for (int  i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}