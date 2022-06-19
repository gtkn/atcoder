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
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
 
    void solve(){
        ll N,D;
        cin >> N >> D;

        ll d2=0,d3=0,d5=0;
        while(D%2==0){
            D/=2;
            d2++;
        }
        while(D%3==0){
            D/=3;
            d3++;
        }
        while(D%5==0){
            D/=5;
            d5++;
        }
        if(D>1){
            cout << 0 << endl;
            return;
        }

        double dp[N+1][d2+1][d3+1][d5+1];
        rep(i,N+1)rep(j,d2+1)rep(k,d3+1)rep(l,d5+1) dp[i][j][k][l]=0;
        dp[0][0][0][0]=1.;

        rep(i,N)rep(j,d2+1)rep(k,d3+1)rep(l,d5+1){
            double x = dp[i][j][k][l]/6;
            dp[i+1][min(j,d2)][min(k,d3)][min(l,d5)] += x;
            dp[i+1][min(j+1,d2)][min(k,d3)][min(l,d5)] += x;
            dp[i+1][min(j,d2)][min(k+1,d3)][min(l,d5)] += x;
            dp[i+1][min(j+2,d2)][min(k,d3)][min(l,d5)] += x;
            dp[i+1][min(j,d2)][min(k,d3)][min(l+1,d5)] += x;
            dp[i+1][min(j+1,d2)][min(k+1,d3)][min(l,d5)] += x;
        }


        printf("%.7f\r\n",dp[N][d2][d3][d5]);

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
