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

};



void solve(){
    ll N;
    cin >> N;
    vec(ll) P(N+1);
    rep1(i,N) cin >> P[i];

    ll M;
    cin >> M;
    vec(ll) a(M+1),b(M+1);
    rep1(i,M) cin >> a[i] >> b[i];

    vvec(Pll) g(N+1);
    rep1(i,M) g[a[i]].emplace_back(b[i],i);
    rep1(i,M) g[b[i]].emplace_back(a[i],i);

    dsu uf(N+1);
    rep1(i,M) uf.merge(a[i],b[i]);

    auto groups = uf.groups();
    for(auto& group: groups){
        set<ll> s;
        for(auto& v: group) s.insert(v);
        for(auto& v: group) if(!sfind(s,P[v])) dame;
        if(group[0]!=0) g[0].emplace_back(group[0], -1);
    }


    vvec(ll) tree(N+1);
    vec(bool) used(N+1);
    queue<ll> q;
    q.push(0);
    used[0] = true;
    vec(Pll) par(N+1);

    queue<ll> leaf;

    while(!q.empty()){
        ll now = q.front(); q.pop();
        bool is_leaf = true;
        for(auto [nxt,idx]:g[now]){
            if(used[nxt]) continue;
            used[nxt] = true;
            tree[now].push_back(nxt);
            q.push(nxt);
            par[nxt] = {now,idx};
            is_leaf = false;
        }
        if(is_leaf) leaf.push(now);
    }


    vec(ll) pos(N+1);
    rep1(i,N) pos[P[i]] = i;
    vec(ll) ans;


    LCA lca(tree);

    while(!leaf.empty()){
        ll ii = leaf.front(); leaf.pop();
        ll jj = pos[ii];
        ll kk = lca.get_lca(ii,jj);

        if(par[ii].first!=0) leaf.push(par[ii].first);
        // swap(ii,jj);

        vec(ll) memoi,memoj;
        while(ii!=kk){
            memoi.push_back(par[ii].second);
            ii = par[ii].first;
        }
        while(jj!=kk){
            memoj.push_back(par[jj].second);
            jj = par[jj].first;
        }

        vec(ll) memo = memoj;
        reverse(all(memoi));
        for(ll idx:memoi) memo.push_back(idx);

        for(ll idx:memo){
            ans.push_back(idx);
            ll ai = a[idx], bi = b[idx];
            swap(P[ai],P[bi]);
            pos[P[ai]] = ai;
            pos[P[bi]] = bi;

        }
    }

    cout << ans.size() << endl;
    for(ll a:ans) cout << a << " "; cout << endl;
    // rep1(i,N) cerr << P[i] << " "; cerr << endl;


    // auto groups = uf.groups();

    // vec(ll) ans;

    // for(auto& group: groups){
    //     set<ll> s;
    //     for(auto& v: group) s.insert(v);
    //     for(auto& v: group) if(!sfind(s,P[v])) dame;

    //     map<ll,ll> mp;
    //     ll nn = 0;
    //     for(auto& v: group) mp[P[v]] = nn++;

    //     vvec(Pll) g2(nn);
    //     for(auto& v: group){
    //         for(auto& [u,idx]: g[v]){
    //             g2[mp[P[v]]].emplace_back(mp[P[u]], idx);
    //         }
    //     }

    //     vec(ll) pp(nn);
    //     for(auto& v: group) pp[mp[v]] = mp[P[v]];

    //     ll rt = 0;
    //     vec(ll) paredge(nn);
    //     queue<ll> q;
    //     q.push(rt);
    //     vec(bool) visited(nn);
    //     while(!q.empty()){
    //         ll now = q.front(); q.pop();
    //         visited[now] = true;
    //         for(auto& [nxt,idx]: g2[now]){
    //             if(visited[nxt]) continue;
    //             paredge[nxt] = idx;
    //             q.push(nxt);
    //         }
    //     }

    //     vvec(ll) g3(nn);
    //     rep(i,nn)for(auto [j,_]:g2[i]) g3[i].push_back(j);

    //     LCA lca(g3,rt);

    //     rep(i,nn){
    //         ll st = i;
    //         ll gl = pp[i];
    //         if(st==gl) continue;
    //         ll mid = lca.get_lca(st,gl);

    //         vec(ll) tmp, tmp2;
    //         while(st!=mid){
    //             tmp.push_back(paredge[st]);
    //             st = lca.par[st][0];
    //         }
    //         while(gl!=mid){
    //             tmp2.push_back(paredge[gl]);
    //             gl = lca.par[gl][0];
    //         }
    //         reverse(all(tmp2));
    //         for(auto& v: tmp2) tmp.push_back(v);

    //         for(ll idx:tmp){
    //             ans.push_back(idx);
    //             swap(pp[mp[a[idx]]], pp[mp[b[idx]]]);
    //         }
    //     }
    // }

    // cout << ans.size() << endl;
    // for(auto& v: ans) cout << v+1 << " "; cout << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
