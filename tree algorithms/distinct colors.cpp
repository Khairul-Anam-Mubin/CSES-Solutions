#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

// Mo's contents
const int block = 555;
int freq[mxN + 5];
int ans[mxN + 5];
int tot = 0;

// Compress contents
int col[mxN + 5], id = 1;
vector <int> all , v , vec;

// tree contents
vector <int> g[mxN + 4];
vector <int> tin(mxN + 5) , sub(mxN + 5) , flat(mxN + 5);
int cnt = 1;

// Compressing and mapping
int mapp(int x) {
    int idx = lower_bound(v.begin() , v.end(), x) - v.begin();
    return vec[idx];
}
void Compress(int n) {
    for (int i = 1; i <= n; i++) all.emplace_back(col[i]);
    sort(all.begin(),all.end());
    for (int i = 0; i < (int)all.size(); id++) {
        int x = all[i];
        while (i < (int)all.size() && x == all[i]) i++;
        v.emplace_back(x);
        vec.emplace_back(id);
    }
}

// calculating intime and subtree size
void Dfs(int u, int par = -1) {
    sub[u] = 1;
    tin[u] = cnt;
    flat[cnt] = u;
    cnt++;
    for (int v: g[u]) {
        if (par == v) continue;
        Dfs(v , u);
        sub[u] += sub[v];
    }
}

// query containers
struct node {
    int l, r, idx;
} q[mxN + 5];

// Mo's query sorting methods
bool Cmp(node &a, node &b) {
    if (a.l / block != b.l / block) return a.l / block < b.l / block;
    return a.r < b.r;
}
void Add(int pos) {
    freq[col[flat[pos]]]++;
    if (freq[col[flat[pos]]] == 1) tot++;
}
void Remove(int pos) {
    freq[col[flat[pos]]]--;
    if (freq[col[flat[pos]]] == 0) tot--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> col[i];
    Compress(n);
    for (int i = 1; i <= n; i++) col[i] = mapp(col[i]);
    //for (int i = 1; i <= n; i++) cout << col[i] << "\n";
    for (int i = 1; i <= n - 1; i++) {
        int u , v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    Dfs(1);
    for (int i = 1; i <= n; i++) {
        q[i - 1].l = tin[i];
        q[i - 1].r = tin[i] + sub[i] - 1;
        q[i - 1].idx = i;
    }
    sort(q , q + n, Cmp);
    int ML = 1 , MR = 0;
    for (int i = 0; i < n; i++) {
        int L = q[i].l;
        int R = q[i].r;
        while (ML > L) Add(--ML);
        while (MR < R) Add(++MR);
        while (ML < L) Remove(ML++);
        while (MR > R) Remove(MR--);
        ans[q[i].idx] = tot;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}