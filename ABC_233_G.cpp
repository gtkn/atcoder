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

const ll M = 60;
ll dp[M][M][M][M];


void solve(){
    ll N;
    cin >> N;
    vec(string) S(N);
    rep(i,N) cin >> S[i];

    vvec(bool) vv(N,vec(bool)(N));
    rep(i,N)rep(j,N){
        if(S[i][j]=='#') vv[i][j] = true;
    }

    rep(i,M)rep(j,M)rep(k,M)rep(l,M) dp[i][j][k][l] = llINF;


    auto f = [&](auto f, ll u, ll b, ll l,ll r)->ll{
        if(dp[u][b][l][r] != llINF) return dp[u][b][l][r];
        chmin(dp[u][b][l][r], max(b-u,r-l));

        for(ll i=u; i<b; ++i){
            bool is_empty = true;
            for(ll j=l; j<r; ++j){
                if(vv[i][j]) is_empty = false; 
            }
            if(is_empty){
                chmin(dp[u][b][l][r], f(f,u,i,l,r) + f(f,i+1,b,l,r));
            }
        }

        for(ll j=l; j<r; ++j){
            bool is_empty = true;
            for(ll i=u; i<b; ++i){
                if(vv[i][j]) is_empty = false;
            }
            if(is_empty){
                chmin(dp[u][b][l][r], f(f,u,b,l,j) + f(f,u,b,j+1,r));
            }
        }

        return dp[u][b][l][r];
    };

    ll ans = f(f,0,N,0,N);

    cout << ans << nl;







}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
