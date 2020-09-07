#include <bits/stdc++.h>
using namespace std;
 
int UpperBound(long long ar[],int low , int high , long long x) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x >= ar[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        } 
    }
    return low;
}   
int main() {
    int n, m; cin >> n >> m;
    long long h[n + 1] , t[m + 1];
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int j = 0; j < m; j++) cin >> t[j];
    sort(h , h + n);
    bool mark[n + 1];
    memset(mark , 0 , sizeof(mark));
    int sq = sqrt(n) + 1;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int id = UpperBound(h , 0 , n - 1, t[i]);
        //cout << id << " : upper \n";
        id = min(n - 1 , id);
        long long x = -1;
        for (int j = id; j >= 0; j--) {
            if (!mark[j] && h[j] <= t[i]) {
                mark[j] = 1;
                x = h[j];
                cnt++;
                break;
            }
        }
        if (cnt == sq) {
            cnt = 0;
            long long here[n + 1];
            int sz = 0;
            for (int j = 0; j < n; j++) {
                if (mark[j] == 0) {
                    here[sz] = h[j];
                    sz++;
                } 
            }
            memset(mark , 0 , sizeof(mark));
            for (int j = 0; j < sz; j++) {
                h[j] = here[j];
            }
            n = sz;
        }
        cout << x << "\n";
    }
    return 0;
}