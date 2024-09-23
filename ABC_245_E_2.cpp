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
    ll N,M;
    cin >> N >> M;
    vec(ll) A(N),B(N),C(M),D(M);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    rep(i,M) cin >> C[i];
    rep(i,M) cin >> D[i];

    vec(Pll) c,b;
    rep(i,N){
        ll h = A[i], w = B[i];
        // if(h<w) swap(h,w);
        c.emplace_back(h,w);
    }
    rep(i,M){
        ll h = C[i], w = D[i];
        // if(h<w) swap(h,w);
        b.emplace_back(h,w);
    }

    set<ll> st;
    for(auto [h,_]:c) st.insert(h);
    for(auto [h,_]:b) st.insert(h);
    map<ll,ll> mp;
    ll nn = 0;
    for(auto h:st) mp[h] = nn++;

    vvec(ll) vvc(nn),vvb(nn);
    for(auto [h,w]:c){
        vvc[mp[h]].push_back(w);
    }
    for(auto [h,w]:b){
        vvb[mp[h]].push_back(w);
    }


    multiset<ll> ms;
    repr(i,nn){
        for(auto w:vvb[i]){
            ms.insert(w);
        }
        for(auto w:vvc[i]){
            auto it = ms.lower_bound(w);
            if(it==ms.end()) sayno;
            ms.erase(it);
        }
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
