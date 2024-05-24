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
    ll N;
    cin >> N;

    vvec(ll) P(N,vec(ll)(N));
    vvec(ll) R(N,vec(ll)(N-1));
    vvec(ll) D(N-1,vec(ll)(N));
    
    rep(i,N)rep(j,N) cin >> P[i][j];
    rep(i,N)rep(j,N-1) cin >> R[i][j];
    rep(i,N-1)rep(j,N) cin >> D[i][j];

    vvec(ll) dp(N,vec(ll)(N,llINF));
    vvec(ll) dp2(N,vec(ll)(N,-llINF));
    dp[0][0] = 0; dp2[0][0]=0;


    rep(i,N)rep(j,N){
    
        vvec(ll) dp3(N,vec(ll)(N,llINF));
        dp3[i][j]=0;
    
    
        for(ll ii=i; ii<N; ii++)for(ll jj=j; jj<N; jj++){
            if(ii==i && jj==j) continue;
            if(ii>0) chmin(dp3[ii][jj], dp3[ii-1][jj] + D[ii-1][jj]);
            if(jj>0) chmin(dp3[ii][jj], dp3[ii][jj-1] + R[ii][jj-1]);

            ll diff = dp3[ii][jj] - dp2[i][j];

            ll x = (diff+P[i][j]-1)/P[i][j];
            if(diff<=0) x=0;

            if(dp[ii][jj]==(dp[i][j]+x) ){
                chmax(dp2[ii][jj], dp2[i][j]+x*P[i][j] - dp3[ii][jj]);
            }
            if(chmin(dp[ii][jj], dp[i][j]+x)){
                dp2[ii][jj] = dp2[i][j]+x*P[i][j] - dp3[ii][jj];
            }
        }
    }

    // rep(i,N){
    //     rep(j,N) cout << dp[i][j] << " "; cout << endl;
    // }



    ll ans = 2*(N-1) + dp[N-1][N-1];
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