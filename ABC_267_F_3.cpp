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

Pll calcTreeDiameter(const vvec(ll)& g){
    ll n = g.size();


    ll st = 0, gl=0;
    vec(ll) dist(n,llINF);
    rep(_,2){
        swap(st,gl);

        // stから一番遠いところをglにする
        rep(i,n) dist[i]=llINF;
        dist[st]=0;
        queue<ll> q;
        q.push(st);
        dist[st]=0;
        while(!q.empty()){
            ll now = q.front();
            q.pop();
            for(ll nxt:g[now]) if(chmin(dist[nxt], dist[now]+1)) q.push(nxt);
        }
        ll dmax = 0;
        rep(i,n) if(chmax(dmax,dist[i])) gl = i;
    }

    // vec(ll) path = {gl};
    // ll now = gl;
    // while(now!=st){
    //     for(ll nxt:g[now]){
    //         if(dist[nxt]+1==dist[now]){
    //             path.push_back(nxt);
    //             now = nxt;
    //             break;
    //         }
    //     }
    // }
    // return path;
    return {st,gl};
}



// LCA tekina
struct LCA{
    ll N,ln;
    vvec(ll) g;
    vvec(ll) par;
    vec(ll) dep;

    void _dfs(ll now,ll frm){
        par[now][0] = frm;
        dep[now] = dep[frm]+1;

        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            _dfs(nxt,now);
        }
    }


    LCA(vvec(ll) _g, ll rt = 0){
        g = _g;
        N = g.size();
        ln = log2(N) + 1;
        dep.resize(N);
        par = vvec(ll)(N,vec(ll)(ln));

        dep[rt] = -1;
        _dfs(rt,rt);

        rep(j,ln){
            if(j==0) continue;
            rep(i,N) par[i][j] = par[ par[i][j-1] ][j-1];
        }
    }


    ll get_dist(ll a,ll b){
        return dep[a] + dep[b] - 2*dep[get_lca(a,b)];
    }

    ll get_lca(ll a,ll b){
        if(dep[a]<dep[b]) swap(a,b);
        ll dd=dep[a]-dep[b];
        ll ex=0;
        while(dd){
            if(dd&1) a = par[a][ex];
            dd >>= 1;
            ex++;
        }

        if(a==b) return(a);
        repr(i,ln){
            if(par[a][i]==par[b][i]) continue;
            a = par[a][i];
            b = par[b][i];
        }
        return par[a][0];
    }

    ll get_ancient(ll a,ll d){
        if(dep[a]<d) return -1;

        ll res = a;
        repr(i,ln){
            if(bit(d,i)) res = par[res][i];
        }
        return res;
    }


};




void solve(){
    ll N;
    cin >> N;

    vvec(ll) g(N);
    rep(_,N-1){
        ll a,b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    auto [r0,r1] = calcTreeDiameter(g);

    LCA lca0(g,r0), lca1(g,r1);

    ll Q;
    cin >> Q;
    while(Q--){
        ll u,k;
        cin >> u >> k;
        --u;

        ll res = -1;
        chmax(res, lca0.get_ancient(u,k));
        chmax(res, lca1.get_ancient(u,k));
        if(res>=0) res++;
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
