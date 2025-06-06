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
using mint = modint998244353;
// using mint = modint;
// mint::set_mod(P);


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
    ll N,K;
    cin >> N >> K;

    ll M = 61;

    vec(bool) b(M);
    rep(i,M) b[i] = (N>>i)&1;

    // rep(i,M) cerr << b[i] << " "; cerr << nl;

    vvvec(mint) dp_sum(M+1,vvec(mint)(K+2,vec(mint)(2)));
    vvvec(mint) dp_cnt(M+1,vvec(mint)(K+2,vec(mint)(2)));
    dp_sum[M][0][0] = 0;
    dp_cnt[M][0][0] = 1;

    repr(i,M)rep(j,K+1){
        if(b[i]){
            dp_sum[i][j][1] += dp_sum[i+1][j][0]*2;
            dp_cnt[i][j][1] += dp_cnt[i+1][j][0];

            dp_sum[i][j+1][0] += dp_sum[i+1][j][0]*2 + dp_cnt[i+1][j][0];
            dp_cnt[i][j+1][0] += dp_cnt[i+1][j][0];
        }else{
            dp_sum[i][j][0] += dp_sum[i+1][j][0]*2;
            dp_cnt[i][j][0] += dp_cnt[i+1][j][0];
        }
        dp_sum[i][j][1] += dp_sum[i+1][j][1]*2;
        dp_cnt[i][j][1] += dp_cnt[i+1][j][1];

        dp_sum[i][j+1][1] += dp_sum[i+1][j][1]*2 + dp_cnt[i+1][j][1];
        dp_cnt[i][j+1][1] += dp_cnt[i+1][j][1];
    }

    mint ans = dp_sum[0][K][0] + dp_sum[0][K][1];
    cout << ans.val() << nl;  


    // rep(i,M) rep(j,K+1) rep(k,2){
    //     cerr << i << " " << j << " " << k << ": " << dp_sum[i][j][k].val() << " " << dp_cnt[i][j][k].val() << endl;
    // }


}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
