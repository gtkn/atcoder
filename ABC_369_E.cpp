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

    vec(ll) U(M),V(M),T(M);
    rep(i,M){
        cin >> U[i] >> V[i] >> T[i];
        U[i]--; V[i]--;
    }

    vvec(Pll) g(N);
    rep(i,M){
        g[U[i]].push_back({V[i],T[i]});
        g[V[i]].push_back({U[i],T[i]});
    }

    vvec(ll) dist(N,vec(ll)(N,llINF));
    rep(i,N) dist[i][i] = 0;
    rep(i,M) chmin(dist[U[i]][V[i]],T[i]);
    rep(i,M) chmin(dist[V[i]][U[i]],T[i]);

    rep(k,N)rep(i,N)rep(j,N) chmin(dist[i][j],dist[i][k]+dist[k][j]);

    // rep(i,N){
    //     rep(j,N) cerr << dist[i][j] << " ";
    //     cerr << endl;
    // }


    ll Q;
    cin >> Q;

    while(Q--){
        ll K; cin >> K;
        vec(ll) B(K);
        rep(i,K) cin >> B[i];
        rep(i,K) B[i]--;
        vec(ll) perm(K);
        rep(i,K) perm[i] = i;

        ll k2 = (1<<K);
        ll res = llINF;
        do{
            rep(ptn,k2){
                ll tmp = 0;
                ll now = 0;
                rep(i,K){
                    ll ui = U[B[perm[i]]], vi = V[B[perm[i]]];
                    if(bit(ptn,i)) swap(ui,vi);
                    tmp += dist[now][ui];
                    tmp += T[B[perm[i]]];
                    now = vi;
                }
                tmp += dist[now][N-1];
                chmin(res,tmp);
            }        
        }while(next_permutation(all(perm)));

        cout << res << endl;

    }

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
