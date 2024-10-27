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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,W;
    cin >> N >> W;
    vec(ll) w(N),v(N);
    rep(i,N) cin >> w[i] >> v[i];

    ll M = 3030;
    vvec(ll) vv(M);
    rep(i,N) vv[w[i]].push_back(i);

    vvec(Pll) c(M);
    vec(ll) cnt(N);


    auto f = [&](ll ii)->ll{
        cnt[ii]++;
        return v[ii] - 2*cnt[ii] + 1;
    };

    rep(wi,M){
        c[wi].emplace_back(0,0);
        if(vv[wi].empty()) continue;
        
        priority_queue<Pll> q;
        for(ll ii:vv[wi]) q.emplace(f(ii),ii);

        ll wtot = 0, vtot = 0;
        while(wtot<M){
            auto [vi,ii] = q.top(); q.pop();
            wtot += wi;
            vtot += vi;
            c[wi].emplace_back(wtot,vtot);
            q.emplace(f(ii),ii);
        }
        sort(all(c[wi]));
    }

    vvec(ll) dp(M+1,vec(ll)(M+1,-llINF));
    dp[0][0] = 0;


    rep(i,M)rep(j,M){
        for(auto [wi,vi]:c[i]){
            if(j+wi>M) break;            
            chmax(dp[i+1][j+wi], dp[i][j]+vi);
        }
    }

    ll ans = 0;
    rep(j,W+1) chmax(ans,dp[M][j]);
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