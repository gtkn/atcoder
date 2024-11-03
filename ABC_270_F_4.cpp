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
    ll frm,to,c;
    edge(ll frm=0, ll to=0, ll c=0):frm(frm),to(to),c(c){}

    bool operator<(edge e){
        return c<e.c;
    }

};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,M;
    cin >> N >> M;
    vec(ll) X(N),Y(N);
    rep(i,N) cin >> X[i];
    rep(i,N) cin >> Y[i];
    vec(ll) A(M),B(M),Z(M);
    rep(i,M) cin >> A[i] >> B[i] >> Z[i];
    rep(i,M) A[i]--, B[i]--;


    auto f = [](vector<edge> es, ll n)->ll{
        sort(all(es));
        ll res = 0;
        dsu uf(n);
        for(auto e:es){
            if(uf.same(e.frm,e.to)) continue;
            uf.merge(e.frm,e.to);
            res += e.c;
        }

        if(uf.groups().size()!=1) res = llINF;
        return res;
    };



    ll ans = llINF;
    {
        vec(edge) es;
        rep(i,M) es.emplace_back(A[i],B[i],Z[i]);
        chmin(ans, f(es,N));
    }
    {
        vec(edge) es;
        rep(i,M) es.emplace_back(A[i],B[i],Z[i]);
        rep(i,N) es.emplace_back(i,N,X[i]);
        chmin(ans, f(es,N+1));
    }
    {
        vec(edge) es;
        rep(i,M) es.emplace_back(A[i],B[i],Z[i]);
        rep(i,N) es.emplace_back(i,N,Y[i]);
        chmin(ans, f(es,N+1));
    }
        {
        vec(edge) es;
        rep(i,M) es.emplace_back(A[i],B[i],Z[i]);
        rep(i,N) es.emplace_back(i,N,X[i]);
        rep(i,N) es.emplace_back(i,N+1,Y[i]);
        chmin(ans, f(es,N+2));
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
