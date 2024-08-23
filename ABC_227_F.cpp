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

const ll M = 33;
const ll M2 = 33*33;
ll dp[M][M][M2];

void solve(){
    ll H,W,K;
    cin >> H >> W >> K;

    vvec(ll) A(H,vec(ll)(W));
    rep(i,H) rep(j,W) cin >> A[i][j];

    vec(tri) v;
    rep(i,H) rep(j,W) v.emplace_back(A[i][j],i,j);
    sort(all(v));
    
    vvec(ll) b(H,vec(ll)(W));
    rep(i,H*W){
        auto [a,h,w] = v[i];
        b[h][w] = i;
    }

    auto f = [&](ll th)->ll{
        rep(i,M)rep(j,M)rep(k,M2) dp[i][j][k] = llINF;

        if(b[0][0]<th) dp[0][0][0] = 0;
        else dp[0][0][1] = A[0][0];

        rep(i,H)rep(j,W)rep(k,K+1){
            if(i<H-1){
                if(b[i+1][j]<th) chmin(dp[i+1][j][k],dp[i][j][k]);
                else chmin(dp[i+1][j][k+1],dp[i][j][k]+A[i+1][j]);
            }
            if(j<W-1){
                if(b[i][j+1]<th) chmin(dp[i][j+1][k],dp[i][j][k]);
                else chmin(dp[i][j+1][k+1],dp[i][j][k]+A[i][j+1]);
            }
        }
        return dp[H-1][W-1][K];
    };

    ll ans = llINF;
    rep(i,H)rep(j,W){
        ll tmp = f(b[i][j]);
        // cerr << i << ' ' << j << ' ' << tmp << endl;        
        chmin(ans,tmp);
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
