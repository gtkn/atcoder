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
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

using mint = modint;

struct Solver{
 
 
 
    void solve(){
        ll N,M;
        cin >> N >> M;

        mint::set_mod(M);



        vvec(mint) cmb(N+1,vec(mint)(N+1));
        cmb[0][0] = 1;
        rep(i,N)rep(j,N){
            cmb[i+1][j+1] += cmb[i][j];
            cmb[i+1][j] += cmb[i][j];
        }

        vec(mint) two(N*N+1);
        two[0] = 1;
        rep1(i,N*N) two[i] = two[i-1]*2;


        auto pairs = [](ll n){return n*(n-1)/2;};

        vvec(mint) vv(N,vec(mint)(N));
        rep(i,N)rep(j,N) vv[i][j] = (two[i]-1).pow(j);



        vvec(mint) dp(N+1,vec(mint)(N+1));
        dp[1][1] = 1;


        rep(i,N)rep(j,N){
            rep1(k,N-i-1){
                mint tmp = two[pairs(k)];
                tmp *= vv[j][k];
                tmp *= cmb[N-1-i][k];
                dp[i+k][k] += dp[i][j] * tmp;
            }
        }

        mint ans = 0;
        rep(j,N) ans += dp[N-1][j] * vv[j][1];

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
