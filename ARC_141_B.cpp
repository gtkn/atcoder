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

//------------------------------------------------

struct Solver{
 
    void solve(){
        ll N,M;
        cin >> N >> M;

        ll MM = M;
        ll X = 0;
        while(MM){
            //cout << MM << ";;;" << X << endl;
            X++;
            MM>>=1;
        }

        if(N>X){
            cout << 0 << endl;
            return;
        }


        vec(mint) v(X+1);
        v[0] = 1;
        rep1(i,X) v[i] = 1LL<<(i-1);
        v[X] = M - (1LL<<(X-1)) + 1;

        vvec(mint) dp(X+10, vec(mint)(X+10));
        dp[0][0] = 1;
        rep(i,N){
            rep(j,X){
                for(ll k=j+1; k<=X; k++) dp[i+1][k] += dp[i][j]*v[k];
            }
        }



        mint ans = 0;
        rep1(i,X) ans += dp[N][i];
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
