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

// modがテストケースで変わるとき
using mint = modint;

void solve(){
    ll N,P;
    cin >> N >> P;

    mint::set_mod(P);

    vvvec(mint) dp(N+1,vvec(mint)(N+10,vec(mint)(4)));
    dp[0][0][3] = 1;
    dp[0][1][1] = 1;

    rep(i,N)rep(j,N){
        dp[i+1][j+1][1] += dp[i][j][1];
        dp[i+1][j][3] += dp[i][j][1];

        dp[i+1][j+1][2] += dp[i][j][2];
        dp[i+1][j][3] += dp[i][j][2];

        dp[i+1][j+2][1] += dp[i][j][3];
        dp[i+1][j+2][2] += dp[i][j][3];
        dp[i+1][j+1][3] += dp[i][j][3]*3;
        dp[i+1][j][3] += dp[i][j][3];
    }


    // rep(i,N+1){
    //     rep1(k,3) cerr << dp[i][1][k].val() << " "; cerr << endl;
    // }

    rep1(i,N-1) cout << dp[N-1][i][3].val() << " "; cout << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
