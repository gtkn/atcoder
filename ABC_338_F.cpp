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

    vec(ll) U(M),V(M),W(M);
    rep(i,M) cin >> U[i] >> V[i] >> W[i];

    rep(i,M) U[i]--;
    rep(i,M) V[i]--;

    vvec(ll) cost(N,vec(ll)(N,llINF));
    vvec(bool) isok(N,vec(bool)(N));
    rep(i,M) cost[ U[i] ][ V[i] ] = W[i];
    rep(i,M) isok[ U[i] ][ V[i] ] = true;
    

    rep(k,N)rep(i,N)rep(j,N){
        if(isok[i][k] && isok[k][j]){
            chmin(cost[i][j], cost[i][k]+cost[k][j] );
            isok[i][j]=true;
        }
    }


    // rep(i,N){
    //     rep(j,N) cerr << cost[i][j] << " "; cerr << nl;
    // }


    ll nn = (1<<N);
    vvec(ll) dp(nn,vec(ll)(N,llINF));
    rep(i,N) dp[(1<<i)][i] = 0;

    rep(hist,nn)rep(now,N){
        if(!bit(hist,now)) continue;

        rep(nxt,N){
            if(bit(hist,nxt)) continue;
            // if(cost[now][nxt]>=llINF) continue;
            if(!isok[now][nxt]) continue;
            chmin(dp[ hist | (1<<nxt) ][nxt], dp[hist][now] + cost[now][nxt] );
        }
    }

    ll ans = llINF;
    rep(i,N) chmin(ans, dp[nn-1][i]);
    if(ans>=llINF) sayno;

    cout << ans << nl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
