//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
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
using Pii = pair<int,int>;
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

struct Solver{

    ll N, Q;
    vvec(ll) q;
    vvec(tri) g;
    vec(ll) ans;
    // vvec(ll) memo;
    vec(set<ll>) memo;


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


    vec(ll) used_cnt, dist_col;
    ll tot = 0;


    void dfs(ll now,ll frm){
        for(ll idx:memo[now]){
            ll res = tot;
            ll x = q[idx][0];
            res -= dist_col[x];
            res += used_cnt[x]*q[idx][1];

            // if(idx==2) cout << res << " ! " << endl;

            if(q[idx][2]==now) ans[idx] += res;
            if(q[idx][3]==now) ans[idx] += res;
            if(q[idx][4]==now) ans[idx] -= 2*res;
        }


        for(auto gi:g[now]){
            ll nxt,col,dist;
            tie(nxt,col,dist) = gi;
            if(nxt==frm) continue;

            used_cnt[col]++;
            dist_col[col]+=dist;
            tot+=dist;
            dfs(nxt,now);
            used_cnt[col]--;
            dist_col[col]-=dist;
            tot-=dist;
        }

    }






    void solve(){
        cin >> N >> Q;
        g.resize(N);
        q.resize(Q);
        ans.resize(Q);
        memo.resize(N);
        used_cnt.resize(N+1);
        dist_col.resize(N+1);


        vvec(ll) gg(N);
        

        rep(_,N-1){
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            a--; b--;
            g[a].emplace_back(b,c,d);
            g[b].emplace_back(a,c,d);
            gg[a].push_back(b);
            gg[b].push_back(a);
        }


        LCA lca(gg);


        rep(i,Q){
            ll x,y,u,v;
            cin >> x >> y >> u >> v;
            u--; v--;
            ll w = lca.get_lca(u,v);
            q[i] = {x,y,u,v,w};
            // cout << u <<" , " << v << " , " << w << endl;
            // memo[u].push_back(i);
            // memo[v].push_back(i);
            // memo[w].push_back(i);
            memo[u].insert(i);
            memo[v].insert(i);
            memo[w].insert(i);
        }

        dfs(0,0);

        for(ll ai:ans) cout << ai << endl;





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
