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

//------------------------------------------------

struct Solver{
    ll N,M;
    vvec(ll) g;
    vec(Pll) ans1,ans2;
    vec(bool) used;

    void dfs(ll now){
        used[now]=true;
        for(ll to:g[now]){
            if(used[to]) continue;
            ans1.emplace_back(now,to);
            dfs(to);
        }
    }

    void bfs(){
        queue<ll> q;
        q.push(0);
        used[0]=true;
        while(!q.empty()){
            ll now = q.front();
            q.pop();
            for(ll to:g[now]){
                if(used[to]) continue;
                used[to]=true;
                ans2.emplace_back(now,to);
                q.push(to);
            }
        }
    }



 
    void solve(){
        cin >> N >> M;
        g.resize(N);
        rep(_,M){
            ll u,v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        used = vector<bool>(N,false);
        dfs(0);

        used = vector<bool>(N,false);
        bfs();

        assert(ans1.size()==N-1);
        assert(ans2.size()==N-1);

        for(Pll ai:ans1) cout << ai.first+1 << " " << ai.second+1 << endl;
        for(Pll ai:ans2) cout << ai.first+1 << " " << ai.second+1 << endl;

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
