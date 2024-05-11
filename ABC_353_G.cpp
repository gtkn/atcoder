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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

ll op(ll a, ll b){
    return max(a,b);
}
ll ee(){
    return -llINF;
}



void solve(){
    ll N,C;
    cin >> N >> C;
    ll M;
    cin >> M;
    vec(ll) T(M),P(M);
    rep(i,M) cin >> T[i] >> P[i];
    rep(i,M) T[i]--;


    vec(ll) dp(N,-llINF);
    dp[0] = 0;

    segtree<ll,op,ee> seg_l(N);
    segtree<ll,op,ee> seg_r(N);

    rep(i,N) seg_l.set(i, dp[i]+i*C );
    rep(i,N) seg_r.set(i, dp[i]+(N-1-i)*C );

    rep(i,M){
        ll t = T[i], p = P[i];
        ll pre = dp[t];

        chmax(pre, seg_l.prod(0,t) - t*C);
        chmax(pre, seg_r.prod(t,N) - (N-1-t)*C);

        dp[t] = pre+p;
        seg_l.set(t, dp[t]+t*C);
        seg_r.set(t, dp[t]+(N-1-t)*C);
    }

    ll ans = 0;
    rep(i,N) chmax(ans, dp[i]);
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
