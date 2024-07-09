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


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll H,W;
    cin >> H >> W;

    vvec(ll) vv(H,vec(ll)(W));
    rep(i,H){
        string s;
        cin >> s;
        rep(j,W) vv[i][j] = (s[j]=='#');
    }

    vvec(ll) tot(H+1,vec(ll)(W+1));
    rep1(i,H)rep1(j,W){
        tot[i][j] = tot[i-1][j] + tot[i][j-1] - tot[i-1][j-1] + vv[i-1][j-1];
    }

    auto f = [&](ll h1, ll w1, ll h2, ll w2){
        return tot[h2][w2] - tot[h1][w2] - tot[h2][w1] + tot[h1][w1];
    };


    ll hh=0,ww=0;
    rep(i,H) chmax(ww,f(i,0,i+1,W));
    rep(j,W) chmax(hh,f(0,j,H,j+1));

    ll ansi,ansj;
    rep(i,H) if(f(i,0,i+1,W)==ww-1) ansi = i;
    rep(j,W) if(f(0,j,H,j+1)==hh-1) ansj = j;

    cout << ansi+1 << " " << ansj+1 << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
