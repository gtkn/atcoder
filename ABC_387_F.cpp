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
    ll N,M;
    cin >> N >> M;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];
    rep(i,N) A[i]--;

    scc_graph g(N);
    rep(i,N) g.add_edge(i,A[i]);

    auto scc = g.scc();
    ll nn = 0;
    vec(ll) ids(N);
    for(auto& v : scc){
        for(auto& u : v){
            ids[u] = nn;
        }
        nn++;
    }

    // rep(i,N) cerr << ids[i] << " "; cerr << endl;


    vector<set<Pll>> g2(nn);
    rep(i,N){
        ll ii = ids[i], jj = ids[A[i]];
        if(ii==jj) continue;
        g2[ii].insert({jj,1});
        g2[jj].insert({ii,0});
    }

    vec(bool) used(nn);
    vvec(mint) dp(nn,vec(mint)(M,1));


    auto f = [&](auto f,ll now, ll frm)->void{
        used[now] = true;
        vec(ll) v0,v1;
        for(auto [nxt,a]:g2[now]){
            if(nxt==frm) continue;
            f(f,nxt,now);
            if(a==0) v0.push_back(nxt);
            else v1.push_back(nxt);
        }

        ll n0 = v0.size();
        ll n1 = v1.size();

        vec(mint) s0(n0),s1(n1);
        rep(i,n1)rep(j,M) s1[i] += dp[v1[i]][j];

        rep(x,M){
            rep(i,n0) s0[i] += dp[v0[i]][x];
            for(mint s:s0) dp[now][x] *= s;
            for(mint s:s1) dp[now][x] *= s;
            rep(i,n1) s1[i] -= dp[v1[i]][x];
        }

        return;
    };


    mint ans = 1;
    rep(st,nn){
        if(used[st]) continue;
        f(f,st,st);
        mint tmp = 0;
        rep(i,M) tmp += dp[st][i];
        ans *= tmp;
    }

    cout << ans.val() << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
