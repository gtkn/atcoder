//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
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
    

    vvec(ll) gf,gr;
    vec(ll) nn;
    vec(bool) used;

    void dfs1(ll now){
        used[now] = true;
        for(auto to:gf[now]){
            if(used[to]) continue;
            dfs1(to);
        }
        nn.push_back(now);
        return;
    }
 
 
    ll dfs2(ll now){
        ll res = 1;
        used[now] = true;
        for(auto to : gr[now]){
            if(used[to]) continue;
            res += dfs2(to);
        }
        return res;
    }



    void solve(){
        ll N,M;
        cin >> N >> M;

        gf.resize(N);
        gr.resize(N);
        used.resize(N);

        rep(i,M){
            ll u,v;
            cin >> u >> v;
            u--; v--;
            gf[u].push_back(v);
            gr[v].push_back(u);
        }

        
        rep(i,N){
            if(used[i]) continue;
            dfs1(i);
        }
 
        rep(i,N) used[i]=false;
 
        ll ans = 0;
        bool f=false;
        repr(i,N){
            if(used[nn[i]]) continue;
            ll mm = dfs2(nn[i]);
            if(mm>1) f=true;
            if(f) ans += mm;
        }
 
        cout << ans << endl;




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
