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
// using mint = modint;
// mint::set_mod(P);


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
    vec(string) S(H);
    rep(i,H) cin >> S[i];

    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    A--; B--; C--; D--;

    vvec(ll) dp(H,vec(ll)(W,llINF));
    priority_queue<tri,vector<tri>,greater<tri>> pq;
    auto isin = [&](ll h, ll w)->bool{
        return (h>=0 && h<H && w>=0 && w<W);
    };
    auto push = [&](ll c, ll h, ll w)->void{
        if(!isin(h,w)) return;  
        if(chmin(dp[h][w],c)){
            pq.emplace(c,h,w);
        }
    };
    push(0,A,B);

    while(!pq.empty()){
        auto [c,h,w] = pq.top(); pq.pop();
        if(c > dp[h][w]) continue;
        rep(i,4){
            auto [dh,dw] = dhw[i];
            if(!isin(h+dh,w+dw)) continue;
            if(S[h+dh][w+dw] == '.'){
                push(c,h+dh,w+dw);
            }else{
                rep1(j,2) push(c+1,h+j*dh,w+j*dw);
            }
        }
    }


    ll ans = dp[C][D];
    cout << ans << nl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
