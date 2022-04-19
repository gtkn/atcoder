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
 
    void solve(){
        ll N;
        cin >> N;
        vec(ll) A(N);
        rep(i,N) cin >> A[i];
        ll nn = -(N/2);

        vector<map<ll,ll>> dp(N);
        rep(i,2){
            dp[i][0]=0;
            dp[i][-1]=A[i];
        }
        chmax(dp[1][-1], A[0]);

        ll th=10;
        for(ll i=2;i<N;i++){
            ll cnt=0;
            for(auto mi:dp[i-1]){
                dp[i][mi.first] = mi.second;
                
                cnt++;
                if(cnt>th) break;
            }
            cnt=0;
            for(auto mi:dp[i-2]){
                ll j = mi.first-1;
                if(j<nn) continue;

                if(dp[i].find(j)==dp[i].end()) dp[i][j] = mi.second+A[i];
                else chmax(dp[i][j], mi.second+A[i]);
                
                cnt++;
                if(cnt>th) break;
            }
        }




        ll ans = -llINF;
        rep(i,N) if(dp[i].find(nn)!=dp[i].end()) chmax(ans,dp[i][nn]);
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
