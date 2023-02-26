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

//using mint = modint1000000007;
using mint = modint998244353;


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

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll H,W;
        cin >> H >> W;

        vvec(bool) vv(H,vec(bool)(W)); // Y:true;
        rep(i,H){
            string S;
            cin >> S;
            rep(j,W) vv[i][j] = (S[j]=='Y');
        }

        vvec(mint) dp0(H,vec(mint)(W));
        vvec(mint) dp1(H,vec(mint)(W));
        vvec(mint) dp2(H,vec(mint)(W));

        dp0[0][0] = 1;
        
        rep(i,H)rep(j,W){
            if(i>0){
                ll ii=i-1, jj=j;
                ll tmp = 0;
                if(vv[ii][jj] && vv[i][j]) tmp = 1;
                dp2[i][j] += dp2[ii][jj] + tmp*(2*dp1[ii][jj] + dp0[ii][jj]);
                dp1[i][j] += dp1[ii][jj] + tmp*dp0[ii][jj];
                dp0[i][j] += dp0[ii][jj];
            }
            if(j>0){
                ll ii=i, jj=j-1;
                ll tmp = 0;
                if(vv[ii][jj] && vv[i][j]) tmp = 1;
                dp2[i][j] += dp2[ii][jj] + tmp*(2*dp1[ii][jj] + dp0[ii][jj]);
                dp1[i][j] += dp1[ii][jj] + tmp*dp0[ii][jj];
                dp0[i][j] += dp0[ii][jj];
            }
        }

        cout << dp2[H-1][W-1].val() << endl;

        // vector<vector<map<ll,mint>>> dp(H,vector<map<ll,mint>>(W));
        // dp[0][0][0]=1;

        // rep(i,H)rep(j,W){
        //     if(i>0){
        //         ll tmp = 0;
        //         if(vv[i-1][j] && vv[i][j]) tmp = 1;
        //         for(auto mi:dp[i-1][j]) dp[i][j][mi.first+tmp] += mi.second;
        //     }
        //     if(j>0){
        //         ll tmp = 0;
        //         if(vv[i][j-1] && vv[i][j]) tmp = 1;
        //         for(auto mi:dp[i][j-1]) dp[i][j][mi.first+tmp] += mi.second;
        //     }
        // }

        // mint ans = 0;
        // for(auto mi:dp[H-1][W-1]) ans += mi.first*mi.first*mi.second;
        // cout << ans.val() << endl;

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
