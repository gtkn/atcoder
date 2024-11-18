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
    vvec(ll) A(H,vec(ll)(W));
    rep(i,H)rep(j,W) cin >> A[i][j];


    {
        vec(Pll) rng;
        rep(i,H){
            ll amin =llINF, amax = 0;
            rep(j,W){
                if(A[i][j]==0) continue;
                chmin(amin,A[i][j]);
                chmax(amax,A[i][j]);
            }
            rng.emplace_back(amin,amax);
        }
        sort(all(rng));
        rep(i,H-1){
            if(rng[i].second > rng[i+1].first) sayno;
        }
    }
    // cerr << "ok" << endl;

    scc_graph sg(W + H*(W+1));


    ll idx = W;
    rep(i,H){
        map<ll,vector<ll>> mp;
        rep(j,W) if(A[i][j]!=0) mp[A[i][j]].push_back(j);

        vvec(ll) p;
        for(auto [_,js]:mp) p.push_back(js);

        for(const vec(ll) &pi:p){
            for(const ll &x:pi) sg.add_edge(idx,x);
            idx++;
            for(const ll &x:pi) sg.add_edge(x,idx);
        }
        idx++;
    }
    // cerr << idx << endl;

    auto scc = sg.scc();
    for(auto &v:scc){
        if(v.size()>1) sayno;
    }

    sayyes;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
