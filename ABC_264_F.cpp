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

        vec(ll) R(H),C(W);
        rep(i,H) cin >> R[i];
        rep(i,W) cin >> C[i];

        vvec(bool) vv(H,vec(bool)(W));
        rep(i,H){
            string s;
            cin >> s;
            rep(j,W) vv[i][j] = (s[j]=='1');
        }

        vvvec(ll) dp(H,vvec(ll)(W,vec(ll)(4,llINF)));
        dp[0][0][0]=0;
        dp[0][0][1]=R[0];
        dp[0][0][2]=C[0];
        dp[0][0][3]=R[0]+C[0];

        rep(i,H)rep(j,W)rep(k,4){
            //cout << i << ", " << j << " , " << k << endl;

            if(i<H-1){
                bool x = vv[i][j];
                if(k&1) x=!x;

                if(x==vv[i+1][j]) chmin(dp[i+1][j][ (k&2) ], dp[i][j][k]);
                else chmin(dp[i+1][j][(k&2)|1], dp[i][j][k]+R[i+1] );
            }
            
            if(j<W-1){
                bool x = vv[i][j];
                if(k&2) x=!x;

                if(x==vv[i][j+1]) chmin(dp[i][j+1][ (k&1) ], dp[i][j][k]);
                else chmin(dp[i][j+1][(k&1)|2], dp[i][j][k]+C[j+1] );
            }
        }

        ll ans = llINF;
        rep(k,4) chmin(ans,dp[H-1][W-1][k]);

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
