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

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll H,W;
        cin >> H >> W;

        vvec(ll) A(H,vec(ll)(W));
        rep(i,H)rep(j,W) cin >> A[i][j];
        vvec(ll) B(H,vec(ll)(W));
        rep(i,H)rep(j,W) cin >> B[i][j];

        vvec(ll) D(H,vec(ll)(W));
        rep(i,H)rep(j,W) D[i][j] = A[i][j] - B[i][j];

        ll z = 80*80*2;
        ll nn = z*2+1;

        vvvec(bool) dp(H,vvec(bool)(W,vec(bool)(nn)));
        dp[0][0][z+D[0][0]] = true;
        dp[0][0][z-D[0][0]] = true;

        rep(h,H)rep(w,W){
            rep(k,nn){
                if(!dp[h][w][k]) continue;
                if(h+1<H){
                    dp[h+1][w][k+D[h+1][w]] = true;
                    dp[h+1][w][k-D[h+1][w]] = true;
                }
                if(w+1<W){
                    dp[h][w+1][k+D[h][w+1]] = true;
                    dp[h][w+1][k-D[h][w+1]] = true;
                }
            }
        }

        ll ans = llINF;
        rep(k,nn) if(dp[H-1][W-1][k]) chmin(ans, abs(k-z) );
        cout << ans << endl;



        // vvec(vector<ll>) dp(H,vec(vector<ll>)(W));
        // dp[0][0].push_back(D[0][0]);
        // dp[0][0].push_back(-D[0][0]);

        // rep(h,H)rep(w,W){
        //     unique(all(dp[h][w]));
        //     if(h+1<H){
        //         for(ll now:dp[h][w]){
        //             dp[h+1][w].push_back(now+D[h+1][w]);
        //             dp[h+1][w].push_back(now-D[h+1][w]);
        //         }
        //     }
        //     if(w+1<W){
        //         for(ll now:dp[h][w]){
        //             dp[h][w+1].push_back(now+D[h][w+1]);
        //             dp[h][w+1].push_back(now-D[h][w+1]);
        //         }
        //     }
        // }

        // ll ans = llINF;
        // for(ll now:dp[H-1][W-1]) chmin(ans, abs(now));
        // cout << ans << endl;

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
