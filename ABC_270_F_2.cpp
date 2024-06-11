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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

// 最小全域木のコストを計算する
ll calc_mincosttree(vec(tri) es, ll n){
    // es: {cost, from, to}

    sort(all(es)); 
    dsu d(n);
    ll res = 0;

    for(auto [c, f, t]:es){
        if(d.same(f, t)) continue;
        d.merge(f, t);
        res += c;
    }

    auto grps = d.groups();
    if(grps.size() > 1) return llINF;
    if(grps[0].size() != n) return llINF;

    return res;
}




void solve(){
    ll N,M;
    cin >> N >> M;

    vec(ll) X(N),Y(N);
    rep(i,N) cin >> X[i];
    rep(i,N) cin >> Y[i];

    vec(ll) A(M),B(M),Z(M);
    rep(i,M) cin >> A[i] >> B[i] >> Z[i];
    rep(i,M) A[i]--, B[i]--;

    ll ans = llINF;
    {// x,y,z
        vec(tri) es;
        rep(i,N) es.emplace_back(X[i], i, N);
        rep(i,N) es.emplace_back(Y[i], i, N+1);
        rep(i,M) es.emplace_back(Z[i], A[i], B[i]);
        ll tmp = calc_mincosttree(es, N+2);
        // cerr << tmp << endl;
        chmin(ans, tmp);
    }
    {// x,z
        vec(tri) es;
        rep(i,N) es.emplace_back(X[i], i, N);
        rep(i,M) es.emplace_back(Z[i], A[i], B[i]);
        ll tmp = calc_mincosttree(es, N+1);
        // cerr << tmp << endl;
        chmin(ans, tmp);
    }
    {// y,z
        vec(tri) es;
        rep(i,N) es.emplace_back(Y[i], i, N);
        rep(i,M) es.emplace_back(Z[i], A[i], B[i]);
        ll tmp = calc_mincosttree(es, N+1);
        // cerr << tmp << endl;
        chmin(ans, tmp);
    }
    {// z
        vec(tri) es;
        rep(i,M) es.emplace_back(Z[i], A[i], B[i]);
        ll tmp = calc_mincosttree(es, N);
        // cerr << tmp << endl;
        chmin(ans, tmp);
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
