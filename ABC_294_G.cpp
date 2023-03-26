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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


ll op(ll a, ll b){ return min(a,b);}
ll ee(){return llINF;}
ll mapping(ll f, ll x){return f+x;}
ll composition(ll f,ll g){return f+g;}
ll id(){return 0;}



struct Solver{
    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };


    ll N;
    vvec(abc) g;
    vec(abc) edge;

    vec(Pll) edge_inout,node_inout;
    vec(ll) hen,dist;

    void dfs(ll now, ll eid, ll d){
        edge_inout[eid].first = hen.size();
        node_inout[now].first = hen.size();
        hen.push_back(eid);
        dist.push_back(d);

        for(abc gi:g[now]){
            if(gi.b==eid) continue;
            dfs(gi.a, gi.b, d+gi.c);
        }

        edge_inout[eid].second = hen.size();
        node_inout[now].second = hen.size();
        hen.push_back(-eid);
        dist.push_back(d - edge[eid].c);
    }




    void solve(){
        cin >> N;
        g.resize(N);
        edge.resize(N);
        edge_inout.resize(N);
        node_inout.resize(N);

        rep1(i,N-1){
            ll u,v,w;
            cin >> u >> v >> w;
            u--;v--;
            edge[i] = abc(u,v,w);
            g[u].emplace_back(v,i,w);
            g[v].emplace_back(u,i,w);
        }

        dfs(0,0,0);

        // rep(i,hen.size()) cout << hen[i] <<" , " << dist[i] << endl;
        // rep(i,N) cout << i << " : " << node_inout[i].first << " , " << node_inout[i].second << " / " << edge_inout[i].first << " , " << edge_inout[i].second << endl;

        lazy_segtree<ll, op, ee, ll, mapping, composition, id> ls(dist);


        ll Q;
        cin >> Q;
        while(Q--){
            ll t,a,b;
            cin >> t >> a >> b;
            if(t==1){
                ls.apply(edge_inout[a].first, edge_inout[a].second, b-edge[a].c);
                edge[a].c = b;
            }else{
                a--; b--;
                ll res = 0;
                res += ls.get(node_inout[a].first);
                res += ls.get(node_inout[b].first);
                res -= 2*ls.prod(min(node_inout[a].first, node_inout[b].first), max(node_inout[a].second, node_inout[b].second)  );

                // cout << ls.get(node_inout[a].first) <<" , " << ls.get(node_inout[b].first) << " , " << ls.prod(min(node_inout[a].first, node_inout[b].first), max(node_inout[a].second, node_inout[b].second)  ) << endl;

                cout << res << endl;

            }
        }


        


    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
