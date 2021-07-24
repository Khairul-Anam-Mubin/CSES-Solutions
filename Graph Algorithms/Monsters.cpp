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
 
int dx[] = {0 , 0 , -1 , 1 , -1 , -1 , 1 , 1 , 0} ;  // right , left , up , down
int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 , -1 , 1 , 0} ;

const int mxN = 1000;
char g[mxN][mxN]; 
int n , m;
bool vis[mxN][mxN];
int Alevel[mxN][mxN];
int Mlevel[mxN][mxN];
char sign[mxN][mxN];

vector <vector <pair <int , int>>> path;  
vector <pair <int , int>> ex_points;
vector <pair <int , int>> mon_points;

void Bfs(int sx , int sy, int x) {
    memset(vis , 0 , sizeof(vis));
    //memset(Mlevel , 0 , sizeof(Mlevel));
    vis[sx][sy] = 1;
    if (x == 0) Alevel[sx][sy] = 0;
    else Mlevel[sx][sy] = 0;
    queue <pair <int ,int>> q;
    q.push({sx , sy});
    while (!q.empty()) {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if (vx < n && vy < m && vx >= 0 && vy >= 0 && vis[vx][vy] == 0) {
                if (g[vx][vy] == '.') {
                    vis[vx][vy] = 1;
                    if (x == 1) Mlevel[vx][vy] = Mlevel[ux][uy] + 1;
                    if (x == 0) {
                        Alevel[vx][vy] = Alevel[ux][uy] + 1;
                        path[vx][vy] = {ux , uy};
                        if (i == 0) {
                            sign[vx][vy] = 'R';
                        } else if (i == 1) {
                            sign[vx][vy] = 'L';
                        } else if (i == 2) {
                            sign[vx][vy] = 'U';
                        } else if (i == 3) {
                            sign[vx][vy] = 'D';
                        }
                        if (vx == 0 || vy == 0 || vx + 1 == n || vy + 1 == m) {
                            ex_points.push_back({vx , vy});
                        }
                    }
                    q.push({vx , vy});
                }
                if (x == 0 && g[vx][vy] == 'M' && Alevel[vx][vy] <= 50) {
                    mon_points.push_back({vx , vy});
                }
            }
        }
    }
}
int main() {
    FasterIO
    cin >> n >> m;
    int ax = -1, ay = -1;
    for (int i = 0; i < n; i++) {
        vector <pair <int , int>> p;
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') ax = i , ay = j;
            p.push_back({-1 , -1});
        }
        path.push_back(p);
    }
    if (ax == -1) {
        cout << "NO\n";
        return 0;
    }
    Bfs(ax , ay , 0);
    //cout << "Exit points: ";
    //for (int i = 0; i < ex_points.size(); i++) {
    //    cout << ex_points[i].first << " " << ex_points[i].second << "\n";
    //}
    //cout << "Start level :\n";
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << Alevel[i][j] << " ";
        }
        cout << "\n";
    }
    */
    map<pair <int , int>, int> ispossible;
    for (int k = 0; k < mon_points.size(); k++) {
        Bfs(mon_points[k].first , mon_points[k].second, 1);
        /*
        cout << k << " kth monster level:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << Mlevel[i][j] << " ";
            }
            cout << "\n";
        }
        */
        for (int i = 0; i < ex_points.size(); i++) {
            //if (g[mon_points[k].first][mon_points[k].second] != 'M')
                if (Mlevel[ex_points[i].first][ex_points[i].second] == 0 || Alevel[ex_points[i].first][ex_points[i].second] < Mlevel[ex_points[i].first][ex_points[i].second]) {
                    ispossible[{ex_points[i].first ,ex_points[i].second}]++;
                }
        }
    }
    pair <int , int> res = {-1, -1};
    for (auto it : ispossible) {
        if (it.second == mon_points.size()) {
            res = it.first;
            break;
        }
    }
    if (mon_points.size() == 0) {
        if (ex_points.size() != 0) {
            res = ex_points[0];
        }
    }
    if (ex_points.size() == 0) {
        if (ax + 1 == n || ay + 1 == m) res = {ax , ay};
    }
    //cout << res.first << " " << res.second << "\n";
    if (res.first == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string ans; 
        while (res.first != -1) {
            int tmpx = res.first;
            int tmpy = res.second;
            ans.push_back(sign[tmpx][tmpy]);
            res = path[tmpx][tmpy];
        }
        ans.pop_back();
        reverse(ans.begin() , ans.end());
        cout << ans.size() << "\n";
        cout << ans << "\n";
    }
    return 0;
}