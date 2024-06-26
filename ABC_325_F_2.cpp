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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

void solve(){
    ll N;
    cin >> N;
    vec(ll) D(N);
    rep(i,N) cin >> D[i];
    vec(ll) L(2), C(2), K(2);
    rep(i,2) cin >> L[i] >> C[i] >> K[i];


    vvec(ll) dp(N+1,vec(ll)(K[0]+1, llINF));
    dp[0][0] = 0;
    rep(i,N)rep(j,K[0]+1){
        if (dp[i][j] == llINF) continue;
        ll rem = D[i];
        for(ll jj = j; jj<=K[0]; ++jj){
            chmin(dp[i+1][jj], dp[i][j] + (rem+L[1]-1)/L[1] );
            rem = max(0LL, rem-L[0]);
        }
    }

    ll ans = llINF;
    rep(j,K[0]+1){
        if(dp[N][j] > K[1]) continue;
        chmin(ans, dp[N][j]*C[1] + j*C[0]);
    }
    if(ans>=llINF) ans = -1;

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
