//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (int i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目
#define vec(T) vector<T>
#define vvec(T) vector<vector<T>>
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
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };
 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N;
        cin >> N;
        vec(ll) A(N);
        rep(i,N) cin >> A[i];


        //---ave---
        ll ten = 1000;
        ll l=0,r=1e9*ten+10;
        while(r-l>1){
            ll m=(l+r)/2;
            vvec(ll) dp(N+1,vec(ll)(2,-llINF));
            dp[0][1]=0;
            rep(i,N){
                chmax(dp[i+1][1], dp[i][0]+A[i]*ten-m);
                chmax(dp[i+1][1], dp[i][1]+A[i]*ten-m);
                chmax(dp[i+1][0], dp[i][1]);
            }
            if(max(dp[N][0],dp[N][1]) >= 0) l=m;
            else r=m;
        }
        double ans = 1.*l/ten;
        printf("%.4f\r\n",ans);

        //---med---
        l = 0; r=1e9+10;
        while(r-l>1){
            ll m = (l+r)/2;
            ll cnt=0;
            bool lst = true;
            rep(i,N){
                if(lst){
                    if(A[i]>=m) cnt++;
                    else lst=false;
                }else{
                    if(A[i]>=m) cnt++;
                    else cnt--;
                    lst = true;
                }
            }
            if(cnt>0) l=m;
            else r=m;
        }
        cout << l << endl;
        

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
