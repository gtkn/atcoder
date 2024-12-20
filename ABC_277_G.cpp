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
    ll N,M,K;
    cin >> N >> M >> K;

    vvec(ll) g(N);
    rep(_,M){
        ll a,b;
        cin >> a >> b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vec(ll) C(N);
    rep(i,N) cin >> C[i];

    vvec(mint) dp0(K+1,vec(mint)(N));
    vvec(mint) dp1(K+1,vec(mint)(N));
    vvec(mint) dp2(K+1,vec(mint)(N));
    dp0[0][0] = 1;
    dp1[0][0] = 0;
    dp2[0][0] = 0;

    vec(mint) q(N);
    rep(i,N) q[i] = mint(g[i].size()).inv();

    rep(i,K)rep(now,N){
        for(ll nxt:g[now]){
            if(C[nxt]==0){
                dp0[i+1][nxt] += q[now] * dp0[i][now];
                dp1[i+1][nxt] += q[now] *(dp1[i][now] + dp0[i][now]);
                dp2[i+1][nxt] += q[now] *(dp2[i][now] + 2*dp1[i][now] + dp0[i][now]);
            }else{
                dp0[i+1][nxt] += q[now] * dp0[i][now];
                dp1[i+1][nxt] += q[now] * dp1[i][now];
                dp2[i+1][nxt] += q[now] * dp2[i][now];
            }
        } 
    }

    mint ans = 0;
    rep1(i,K)rep(pos,N) if(C[pos]==1) ans += dp2[i][pos];

    cout << ans.val() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}