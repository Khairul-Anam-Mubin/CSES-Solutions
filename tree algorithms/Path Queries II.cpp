/***
**      Bismillahir Rahmanir Rahim                
**              ALLAHU AKBAR
**
**     Author: Khairul Anam Mubin (__Broly__)
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <bits/stdc++.h>
using namespace std;
 
#define F            first
#define S            second  
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Test         int test;cin >> test;for(int tc = 1; tc <= test; tc++)
 
#define INF9         2147483647
#define INF18        9223372036854775806
#define eps          1e-8 
 
const double pi = 2 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template <typename T> T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
template <typename T> T Exgcd(T a,T b,T &x,T &y) {if(a<0){T d=Exgcd(-a,b,x,y);x=-x;return d;}   if(b<0){T d=Exgcd(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=Exgcd(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInvPrime (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T ModInvNotPrime(T a , T m) {T x , y ;Exgcd(a , m , x , y) ;x %= m ;if(x < 0) x += m ;return x ;}
template <typename T> typename std::vector<T>::iterator Insert_sorted (std :: vector<T> & vec, T const& item) {return vec.insert (std::upper_bound( vec.begin(), vec.end(), item ), item);}
template <typename T> inline string ToBinary(T n) {string r ;while(n != 0) {r = ( n % 2 == 0 ? "0" : "1" ) + r ; n >>= 1;} return r ;} 
long long BinaryToDecimal(string s) {int len = s.size();long long n = 0, p = 1;for (int i = len - 1; i >= 0; i-- , p *= 2) n += p * (s[i] - '0');return n;}
 
char Uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char Lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool Isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
int Strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
string Intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> Linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.push_back(s);return v;}
template <typename T> void Print(T ar[] , int a , int b) {for (int i = a; i + 1 <= b ; i++)cout << ar[i] << " ";cout << ar[b] << "\n";}
template <typename T> void Print(T ar[] , int n) {for (int i = 0; i + 1 < n; i++)cout << ar[i] << " ";cout << ar[n - 1] << "\n";} 
template <typename T> void Print(const vector<T> &v) {for (int i = 0; i + 1 < v.size() ; i++) cout << v[i] << " ";cout << v.back() << "\n";}
 
//int dx[] = {0 , 0 , -1 , 1 , -1 , -1 , 1 , 1 , 0} ;  // right , left , up , down
//int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 , -1 , 1 , 0} ;

template <typename T> struct SegmentTree {
    vector <T> seg;
    vector <T> lazy;
    vector <T> ar;
    int type , up;
    SegmentTree() {
        type = 0;
        up = 0;
    }
    SegmentTree(int tp , int u) {
        type = tp;
        up = u;
    }
    void Init(int N) {
        seg.assign(N << 2, 0);
        lazy.assign(N << 2 , 0);
    }
    void Init(vector <T> &s) {
        Init(s.size() + 1);
        ar = s;
    }
    void PushDown(int cur , int left , int right) {
        if (type == 0) {
            if (up == 1) seg[cur] += (right - left + 1) * lazy[cur];
            else seg[cur] = (right - left + 1) * lazy[cur];
        } else {
            if (up == 1) seg[cur] += lazy[cur];
            else seg[cur] = lazy[cur];
        }
        if (left != right) {
            if (up == 1) {        
                lazy[cur << 1] += lazy[cur];  
                lazy[cur << 1 | 1] += lazy[cur];
            } else {
                lazy[cur << 1] = lazy[cur];  
                lazy[cur << 1 | 1] = lazy[cur];
            }
        }
        lazy[cur] = 0;
    }
    T Merge(T x , T y) {
        if (type == 0) return x + y;
        if (type == 1) return max(x , y);
        if (type == 2) return min(x , y);
        return 0;
    }
    void Build(int cur , int left , int right) {
        //lazy[cur] = 0;
        if (left == right) {
            seg[cur] = ar[left];
            return;
        }
        int mid = (left + right) >> 1;
        Build(cur << 1 , left , mid);
        Build(cur << 1 | 1 , mid + 1 , right);
        //seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
        seg[cur] = max(seg[cur << 1] , seg[cur << 1 | 1]);
    }
    void Update(int cur , int left , int right , int pos , T val) {
        Update(cur , left , right , pos , pos , val);
    }
    void Update(int cur , int left , int right , int l , int r , T val) {
        //if (lazy[cur] != 0) PushDown(cur , left , right);         
        if (l > right || r < left) return;
        if (left >= l && right <= r) {
            //if (up == 0) lazy[cur] = val;
            //else lazy[cur] += val;
            //PushDown(cur , left , right);
            seg[cur] = val;
            return ;
        }
        int mid = (left + right) >> 1;
        Update(cur << 1 , left , mid , l , r , val);
        Update(cur << 1 | 1 , mid + 1 , right , l , r , val);
        //seg[cur] = Merge(seg[cur << 1] , seg[cur << 1 | 1]);
        seg[cur] = max(seg[cur << 1] , seg[cur << 1 | 1]);
    }
    T Query(int cur , int left , int right , int l , int r) {
        if (l > right || r < left) {
            //if (type == 0) return 0;
            //if (type == 1) return -INF18;
            //if (type == 2) return INF18;
            return -INF18;
        }
        //if (lazy[cur] != 0) PushDown(cur , left , right);
        if (left >= l && right <= r) return seg[cur];
        int mid = (left + right) >> 1;
        T p1 = Query(cur << 1 , left , mid , l , r);
        T p2 = Query(cur << 1 | 1 , mid + 1 , right , l , r);
        //return Merge(p1 , p2);
        return max(p1 , p2);
    }
};
//for sum = 0, max = 1, min = 2, for assignment update send 0 or 1 for increment.
SegmentTree <long long> T(1 , 0);


/**************************HeavyLightDecomposition***********************/
/*  1.  All nodes are number from 0 to n - 1  */ 
/*  2.  Assign the graph by Init(graph) or simply Init(total nodes) and 
        call AddEdge(u , v) for all the edges */
/*  3.  Must be Take the node value from input directly or use the 
        TakeNodeVal(nodeval) to assigning the node value */
/*  4.  Call Build() to construct hld and segment tree */
/*  5.  simply use the path query by query(u , v) and update(pos , val) */

struct HeavyLightDecompose {
    vector <vector <int> > g ; // graph
    vector <long long> node_val;
    int N , root = 0;
    vector <int> depth , parent , sub;
    // HLD staffs
    int chain_no, indx;
    vector <int> chain_head , chain_ind;
    vector <int> node_serial , serial_node;
    vector <long long> segarr; // tree on linear format
    void Init(int n) {
        N = n;
        g.assign(N , {});
        node_val.clear();
        segarr.resize(N);
        depth.resize(N);
        parent.resize(N);
        sub.resize(N);
        chain_head.assign(N, -1);
        chain_ind.resize(N);
        node_serial.resize(N);
        serial_node.resize(N);
        return;
    }
    void Init(const vector <vector<int>> &_g) {
        Init(_g.size());
        g = _g;
        return;
    }
    void AddEdge(int u , int v) {
        g[u].push_back(v) ;
        g[v].push_back(u) ;
        return;
    }
    void TakeNodeVal(const vector <long long> &_node_val) {
        node_val = _node_val;
    }
    void Build() {
        Dfs(root);
        chain_no = 0, indx = 0;
        HLD(0);
        T.Init(segarr);
        T.Build(1 , 0 , N - 1);
    }
    void Dfs(int u, int par = -1) {
        sub[u] = 1;
        if (par == -1) {
            depth[u] = 0;
            parent[u] = -1;
        }
        for (int v : g[u]) {
            if (v == par) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            Dfs(v , u);
            sub[u] += sub[v];
            
        }
        return;
    }
    void HLD(int u , int par = -1) {
        if (chain_head[chain_no] == -1) chain_head[chain_no] = u;
        chain_ind[u] = chain_no;
        node_serial[u] = indx;
        serial_node[indx] = u;
        segarr[indx] = node_val[u]; // tree flatting..
        indx++;
        int heavychild = -1 , heavysize = 0;
        for (int v : g[u]) {
            if (v == par) continue;
            if (sub[v] > heavysize) {
                heavysize = sub[v];
                heavychild = v;
            }
        }
        if (heavychild != -1) HLD(heavychild , u);
        for (int v : g[u]) {
            if (v != par && v != heavychild) {
                chain_no++;
                HLD(v , u);
            }
        }
        return;
    }
    void Update(int p , int val) {
        T.Update(1 , 0 , N - 1, node_serial[p] , val);
        node_val[p] = val;
    }
    long long Query(int u , int v) {
        long long ans = 0;
        for ( ; chain_ind[u] != chain_ind[v] ; v = parent[chain_head[chain_ind[v]]]) {
            if (depth[chain_head[chain_ind[u]]] > depth[chain_head[chain_ind[v]]])
                swap( u , v );
            ans = max(ans , T.Query(1 , 0 , N - 1 , node_serial[chain_head[chain_ind[v]]] , node_serial[v]));
        }
        if (depth[u] > depth[v])
            swap(u , v);
        ans = max(ans , T.Query(1 , 0 , N - 1 , node_serial[u] , node_serial[v]));
        return ans;
    }
} hd; 
/***********************Lowest Common Ancestor***********************/
/* 1.   All nodes are number 0 to n - 1 */
/* 2.   simply Init(total nodes) and call AddEdge(u , v) for all the edges */
/* 3.   Call Build() to run dfs and build the sparse table */

struct LowestCommonAncestor {
    int N , root = 0, po;
    
    vector <vector <int> > g;
    vector <vector <int> > sptab; 
    vector <int> depth;
    vector <int> parent;
    
    void Init(int _n) {
        N = _n; 
        po = log2((N)) + 1;
        g.assign(N, {});
        depth.resize(N);
        parent.resize(N);
        sptab.assign(N, {});
    }
    void AddEdge(int u , int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void Dfs(int u , int par = -1) {
        if(par == -1) {
            depth[u] = 0;
            parent[u] = -1;
        }
        for(int v : g[u]) {
            if (v == par) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            Dfs(v , u);
        }
    } 
    void SparceTable() {
        for(int i = 0 ; i < N ; i++) sptab[i][0] = parent[i];
        for(int j = 1 ; (1 << j) < N ; j++) {
            for(int i = 0 ; i < N ; i++) {
                if(sptab[i][j - 1] != -1) {
                    sptab[i][j] = sptab[sptab[i][j - 1]][j - 1];
                }
            }
        }
    }
    void Build() {
        for(int i = 0 ; i < N ; i++) {
            for(int j = 0 ; j <= po ; j++) {
                sptab[i].push_back(-1);
            }
        }
        Dfs(root);
        SparceTable();
    }
    int Lca(int u , int v) {
        if(depth[u] < depth[v]) swap(u , v);
        int log;
        for(log = 1 ; (1 << log) <= depth[u] ; log++); log--;
        for(int i = log ; i >= 0 ; i--) {
            if(depth[u] - (1 << i) >= depth[v]) {
                u = sptab[u][i];
            }
        }
        if(u == v) return u;
        for(int i = log ; i >= 0 ; i--) {
            if(sptab[u][i] != -1 && sptab[u][i] != sptab[v][i]) {
                u = sptab[u][i];
                v = sptab[v][i];
            } 
        }
        return parent[u];
    }
    int KthAncestor(int u, int k) {
        int log;
        for(log = 1 ; (1 << log) <= depth[u] ; log++); log--;
        for(int i = log ; i >= 0 ; i--) {
            if(k - (1 << i) >= 0) {
                u = sptab[u][i];
                k -= (1 << i);
            }
        }
        return u;
    }
    int Getdist(int u , int v) {
        return (depth[u] + depth[v] - (2 * (depth[Lca(u , v)]))) ;
    }
    bool IsAnsector(int u , int v) {
        int cur = Lca(u , v);
        if(cur == u) return 1;
        return 0;
    }
} lca;
int main() {
    FasterIO
    int n, q; cin >> n >> q;
    hd.Init(n);
    //lca.Init(n);
    vector <ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    hd.TakeNodeVal(vec);
    for (int i = 0; i < n - 1; i++) {
        int u , v; cin >> u >> v;
        u-- , v--;
        hd.AddEdge(u , v);
        //lca.AddEdge(u , v);
    }
    hd.Build();
    //lca.Build();
    while (q--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int u , val;
            cin >> u >> val;
            u--;
            hd.Update(u , val);
        } else if (tp == 2) {
            int u , v; cin >> u >> v;
            u-- , v--;
            //int lc = lca.Lca(u , v);
            //ll ans = max(hd.Query(u , lc) , hd.Query(lc , v)); 
            cout << hd.Query(u , v) << " ";
        }
    }
    return 0;
}
