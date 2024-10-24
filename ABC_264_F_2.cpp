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
    ll H,W;
    cin >> H >> W;
    vec(ll) R(H),C(W);
    rep(i,H) cin >> R[i];
    rep(i,W) cin >> C[i];
    vvec(bool) A(H,vec(bool)(W));
    rep(i,H){
        string s;
        cin >> s;
        rep(j,W) A[i][j] = (s[j]=='1');        
    }

    ll ans = llINF;


    rep(ptn,4){
        vvvec(ll) dp(H,vvec(ll)(W,vec(ll)(4,llINF)));
        dp[0][0][ptn] = 0;
        if(ptn&1) dp[0][0][ptn] += R[0];
        if(ptn&2) dp[0][0][ptn] += C[0];

        rep(i,H)rep(j,W)rep(k,4){
            if(i+1<H){
                ll d = 0;
                ll kk = (k&2);
                bool b = false;
                if(k&1){
                    if(A[i][j] == A[i+1][j]) b = true;
                }else{
                    if(A[i][j] != A[i+1][j]) b = true;
                }
                if(b){
                    d = R[i+1];
                    kk |= 1;
                }
                chmin(dp[i+1][j][kk],dp[i][j][k]+d);
            }
            if(j+1<W){
                ll d = 0;
                ll kk = (k&1);
                bool b = false;
                if(k&2){
                    if(A[i][j] == A[i][j+1]) b = true;
                }else{
                    if(A[i][j] != A[i][j+1]) b = true;
                }
                if(b){
                    d = C[j+1];
                    kk |= 2;
                }
                chmin(dp[i][j+1][kk],dp[i][j][k]+d);
            }
        }
        rep(k,4) chmin(ans,dp[H-1][W-1][k]);
    }

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
