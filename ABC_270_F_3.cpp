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
    ll frm,to,cost;
    edge(ll frm=0, ll to=0, ll cost=0):frm(frm),to(to),cost(cost){}
};

// 頂点数n, 辺の集合eの最小全域木を求める
// 頂点は0~n
ll MinCostTree(ll n, vec(edge) e){
    sort(all(e),[](const edge& a, const edge& b){
        return a.cost < b.cost;
    });

    dsu uf(n);
    ll res = 0;

    for(const auto& ei: e){
        if(uf.same(ei.frm,ei.to)) continue;
        uf.merge(ei.frm,ei.to);
        res += ei.cost;
    }

    if(uf.groups().size()!=1) res = llINF;
    return res;
}




void solve(){
    ll N,M;
    cin >> N >> M;
    vec(ll) X(N),Y(N);
    rep(i,N) cin >> X[i];
    rep(i,N) cin >> Y[i];
    vec(edge) v;
    rep(_,M){
        ll a,b,z;
        cin >> a >> b >> z;
        a--; b--;
        v.emplace_back(a,b,z);
    }


    ll ans = llINF;
    {
        chmin(ans,MinCostTree(N,v));
        cerr << "0 : " << ans << endl;
    }
    {
        vec(edge) e = v;
        rep(i,N) e.emplace_back(i,N,X[i]);
        chmin(ans,MinCostTree(N+1,e));
        cerr << "1 : " << ans << endl;
    }
    {
        vec(edge) e = v;
        rep(i,N) e.emplace_back(i,N,Y[i]);
        chmin(ans,MinCostTree(N+1,e));
        cerr << "2 : " << ans << endl;
    }
    {
        vec(edge) e = v;
        rep(i,N) e.emplace_back(i,N,X[i]);
        rep(i,N) e.emplace_back(i,N+1,Y[i]);
        chmin(ans,MinCostTree(N+2,e));
        cerr << "3 : " << ans << endl;
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
