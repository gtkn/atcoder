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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------



void solve(){
    ll N,M;
    cin >> N >> M;

    ll st = 0, gl = N+1;
    vvec(Pll) g(N+2);
    rep(_,M){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
    }

    rep1(i,N) g[st].emplace_back(i,0);
    rep1(i,N) g[i].emplace_back(gl,0);

    ll N2 = N+2;
    vvec(ll) dist(N2, vec(ll)(N2,llINF));
    rep(now,N2){
        dist[now][now] = 0;
        for(auto [nxt,w]:g[now]) dist[now][nxt] = w;
    }
    rep(k,N2)rep(i,N2)rep(j,N2){
        if(dist[i][k]>=llINF || dist[k][j]>=llINF) continue;
        chmin(dist[i][j], dist[i][k]+dist[k][j]);
    }


    ll nn = (1<<(N+2));
    vvec(ll) dp(N+2,vec(ll)(nn,llINF));


    dp[st][1]=0;
    rep(hist,nn)rep(now,N2){
        if(!bit(hist,now)) continue;
        if(dp[now][hist]>=llINF) continue;
        rep(nxt,N2){
            if(bit(hist,nxt)) continue;
            if(dist[now][nxt]>=llINF) continue;
            chmin(dp[nxt][hist|(1<<nxt)], dp[now][hist]+dist[now][nxt]);
        }
    }


    // queue<Pll> q;
    // auto qpush = [&](ll cost,ll node, ll hist)->void{
    //     if(chmin(dp[node][hist], cost)) q.emplace(node,hist);
    // };

    // qpush(0,0,1);
    // while(!q.empty()){
    //     auto [now,hist] = q.front();
    //     q.pop();
    //     // for(auto [nxt,w]:g[now]){
    //     //     qpush(dp[now][hist]+w, nxt, hist|(1<<nxt));
    //     // }
    //     rep(nxt,N2){
    //         if(bit(hist,nxt)) continue;
    //         qpush(dp[now][hist]+dist[now][nxt], nxt, hist|(1<<nxt));
    //     }

    // }

    ll ans = dp[gl][nn-1];
    if(ans>=llINF) cout << "No" << endl;
    else cout << ans << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
