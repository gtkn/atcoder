//title
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (int i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目
#define vec(T) vector<T>
#define vvec(T) vector<vector<T>>
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
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

//------------------------------------------------

struct Solver{
    

    void solve(){
        ll N,M;
        cin >> N >> M;

        scc_graph graph(N);
        vec(Pll) gr;
        rep(_,M){
            ll u,v;
            cin >> u >> v;
            u--; v--;
            graph.add_edge(u,v);
            gr.emplace_back(v,u);
        }

        vector<vector<int>> vv=graph.scc();
        ll nn = vv.size();
        vec(ll) v(N);
        rep(i, nn){
            for(ll j:vv[i]) v[j]=i;
        }

        vector<set<ll>> g(nn);
        for(Pll ei:gr) g[v[ei.first]].insert(v[ei.second]);

        vec(ll) used(nn);
        queue<ll> q;
        auto qpush = [&](ll to){
            if(used[to]) return;
            used[to] = true;
            q.push(to);
        };

        rep(i,nn) if(vv[i].size()>1) qpush(i);

        while(!q.empty()){
            ll now = q.front();
            q.pop();
            for(ll to:g[now]) qpush(to);
        }

        ll ans = 0;
        rep(i,nn) if(used[i]) ans += vv[i].size();

        cout << ans << endl;
        //rep(i,N) cout << i << " ; " << v[i] << ", " << used[v[i]] << endl;


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
