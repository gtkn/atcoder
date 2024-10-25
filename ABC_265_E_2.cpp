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
    ll N,M;
    cin >> N >> M;
    ll A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    vec(ll) X(M),Y(M);
    rep(i,M) cin >> X[i] >> Y[i];

    set<Pll> st;
    rep(i,M) st.emplace(X[i],Y[i]);

    // vvvec(Pll) pos(N+1,vvec(Pll)(N+1,vec(Pll)(N)));
    vvvec(bool) isok(N+1,vvec(bool)(N+1,vec(bool)(N+1,true)));

    auto f = [&](const ll& i, const ll& j,const ll& k)->Pll{
        return {A*i + C*j + E*k, B*i + D*j + F*k};
    };


    rep(i,N+1)rep(j,N+1-i)rep(k,N+1-i-j){
        Pll pos = f(i,j,k);
        if(st.find(pos)!=st.end()) isok[i][j][k] = false;
    }

    vvvec(mint) dp(N+1,vvec(mint)(N+1,vec(mint)(N+1)));
    dp[0][0][0] = 1;
    rep(i,N)rep(j,N-i)rep(k,N-i-j){
        if(isok[i+1][j][k]) dp[i+1][j][k] += dp[i][j][k];
        if(isok[i][j+1][k]) dp[i][j+1][k] += dp[i][j][k];
        if(isok[i][j][k+1]) dp[i][j][k+1] += dp[i][j][k];
    }

    mint ans = 0;
    rep(i,N+1)rep(j,N+1-i){
        ll k = N-i-j;
        ans += dp[i][j][k];
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
