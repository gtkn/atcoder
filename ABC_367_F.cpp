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


// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}




void solve(){
    ll N,Q;
    cin >> N >> Q;
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];

    ll MOD = (1LL<<61)-1;
    vec(ll) h(N+1);
    rep1(i,N) h[i] = RandInt(1,MOD-1);

    vec(ll) cuma(N+1),cumb(N+1);
    rep(i,N){
        cuma[i+1] = (cuma[i] + h[A[i]])%MOD;
        cumb[i+1] = (cumb[i] + h[B[i]])%MOD;    
    }

    rep(i,Q){
        ll l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll ha = (cuma[r1]-cuma[l1-1]+MOD)%MOD;
        ll hb = (cumb[r2]-cumb[l2-1]+MOD)%MOD;
        if(ha==hb) sayyn;
    }







}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
