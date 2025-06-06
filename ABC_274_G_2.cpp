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
    ll H, W;
    cin >> H >> W;

    vec(string) S(H);
    rep(i,H) cin >> S[i];

    vvec(bool) ss(H,vec(bool)(W));
    rep(i,H)rep(j,W){
        if(S[i][j]=='#') ss[i][j] = true;
    }


    auto id = [&](ll h, ll w){
        return h*W+w;
    };


    vvec(ll) x(H,vec(ll)(W)), y(H,vec(ll)(W));
    ll hw = H*W;

    rep(i,H)rep(j,W){
        if(ss[i][j]) continue;

        // 下
        if(i==0 || ss[i-1][j]){
            ll cpos = id(i,j)+hw;
            for(ll ii=i; ii<H; ++ii){
                x[ii][j] = cpos;
            }
        }

        // 右
        if(j==0 || ss[i][j-1]){
            ll cpos = id(i,j)+hw*2;
            for(ll jj=j; jj<W; ++jj){
                y[i][jj] = cpos;
            }
        }
    }


    ll nn = 2 + hw*3;
    ll st = hw*3, gl = hw*3+1;
    mf_graph<ll> g(nn);


    rep(i,H)rep(j,W){
        if(ss[i][j]) continue;

        g.add_edge(st, id(i,j)+hw, 1);
        g.add_edge(id(i,j)+hw*2, gl, 1);
        g.add_edge(x[i][j], y[i][j], llINF);
    }



    ll ans = g.flow(st,gl);
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
