#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int ar[mxN + 5];

pair <int , int> seg[mxN << 2];
pair <int , int> Merge(pair <int,int> left , pair<int , int> right) {
    if (left.first >= right.first) return left;
    return right;
}
void Build(int cur, int left , int right) {
    if (left == right) {
        seg[cur] = make_pair(ar[left] , left);
        return;
    }
    int mid = (left + right) >> 1;
    Build(cur << 1 , left , mid);
    Build(cur << 1 | 1, mid + 1, right);
    seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
}
pair <int , int> Query(int cur, int left , int right, int l, int r) {
    if (right < l || r < left) return make_pair(-1 , -1);
    if (left >= l && right <= r) return seg[cur];
    int mid = (left + right) >> 1;
    return Merge(Query(cur << 1 , left , mid , l , r) , Query(cur << 1 | 1, mid + 1, right ,l, r));
}
void Update(int cur , int left , int right, int pos, int val) {
    if (right < pos || pos < left) return;
    if (left >= pos && right <= pos) {
        seg[cur] = make_pair(val , pos);
        return;
    } 
    int mid = (left + right) >> 1;
    Update(cur << 1, left , mid , pos , val);
    Update(cur << 1 | 1, mid + 1, right , pos , val);
    seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
}
int Query(int x, int n) {
    int low = 1, high = n;
    pair <int, int> ok;
    
    pair <int , int> ans = {-1 , -1};
    
    while (low <= high) {
        int mid = (low + high) >> 1;
        ok = Query(1 ,1 , n , low , mid);
        if (ok.first >= x) {
            ans = ok;
            high = mid - 1;
            //cout << ans.first << " " << ans.second << "\n";            
        } else {
            ok = Query(1 , 1, n , mid , high);
            if (ok.first >= x) {
                ans = ok;
                low = mid + 1;
            } else {
                break;
            }
        }
    }
    if (ans.second == -1) return 0;
    Update(1, 1 , n, ans.second, ans.first - x);
    return ans.second;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    Build(1 , 1 , n);
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        cout << Query(x , n) << " ";
    }
    return 0;
}