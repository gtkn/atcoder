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




void solve(){
    ll N,M;
    cin >> N >> M;

    vec(ll) A(M),B(M),C(M);
    rep(i,M) cin >> A[i] >> B[i] >> C[i];
    rep(i,M) --A[i], --B[i];

    vvec(Pll) g(N);
    rep(i,M){
        ll a = A[i], b = B[i], c = C[i];
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);        
    }

    vvec(ll) dist(N,vec(ll)(N,llINF));
    rep(i,N) dist[i][i] = 0;
    rep(i,M) dist[A[i]][B[i]] = dist[B[i]][A[i]] = C[i];

    rep(k,N)rep(i,N)rep(j,N) chmin(dist[i][j],dist[i][k]+dist[k][j]);

    ll ans = 0;
    rep(i,M){
        bool isok = false;
        rep(k,N){
            if(k==A[i] || k==B[i]) continue;
            if(dist[A[i]][k]+dist[k][B[i]] <= C[i]){
                isok = true;
            }
        }
        if(isok) ans++;
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
