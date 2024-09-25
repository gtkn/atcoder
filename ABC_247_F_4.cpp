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



void solve(){
    ll N;
    cin >> N;
    vec(ll) P(N),Q(N);
    rep(i,N) cin >> P[i];
    rep(i,N) cin >> Q[i];
    rep(i,N) P[i]--, Q[i]--;


    vvec(mint) dp0(N+1,vec(mint)(2));
    dp0[0][0] = 1;
    rep(i,N){
        dp0[i+1][0] += dp0[i][1];
        dp0[i+1][1] += dp0[i][0] + dp0[i][1];
    }

    vvec(mint) dp1(N+1,vec(mint)(2));
    dp1[0][1] = 1;
    rep(i,N){
        dp1[i+1][0] += dp1[i][1];
        dp1[i+1][1] += dp1[i][0] + dp1[i][1];
    }


    dsu uf(N);
    rep(i,N) uf.merge(P[i],Q[i]);

    mint ans = 1;
    for(auto grp:uf.groups()){
        ll sz = grp.size();
        ans *= dp0[sz][0] + dp1[sz][1];
    }
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
