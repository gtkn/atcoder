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
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    auto f1 = [&](double x)->bool{
        vvec(double) dp(N+1,vec(double)(2, -llINF));
        dp[0][1] = 0;
        rep(i,N){
            chmax(dp[i+1][1], dp[i][0]+A[i]-x);
            chmax(dp[i+1][0], dp[i][1]);
            chmax(dp[i+1][1], dp[i][1]+A[i]-x);
        }

        return max(dp[N][0],dp[N][1])>=0;
    };


    auto f2 = [&](ll x)->bool{
        vvec(ll) dp(N+1,vec(ll)(2, -llINF));
        dp[0][1] = 0;
        rep(i,N){
            ll d = ((A[i]>=x)? 1 : -1 );
            chmax(dp[i+1][1], dp[i][0]+d);
            chmax(dp[i+1][0], dp[i][1]);
            chmax(dp[i+1][1], dp[i][1]+d);
        }
        return max(dp[N][0],dp[N][1])>=1;
    };


    double l0 = 0, r0 = 1e9+10;
    double eps = 1e-6;
    while(r0-l0>eps){
        double mid = (l0+r0)/2;
        if(f1(mid)) l0 = mid;
        else r0 = mid;
    }
    printf("%.6f\n",l0);

    ll l1 = 0, r1 = 1e9+10;
    while(r1-l1>1){
        ll mid = (l1+r1)/2;
        if(f2(mid)) l1 = mid;
        else r1 = mid;
    }
    cout << l1 << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
