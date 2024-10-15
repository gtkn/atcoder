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
    ll N;
    cin >> N;
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];
    rep(i,N) A[i]--;

    vec(ll) bcum(N+1);
    rep(i,N) bcum[i+1] = bcum[i] + B[i];
    if(bcum[N]%3!=0) dame;

    ll th = bcum[N]/3;

    vvec(ll) aa(N,vec(ll)(3,1));
    rep(i,N) aa[i][A[i]] = 0;


    vvvec(ll) dp(N+1,vvec(ll)(th+1,vec(ll)(th+1,llINF)));
    dp[0][0][0] = 0;
    
    rep(i,N)rep(j,th+1)rep(k,th+1){
        ll l = bcum[i]-j-k;
        if(j+B[i]<=th) chmin(dp[i+1][j+B[i]][k], dp[i][j][k]+aa[i][0]);
        if(k+B[i]<=th) chmin(dp[i+1][j][k+B[i]], dp[i][j][k]+aa[i][1]);
        if(l+B[i]<=th) chmin(dp[i+1][j][k],      dp[i][j][k]+aa[i][2]);
    }

    ll ans = dp[N][th][th];
    if(ans==llINF) ans = -1;
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
