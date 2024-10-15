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


// Lowlink algorithm to find bridges
struct Lowlink {
    const vvec(edge) &g;
    vec(int) ord, low;
    vec(bool) visited;
    // vec(Pll) bridges;
    vec(ll) bridges;
    int k;

    Lowlink(const vvec(edge) &g) : g(g), ord(g.size(), -1), low(g.size(), -1), visited(g.size(), false), k(0) {
        rep(i, g.size()) if (ord[i] == -1) dfs(i, -1);
    }

    void dfs(ll v, ll p) {
        visited[v] = true;
        ord[v] = low[v] = k++;
        for (auto &e : g[v]) {
            if (e.to == p) continue;
            if (!visited[e.to]) {
                dfs(e.to, v);
                low[v] = min(low[v], low[e.to]);
                // if (ord[v] < low[e.to]) bridges.emplace_back(min(v, e.to), max(v, e.to));
                if (ord[v] < low[e.to]) bridges.emplace_back(e.idx);
            } else {
                low[v] = min(low[v], ord[e.to]);
            }
        }
    }
};





void solve(){
    ll N,M;
    cin >> N >> M;
    vec(ll) A(M),B(M),C(M);
    rep(i,M){
        cin >> A[i] >> B[i] >> C[i];
        --A[i]; --B[i];
    }


    vvec(edge) g(N);
    rep(i,M){
        g[A[i]].emplace_back(B[i],C[i],i);
        g[B[i]].emplace_back(A[i],C[i],i);
    }

    auto f = [&](ll st)->vec(ll){
        vec(ll) dist(N,llINF);
        priority_queue<Pll,vector<Pll>,greater<Pll>> pq;
        if(chmin(dist[st],0LL)) pq.emplace(0,st);

        while(!pq.empty()){
            auto [d,v] = pq.top(); pq.pop();
            if(dist[v]<d) continue;
            for(auto e:g[v]){
                ll nv = e.to, nd = d+e.c;
                if(chmin(dist[nv],nd)) pq.emplace(nd,nv);
            }
        }
        return dist;
    };


    vec(ll) distf = f(0);
    vec(ll) distr = f(N-1);

    vec(bool) cand(M);
    rep(i,M){
        if(distf[A[i]]+C[i]+distr[B[i]]==distr[0]) cand[i] = true;
        if(distf[B[i]]+C[i]+distr[A[i]]==distr[0]) cand[i] = true;
    }


    vvec(edge) g2(N);
    rep(i,M) if(cand[i]){
        g2[A[i]].emplace_back(B[i],C[i],i);
        g2[B[i]].emplace_back(A[i],C[i],i);
    }

    Lowlink lowlink(g2);
    vec(ll) bs = lowlink.bridges;

    vec(bool) ans(M);
    for(auto b:bs) ans[b] = true;
    
    rep(i,M)if(ans[i]) sayyn;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
