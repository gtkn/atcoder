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
    ll N;
    cin >> N;

    vec(ll) a(N),b(N);
    rep(i,N) cin >> a[i];
    rep(i,N) cin >> b[i];

    set<ll> st;
    rep(i,N) st.insert(a[i]);
    rep(i,N) st.insert(b[i]);
    ll nn = 0;
    map<ll,ll> mp;
    for(ll val:st) mp[val] = nn++;

    rep(i,N) a[i] = mp[a[i]];
    rep(i,N) b[i] = mp[b[i]];

    vec(ll) posa(nn,N), posb(nn,N);
    rep(i,N) chmin(posa[a[i]],i);
    rep(i,N) chmin(posb[b[i]],i);

    vvec(ll) p(N+1);
    rep(i,nn) p[posa[i]].push_back(posb[i]);
    // rep(i,nn) cerr << posa[i] << ' ' << posb[i] << endl;


    vec(ll) cx0(N+1), cx1(N+1);
    ll tmp = 0;
    rep(i,N+1){
        for(ll yi:p[i]) chmax(tmp,yi);
        cx0[i] = tmp;
    }

    tmp = N;
    repr(i,N+1){
        for(ll yi:p[i]) chmin(tmp,yi);
        cx1[i] = tmp;
    }


    ll Q;
    cin >> Q;
    vec(ll) x(Q),y(Q);
    rep(i,Q) cin >> x[i] >> y[i];
    rep(i,Q) x[i]--, y[i]--;

    vvec(Pll) z(N);
    rep(i,Q) z[x[i]].emplace_back(y[i],i);

    vec(bool) ans(Q);
    rep(xi,N){
        for(auto [yi,idx]:z[xi]){
            if(yi>=cx0[xi] && yi<cx1[xi+1]) ans[idx] = true;
        }
    }

    rep(i,Q)if(ans[i]) sayyn;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
