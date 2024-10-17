//title
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep1(i,n) for (ll i = 1; i <= (n); ++i)
#define repr(i,n) for (ll i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (ll i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目

#define vec(T) vector<T>
#define vvec(T) vector<vec(T)>
#define vvvec(T) vector<vvec(T)>
#define vvvvec(T) vector<vvvec(T)>

//typedef vector<mint>vi;
//typedef vector<vi>vvi;
//typedef vector<vvi>vvvi;
//typedef vector<vvvi>vvvvi;

#define all(x) x.begin(),x.end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,M;
    cin >> N >> M;
    vec(string) S(N);
    rep(i,N) cin >> S[i];


    ll nn = 3*N+10;
    vvec(ll) a(nn,vec(ll)(nn)), b(nn,vec(ll)(nn));

    rep(i,N)rep(j,N){
        if(S[j][i]=='X') continue;
        ll ii = min(i+2*M, N);
        a[i][j]++;
        a[ii][j]--;
        b[i][j+M]++;
        b[i+1][j+M]++;
        b[ii][j]--;
        b[ii+1][j]--;
    }

    rep(i,nn)rep(j,nn){
        if(i==0) continue;
        a[i][j] += a[i-1][j];
    }

    rep(i,nn)rep(j,nn){
        if(i-2<0 || j+1>=nn) continue;
        b[i][j] += b[i-2][j+1];
    }

    vvec(ll) c(nn,vec(ll)(nn));
    rep(i,nn)rep(j,nn){
        c[i][j] = a[i][j] - b[i][j];
    }

    rep(i,nn)rep(j,nn){
        if(j==0) continue;
        c[i][j] += c[i][j-1];
    }

    ll Q;
    cin >> Q;
    while(Q--){
        ll x,y;
        cin >> x >> y;
        x--; y--;
        swap(x,y);
        cout << c[x][y] << endl;
    }

    // cerr << "---" << endl;
    // rep(i,nn){
    //     rep(j,nn) cerr << a[i][j] << " "; cerr << endl;
    // }
    // cerr << "---" << endl;
    // rep(i,nn){
    //     rep(j,nn) cerr << b[i][j] << " "; cerr << endl;
    // }
    // cerr << "---" << endl;
    // rep(i,nn){
    //     rep(j,nn) cerr << c[i][j] << " "; cerr << endl;
    // }








}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
