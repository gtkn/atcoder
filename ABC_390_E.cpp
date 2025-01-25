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
    ll N,X;
    cin >> N >> X;

    vvec(Pll) vv(3);
    rep(_,N){
        ll v,a,c;
        cin >> v >> a >> c;
        v--;
        vv[v].push_back({a,c});
    }

    vvec(ll) memo(3,vec(ll)(X+1));

    rep(ii,3){
        ll n = vv[ii].size();
        vvec(ll) dp(n+1,vec(ll)(X+2,-llINF));
        dp[0][0] = 0;
        rep(i,n)rep(j,X+1){
            auto [a,c] = vv[ii][i];
            // chmax(dp[i][j+1],dp[i][j]);
            chmax(dp[i+1][j],dp[i][j]);
            if(j+c<=X) chmax(dp[i+1][j+c],dp[i][j]+a);
        }
        rep1(j,X) dp[n][j] = max(dp[n][j],dp[n][j-1]);
        rep(j,X+1) memo[ii][j] = dp[n][j];
    }


    auto f = [&](ll th)->ll{
        ll res = 0;
        rep(ii,3){
            auto itr = lower_bound(all(memo[ii]),th);
            if(itr == memo[ii].end()) return llINF;
            res += itr-memo[ii].begin();
        }
        return res;
    };


    ll l = 0, r = llINF;
    while(r-l>1){
        ll mid = (l+r)/2;
        if(f(mid)<=X) l = mid;
        else r = mid;
    }

    cout << l << endl;


    // rep(ii,3){
    //     cerr << ii << "---" << endl;
    //     for(auto [a,c]:vv[ii]){
    //         cerr << a << " " << c << endl;
    //     }
    // }

    // rep(ii,3){
    //     cerr << ii << "---" << endl;
    //     rep(j,X+1){
    //         cerr << memo[ii][j] << " ";
    //     }
    //     cerr << endl;
    // }

    // cerr << f(0) << endl;
    // cerr << f(1) << endl;
    // cerr << f(2) << endl;
    // cerr << f(3) << endl;
    // cerr << f(4) << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
