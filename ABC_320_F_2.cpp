//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N,H;
    cin >> N >> H;
    vec(ll) X(N+1);
    rep1(i,N) cin >> X[i];
    vec(ll) P(N),F(N);
    rep1(i,N-1) cin >> P[i] >> F[i];


    vec(ll) dist(N);
    rep(i,N) dist[i] = X[i+1]-X[i];

    vvvec(ll) dp(N+1,vvec(ll)(H+1,vec(ll)(H+1,llINF)));
    rep(i,H+1) dp[N][i][i] = 0;


    repr(i,N){
        rep(bef,H+1){
            // 行きに使う
            if(dist[i] <= min(bef+F[i],H)){
                ll bef2 = min(bef+F[i],H) - dist[i];
                rep(aft2,H+1){
                    if(aft2 < dist[i]) continue;
                    ll aft = aft2-dist[i];
                    chmin(dp[i][bef][aft], dp[i+1][bef2][aft2]+P[i]);
                }
            }
            // 行きに使わない
            if(dist[i] <= bef){
                ll bef2 = bef - dist[i];
                rep(aft2,H+1){
                    if(aft2 < dist[i]) continue;
                    ll aft = aft2-dist[i];
                    // 帰りに使わない
                    chmin(dp[i][bef][aft], dp[i+1][bef2][aft2]);
                    // 帰りに使う
                    aft = min(aft+F[i],H);
                    chmin(dp[i][bef][aft], dp[i+1][bef2][aft2]+P[i]);
                }
            }
        }
    }

    ll ans = llINF;
    rep(aft,H+1) chmin(ans, dp[0][H][aft]);
    if(ans>=llINF) ans = -1;
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
