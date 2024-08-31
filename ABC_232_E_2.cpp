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
using mint = modint998244353;


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
    ll H,W,K;
    cin >> H >> W >> K;
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll xx = 1, yy = 1;
    if(x1==x2) xx = 0;
    if(y1==y2) yy = 0;
    mint hh = H-xx-1;
    mint ww = W-yy-1;

    vvvvec(mint) mvs(3,vvvec(mint)(3));

    mvs[0][0] = {
        {hh-1+ww-1,1,yy},
        {1,0,0},
        {xx,0,0}
    };

    mvs[0][1] = {
        {ww,hh-1,yy},
        {0,1,0},
        {0,xx,0}
    };

    mvs[0][2] = {
        {ww,1,hh-1},
        {0,0,1},
        {0,0,xx}
    };

    mvs[1][0] = {
        {hh,0,0},
        {ww-1,1,yy},
        {xx,0,0}
    };

    mvs[1][1] = {
        {0,hh,0},
        {ww,0,yy},
        {0,xx,0}
    };

    mvs[1][2] = {
        {0,0,hh},
        {ww,1,0},
        {0,0,xx}
    };

    mvs[2][0] = {
        {hh,0,0},
        {1,0,0},
        {ww-1,1,yy}
    };

    mvs[2][1] = {
        {0,hh,0},
        {0,1,0},
        {ww,0,yy}
    };

    mvs[2][2] = {
        {0,0,hh},
        {0,0,1},
        {ww,1,0}
    };


    vvec(mint) dp(3,vec(mint)(3));
    dp[1][1] = 1;

    rep(_,K){
        vvec(mint) ndp(3,vec(mint)(3));
        rep(i,3) rep(j,3){
            rep(k,3) rep(l,3){
                ndp[k][l] += dp[i][j] * mvs[i][j][k][l];
            }
        }
        dp = ndp;
    }


    mint ans = dp[xx+1][yy+1];
    cout << ans.val() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
