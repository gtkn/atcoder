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

struct Solver{

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


        LCA(vvec(ll) _g){
            g = _g;
            N = g.size();
            ln = log2(N) + 1;
            dep.resize(N);
            par = vvec(ll)(N,vec(ll)(ln));

            dep[0] = -1;
            _dfs(0,0);

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

        vvec(ll) g(N);
        rep(_,N-1){
            ll u,v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        LCA lca(g);

        ll Q;
        cin >> Q;
        while(Q--){
            ll a,b;
            cin >> a >> b;
            
            ll d = lca.get_dist(a-1,b-1);
            cout << d + 1 << endl;
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
