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

    struct edge{
        ll to,c,t;
        edge(ll to=0, ll c=0, ll t=0):to(to),c(c),t(t){}
    };


 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,M,S;
        cin >> N >> M >> S;
        ll XX = 5050;
        chmin(S,XX);

        vvec(edge) g(N);
        rep(_,M){
            ll u,v,a,b;
            cin >> u >> v >> a >> b;
            u--; v--;
            g[u].emplace_back(v,a,b);
            g[v].emplace_back(u,a,b);
        }

        vec(ll) C(N),D(N);
        rep(i,N) cin >> C[i] >> D[i];


        vvec(ll) dp(N+10,vec(ll)(XX+10,llINF));
        queue<edge> q;
        auto qpush = [&](ll to,ll c, ll t){
            if(c<0) return;
            if(chmin(dp[to][c],t)){
                //cout << to << "," <<c <<","<<t << endl;
                q.emplace(to,c,t);
            }
        };
        qpush(0,S,0);

        while(!q.empty()){
            edge q0 = q.front();
            q.pop();
            ll now,c0,t0;
            now = q0.to; c0=q0.c; t0=q0.t;
            if(dp[now][c0]<t0) continue;
            for(edge gi:g[now]){
                qpush(gi.to, c0-gi.c, t0+gi.t);
            }
            while(c0<XX){
                qpush(now, c0, t0);
                c0+=C[now];
                t0+=D[now];
            }
        }

        vec(ll) ans(N,llINF);
        rep(i,N)rep(j,XX) chmin(ans[i],dp[i][j]);
        rep1(i,N-1) cout << ans[i] << endl;


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
