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
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];

    vec(ll) a(N);
    rep(i,N) a[i] = (M-A[i])%M; 

    set<ll> st;
    rep(i,N) st.insert(a[i]);
    rep(i,N) st.insert(B[i]);
    map<ll,ll> mp;
    ll nn = 0;
    for(auto p: st) mp[p] = nn++;
    vec(ll) v;
    for(auto p: st) v.push_back(p);

    vvec(Pll) g(N+nn);
    rep(i,N) g[i].emplace_back( N + mp[a[i]], 0 );
    rep(i,N) g[N + mp[B[i]] ].emplace_back(i, 0);
    rep(i,nn-1) g[N+i].emplace_back(N+i+1, v[i+1]-v[i]);
    g[N+nn-1].emplace_back(N, M + v[0] - v[nn-1]);

    vec(ll) dist(N+nn,llINF);
    dist[0] = 0;
    priority_queue<Pll,vector<Pll>,greater<Pll>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto [d,v] = pq.top(); pq.pop();
        if(dist[v] < d) continue;
        for(auto [nv,c] : g[v]){
            if(chmin(dist[nv],d+c)){
                pq.push({dist[nv],nv});
            }
        }
    }

    ll ans = dist[N-1];
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
