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
using mint = modint;

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




void solve(){
    ll N,P;
    cin >> N >> P;
    mint::set_mod(P);

    vvec(mint) dp(N+1,vec(mint)(N));
    vvec(mint) cum(N+1,vec(mint)(N));
    dp[0][0] = 1;
    cum[1][0] = -1;

    rep(i,N)rep(j,N){
        mint x = 25;

        if(i>0){
            dp[i][j] = dp[i-1][j] + cum[i][j];
        }else{
            x = 26;
        }

        ll ten = 1;
        for(ll jj = j+2; jj<N; ++jj){
            ll i0 = i+ten, i1 = i+ten*10;
            if(i0>N) break;
            cum[i0][jj] += dp[i][j]*x;
            if(i1<=N) cum[i1][jj] -= dp[i][j]*x;
            ten *= 10;
        }
    }

    // rep(i,N+1){
    //     rep(j,N) cerr << dp[i][j].val() << " "; cerr << nl;
    // }

    // cerr << "---" << nl;
    // rep(i,N+1){
    //     rep(j,N) cerr << cum[i][j].val() << " "; cerr << nl;
    // }

    mint ans = 0;
    rep(j,N) ans += dp[N-1][j] + cum[N][j];
    cout << ans.val() << nl;

        



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
