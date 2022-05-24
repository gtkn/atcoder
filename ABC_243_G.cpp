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

    ll llsqrt(ll N){
        ll sqrtN=sqrt(N)-1;
        while(sqrtN+1<=N/(sqrtN+1))sqrtN++;
        return sqrtN;
    }

    void solve(){
        ll X;
        cin >> X;        

        ll x2 = llsqrt(X);//floor(sqrt(X)+1e-9);
        ll x4 = llsqrt(x2);//floor(sqrt(x2)+1e-9);

        /*
        vec(ll) dp(x4+10);
        dp[1]=1;
        for(ll x=2; x<=x4; x++){
            for(ll i = 1; i*i<=x; i++) dp[x] += dp[i];
        }
        ll ans = 0;
        rep1(i,x4) ans += ( x2 - i*i + 1 )*dp[i];
        cout << ans << endl;
        */

        vec(ll) v(x4+10);
        rep1(i,x4) v[i] = max(0LL,x2-i*i+1);

        while(v[2]>0){
            vec(ll) tot(x4+10);
            rep1(i,x4+1) tot[i] = tot[i-1]+v[i];
            rep1(i,x4+1){
                if(i*i-1<=x4) v[i] = tot[x4+1]-tot[ i*i-1 ];
                else v[i]=0;
            }
        }
        cout << v[1] << endl;

    }
};


int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
