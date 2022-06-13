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

//------------------------------------------------

struct Solver{
    ll N;
    vvec(ll) g;
    vvvec(mint) dp;
    //mint dp[2020][2020][5];
    vec(bool) used;


    void dfs(ll now){
        used[now]=true;
        
        dp[now][1][0]=1;
        dp[now][0][1]=1;

        for(ll to:g[now]){
            if(used[to]) continue;
            dfs(to);
    
            ll x = dp[now].size()-1;
            ll y = dp[to].size()-1;

            vvec(mint) dp1(x+y+2,vec(mint)(3));

            rep(j,x+1)rep(jj,y+1){
                dp1[j+jj][0]   += dp[now][j][0]*dp[to][jj][0];
                dp1[j+jj+1][0] += dp[now][j][0]*dp[to][jj][1];
                dp1[j+jj][0]   += dp[now][j][0]*dp[to][jj][2];

                dp1[j+jj+1][2] += dp[now][j][1]*dp[to][jj][0];

                dp1[j+jj][1]   += dp[now][j][1]*dp[to][jj][1];
                dp1[j+jj][1]   += dp[now][j][1]*dp[to][jj][2];

                dp1[j+jj][2]   += dp[now][j][2]*dp[to][jj][0];
                dp1[j+jj][2]   += dp[now][j][2]*dp[to][jj][1];
                dp1[j+jj][2]   += dp[now][j][2]*dp[to][jj][2];

            }
            dp1.pop_back();
            assert(dp[now].size() < dp1.size());
            dp[now] = dp1;
            assert(dp[now].size() == dp1.size());
        }

        //rep(j,dp1.size())rep(k,3) dp[now][j][k] = dp0[j][k];
        //dp[now] = dp0;

    }

  
    void solve(){
        cin >> N;
        g.resize(N);
        used.resize(N);

        dp = vvvec(mint)(N,vvec(mint)(2,vec(mint)(3)));


        rep(_,N-1){
            ll u,v;
            cin >> u >> v;
            u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        //rep(i,2020)rep(j,2020)rep(k,3) dp[i][j][k]=0;

        dfs(0);
        rep(k,N+1){
            mint ans = 0;
            rep(i,3) ans+=dp[0][k][i];
            cout << ans.val() << endl;
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
