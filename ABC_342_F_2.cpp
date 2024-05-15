//title
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
    ll N,L,D;
    cin >> N >> L >> D;

    ll nn = N + D + 1;
    double p = 1./D;


    vec(double) v(nn), d(nn);
    d[0] = 1; d[1] = -1;
    double now = 0;
    rep(i,nn){
        now += d[i];
        v[i] = now;
        if(i<L){
            d[i+1] += v[i] * p;
            d[i+D+1] -= v[i] * p;
        }
    }


    vec(double) cum(nn+1);
    rep(i,nn) cum[i+1] = cum[i] + v[i];

    double b0 = cum[nn] - cum[N+1];

    // rep(i,nn) cerr << v[i] << " "; cerr << endl;
    // cerr << b0 << endl;

    vec(double) dp(nn);
    double tot = 0;
    repr(i,N+1){
        double a = tot * p;
        double b = b0;
        if(L<i) b += cum[i] - cum[L];
        dp[i] = max(a,b);
        tot += dp[i];
        tot -= dp[i+D];
    }


    double ans = dp[0];
    printf("%.10f\n",ans);



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
