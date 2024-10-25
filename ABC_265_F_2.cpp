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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,D;
    cin >> N >>  D;

    vec(ll) p(N),q(N);
    rep(i,N) cin >> p[i];
    rep(i,N) cin >> q[i];


    vvec(mint) dp(D+1,vec(mint)(D+1,0));
    dp[0][0] = 1;


    rep(i,N){
        vvec(mint) diff1(D+1,vec(mint)(D+1,0));
        vvec(mint) diff2(D+1,vec(mint)(D+1,0));

        ll d = abs(p[i]-q[i]);
        rep(pd,D+1) rep(qd,D+1){
            mint now = dp[pd][qd];
            ll pd2 = pd+d;
            if(pd2<D && qd>0) diff1[pd2+1][qd-1]-=now;
            if(pd2<D && qd<D) diff2[pd2+1][qd+1]+=now;
            
            ll qd2 = qd+d;
            if(qd2<=D){
                diff1[pd][qd2]+=now;
            }else{
                ll w = qd2-D;
                if(pd+w<=D) diff1[pd+w][D]+=now;
            }
            if(qd2<D && pd<D){
                diff2[pd+1][qd2+1]+=now;
            }
        }

        rep1(pd,D)rep(qd,D) diff1[pd][qd] += diff1[pd-1][qd+1];
        rep1(pd,D)rep1(qd,D) diff2[pd][qd] += diff2[pd-1][qd-1];

        vvec(mint) dp2(D+1,vec(mint)(D+1,0));
        rep(pd,D+1)rep(qd,D+1) dp2[pd][qd] = diff1[pd][qd]+diff2[pd][qd];
        swap(dp,dp2);
    }

    mint ans = 0;
    rep(pd,D+1)rep(qd,D+1) ans += dp[pd][qd];
    cout << ans.val() << endl;

    // rep(pd,D+1){
    //     rep(qd,D+1){
    //         cout << dp[pd][qd].val() << " ";
    //     }
    //     cout << endl;
    // }



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
