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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,a,b;
    edge(ll to=0, ll a=0, ll b=0):to(to),a(a),b(b){}
};



void solve(){
    ll n,m,s,t;
    cin >> n >> m >> s >> t;
    --s; --t;

    vvec(edge) g(n);
    rep(_,m){
        ll u,v,a,b;
        cin >> u >> v >> a >> b;
        --u; --v;
        g[u].emplace_back(v,a,b);
        g[v].emplace_back(u,a,b);
    }


    vec(ll) dp(n,llINF);


    priority_queue<Pll, vector<Pll>, greater<Pll>> q;
    auto qpush = [&](ll c,ll x){
        if(chmin(dp[x],c)) q.emplace(c,x);
    };
    
    qpush(0,s);
    while(!q.empty()){
        auto [c0,now] = q.top(); q.pop();
        if(c0 > dp[now]) continue;
        for(edge e:g[now]) qpush(c0+e.a, e.to);
    }

    vec(ll) dps(n,llINF);
    swap(dp,dps);

    qpush(0,t);
    while(!q.empty()){
        auto [c0,now] = q.top(); q.pop();
        if(c0 > dp[now]) continue;
        for(edge e:g[now]) qpush(c0+e.b, e.to);
    }

    vec(ll) dpt(n);
    swap(dp,dpt);

    vec(ll) ans(n);
    ll mincost = llINF;

    // rep(i,n) cout << dps[i] << " "; cout << endl;
    // rep(i,n) cout << dpt[i] << " "; cout << endl;

    repr(i,n){
        chmin(mincost, dps[i]+dpt[i]);
        ans[i] = 1e15 - mincost;
    }

    rep(i,n) cout << ans[i] << endl;












}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
