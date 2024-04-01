//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
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
constexpr ll llINF = 1LL << 60;
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


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N, M;
    cin >> N >> M;

    vvec(ll) A(N,vec(ll)(N));
    rep(i,N) rep(j,N) cin >> A[i][j];


    ll nn = N-M+1;

    vvec(ll) x1(N,vec(ll)(nn));
    rep(i,N){
        rep(j,M) x1[i][0] += A[i][j];
        rep(j,nn){
            if(j==0) continue;
            x1[i][j] = x1[i][j-1] + A[i][j+M-1] - A[i][j-1];
        }
    }

    vvec(ll) x2(nn,vec(ll)(nn));
    rep(j,nn){
        rep(i,M) x2[0][j] += x1[i][j];
        rep(i,nn){
            if(i==0) continue;
            x2[i][j] = x2[i-1][j] + x1[i+M-1][j] - x1[i-1][j];
        }
    }


    vvec(ll) dp0(N+1,vec(ll)(N+1));
    vvec(ll) dp1(N+1,vec(ll)(N+1)); 
    vvec(ll) dp2(N+1,vec(ll)(N+1)); 
    vvec(ll) dp3(N+1,vec(ll)(N+1)); 

    rep(i,nn)rep(j,nn) dp0[M+i][M+j] = x2[i][j];
    rep(i,N+1)rep1(j,N) chmax(dp0[i][j], dp0[i][j-1]);
    rep(j,N+1)rep1(i,N) chmax(dp0[i][j], dp0[i-1][j]);

    rep(i,nn)rep(j,nn) dp1[M+i][j] = x2[i][j];
    rep(i,N+1)repr(j,N) chmax(dp1[i][j], dp1[i][j+1]);
    rep(j,N+1)rep1(i,N) chmax(dp1[i][j], dp1[i-1][j]);

    rep(i,nn)rep(j,nn) dp2[i][j] = x2[i][j];
    rep(i,N+1)repr(j,N) chmax(dp2[i][j], dp2[i][j+1]);
    rep(j,N+1)repr(i,N) chmax(dp2[i][j], dp2[i+1][j]);

    rep(i,nn)rep(j,nn) dp3[i][M+j] = x2[i][j];
    rep(i,N+1)rep1(j,N) chmax(dp3[i][j], dp3[i][j-1]);
    rep(j,N+1)repr(i,N) chmax(dp3[i][j], dp3[i+1][j]);


    // cerr << "x2 ------" << endl;
    // rep(i,nn){
    //     rep(j,nn) cerr << x2[i][j] << " ";
    //     cerr << endl;
    // }


    // cerr << "dp0 ------ " << endl;
    // rep(i,N+1){
    //     rep(j,N+1) cerr << dp0[i][j] << " ";
    //     cerr << endl;
    // } 

    // cerr << "dp1 ------ " << endl;
    // rep(i,N+1){
    //     rep(j,N+1) cerr << dp1[i][j] << " ";
    //     cerr << endl;
    // } 

    // cerr << "dp2 ------ " << endl;
    // rep(i,N+1){
    //     rep(j,N+1) cerr << dp2[i][j] << " ";
    //     cerr << endl;
    // }

    // cerr << "dp3 ------ " << endl;
    // rep(i,N+1){
    //     rep(j,N+1) cerr << dp3[i][j] << " ";
    //     cerr << endl;
    // }

    ll ans = 0;
    rep(i,N+1)rep(j,N+1){
        chmax(ans, dp0[i][j] + dp1[i][j] + dp2[i][0]);
        chmax(ans, dp1[i][j] + dp2[i][j] + dp3[0][j]);
        chmax(ans, dp2[i][j] + dp3[i][j] + dp0[i][N]);
        chmax(ans, dp3[i][j] + dp0[i][j] + dp1[N][j]);
    }

    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
