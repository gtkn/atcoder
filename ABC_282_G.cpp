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
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


using mint = modint;

void solve(){
    ll N,K,P;
    cin >> N >> K >> P;

    mint::set_mod(P);

    vvvvec(mint) dp(N+1, vvvec(mint)(K+2,vvec(mint)(N+1,vec(mint)(N+1))) );

    dp[0][0][N][N]=1;
    rep(i,N){
        vvvec(mint) cum(K+2,vvec(mint)(N+2,vec(mint)(N+2)));
        rep(j,K+2){
            rep1(k,N+1)rep1(l,N+1) cum[j][k][l] = cum[j][k-1][l] + cum[j][k][l-1] - cum[j][k-1][l-1] + dp[i][j][k-1][l-1];
        }


        auto f = [&](ll jj,ll x0,ll y0, ll x1, ll y1)->mint{
            if(x0>=x1 || y0>=y1 || jj<0) return 0;
            return cum[jj][x1][y1] - cum[jj][x1][y0] - cum[jj][x0][y1] + cum[jj][x0][y0];
        };


        rep(j,K+2)rep(k,N-i)rep(l,N-i){
            dp[i+1][j][k][l] += f(j, k+1, 0, N-i+1, l+1); 
            dp[i+1][j][k][l] += f(j, 0, l+1, k+1, N-i+1);

            dp[i+1][j][k][l] += f(j-1, 0, 0, k+1, l+1);
            dp[i+1][j][k][l] += f(j-1, k+1, l+1, N-i+1, N-i+1);
        }
    }

    cout << dp[N][K+1][0][0].val() << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
