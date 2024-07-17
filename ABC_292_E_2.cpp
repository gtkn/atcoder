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
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N,M;
    cin >> N >> M;



    vvec(ll) gf(N),gr(N);
    rep(_,M){
        ll u,v;
        cin >> u >> v;
        --u,--v;
        gf[u].push_back(v);
        gr[v].push_back(u);
    }

    auto f = [&](auto f, ll st)->ll{
        vec(bool) used(N);
        queue<ll> q;
        q.push(st);
        ll res = 0;
        while(!q.empty()){
            ll now = q.front(); q.pop();
            if(used[now]) continue;
            used[now] = true;
            res++;
            for(ll nxt:gf[now]) q.push(nxt);
        }
        res--;
        return res;
    };

    ll ans = -M;
    rep(i,N) ans += f(f,i);
    cout << ans << endl;







    // vvec(ll) g(N);
    // rep(_,M){
    //     ll u,v;
    //     cin >> u >> v;
    //     --u,--v;
    //     g[u].push_back(v);
    // }

    // scc_graph sccg(N);
    // rep(i,N)for(ll j:g[i]) sccg.add_edge(i,j);

    // auto scc = sccg.scc();
    // ll nn = scc.size();

    // ll cnt = 0;
    // vec(ll) idx(N), sz(nn);
    // rep(i,nn){
    //     sz[i] = scc[i].size();
    //     cnt += sz[i]*(sz[i]-1)/2;
    //     for(ll j:scc[i]) idx[j] = i;
    // }

    // // cerr << nn << " " << cnt << endl;
    // // rep(i,N) cerr << idx[i] << " "; cerr << endl;

    // vector<set<ll>> gf(nn),gr(nn);
    // rep(i,N)for(ll j:g[i]){
    //     // cerr << i << " " << j << " : " << idx[i] << " " << idx[j] << endl;
    //     gf[idx[i]].insert(idx[j]);
    //     gr[idx[j]].insert(idx[i]);
    // }
    // // cerr << "ok?" << endl;

    // vec(ll) incnt(nn), outcnt(nn);
    // rep(i,nn) incnt[i] = gr[i].size();
    // rep(i,nn) outcnt[i] = gf[i].size();

    // vec(ll) dp0(nn),dp1(nn);

    // rep(_,2){
    //     queue<ll> q;
    //     rep(i,nn) if(incnt[i]==0) q.push(i);

    //     while(!q.empty()){
    //         ll now = q.front(); q.pop();
    //         for(ll nxt:gf[now]){
    //             dp0[nxt] += dp0[now]+sz[now];
    //             incnt[nxt]--;
    //             if(incnt[nxt]==0) q.push(nxt);
    //         }
    //     }

    //     swap(incnt,outcnt);
    //     swap(dp0,dp1);
    //     swap(gf,gr);
    // }

    // rep(i,nn) cerr << dp0[i] << " "; cerr << endl;
    // rep(i,nn) cerr << dp1[i] << " "; cerr << endl;



    // rep(i,nn) cnt += dp0[i]*dp1[i];

    // ll ans = cnt - M;
    // cout << ans << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
