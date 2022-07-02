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

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    ll N,K;
    mint dp[1010][3][55];
    vec(bool) used;
    vvec(ll) g;


    void dfs(ll now,ll frm){

        ll C = g[now].size();
        if(now!=frm) C--;

        mint x[C+1][3][55];
        rep(i,C+1)rep(j,3)rep(k,55) x[i][j][k]=0;
        x[0][0][0]=1;

        ll cnt = 0;
        for(ll to:g[now]){
            if(to==frm) continue;
            dfs(to, now);

            rep(k,55){
                rep(kk,55){
                    if(k+kk<=K) x[cnt+1][0][k+kk] += x[cnt][0][k] * dp[to][0][kk];
                    if(k+kk<=K) x[cnt+1][0][k+kk] += x[cnt][0][k] * dp[to][1][kk];
                    if(k+kk<=K) x[cnt+1][0][k+kk] += x[cnt][0][k] * dp[to][2][kk];

                    if(k+kk+1<=K) x[cnt+1][1][k+kk+1] += x[cnt][0][k] * dp[to][0][kk];
                    if(k+kk<=K) x[cnt+1][1][k+kk] += x[cnt][0][k] * dp[to][1][kk];

                    if(k+kk<=K) x[cnt+1][1][k+kk] += x[cnt][1][k] * dp[to][0][kk];
                    if(k+kk<=K) x[cnt+1][1][k+kk] += x[cnt][1][k] * dp[to][1][kk];
                    if(k+kk<=K) x[cnt+1][1][k+kk] += x[cnt][1][k] * dp[to][2][kk];

                    if(k+kk<=K) x[cnt+1][2][k+kk] += x[cnt][1][k] * dp[to][0][kk];
                    if(k+kk-1<=K && k+kk-1>=0) x[cnt+1][2][k+kk-1] += x[cnt][1][k] * dp[to][1][kk];

                    if(k+kk<=K) x[cnt+1][2][k+kk] += x[cnt][2][k] * dp[to][0][kk];
                    if(k+kk<=K) x[cnt+1][2][k+kk] += x[cnt][2][k] * dp[to][1][kk];
                    if(k+kk<=K) x[cnt+1][2][k+kk] += x[cnt][2][k] * dp[to][2][kk];
                }
            }
            cnt++;
        }

        rep(j,3)rep(k,55) dp[now][j][k] = x[C][j][k];

        return;
    }




    void solve(){
        cin >> N >> K;
        used.resize(N);
        g.resize(N);
        rep(i,1010)rep(j,3)rep(k,55) dp[i][j][k]=0;

        rep(_,N-1){
            ll a,b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs(0,0);
        mint ans = 0;
        rep(j,3) ans += dp[0][j][K];
        cout << ans.val() << endl;


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
