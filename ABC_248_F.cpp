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
#define watch(x) cout << (#x) << " is " << (x) << endl
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;
using mint = modint;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

//------------------------------------------------

struct Solver{
 
    void solve(){
        ll N,P;
        cin >> N >> P;
        mint::set_mod(P);

        vvvec(mint) dp(N+10,vvec(mint)(N+10,vec(mint)(2)));
        dp[0][0][1] = 1;
        dp[0][1][0] = 1;

        rep(i,N-1)rep(j,N){
            dp[i+1][j+1][0] += dp[i][j][0];
            dp[i+1][j][1] += dp[i][j][0];
            
            dp[i+1][j+2][0] += dp[i][j][1]*2;
            dp[i+1][j+1][1] += dp[i][j][1]*3;
            dp[i+1][j][1] += dp[i][j][1];
        }

        rep1(i,N-1) cout << dp[N-1][i][1].val() << " ";
        cout << endl;



    }
};


int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
