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
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(ll) dh = {1,0,-1,0};
    vec(ll) dw = {0,1,0,-1};
 
    void solve(){
        ll N1,N2,M;
        cin >> N1 >> N2 >> M;

        ll N = N1+N2;
        vvec(ll) g(N);
        rep(_,M){
            ll a,b;
            cin >> a >> b;
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }


        vec(ll) dp(N,llINF);
        // auto dfs = [&](auto dfs, ll now, ll dist)->void{
        //     if(dp[now]<=dist) return;
        //     dp[now]=dist;
        //     for(ll nxt:g[now]) dfs(dfs, nxt, dist+1);
        // };

        // dfs(dfs,0,0);
        // dfs(dfs,N-1,0);


        priority_queue<Pll,vector<Pll>,greater<Pll>> q;
        auto qpush = [&](ll dist,ll now){
            if(chmin(dp[now],dist)) q.emplace(dist,now);
        };

        qpush(0,0);
        qpush(0,N-1);
        while(!q.empty()){
            Pll q0 = q.top(); q.pop();
            if(dp[q0.second]<q0.first) continue;
            for(ll nxt:g[q0.second]) qpush(q0.first+1, nxt);
        }



        ll d1=0,d2=0;
        rep(i,N1) chmax(d1,dp[i]);
        for(ll i=N1; i<N; i++) chmax(d2,dp[i]);

        cout << d1+d2+1 << endl;


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
