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
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------





ll f(ll x){

    ll xx = x;
    vec(ll) v;
    while(xx){
        v.push_back(xx%10);
        xx/=10;
    }
    ll n = v.size();
    reverse(all(v));

    vvvec(ll) dp(n+1,vvec(ll)(10,vec(ll)(2)));
    // dp[0][0][0] = 1;

    rep(i,n)dp[i][0][i>0] = 1;


    rep(i,n)rep(j,10)rep(k,10){
        if(j==k) continue;

        if(k==v[i]) dp[i+1][k][0] += dp[i][j][0];
        if(k<v[i] ) dp[i+1][k][1] += dp[i][j][0];

        dp[i+1][k][1] += dp[i][j][1];
    }

    // cout << "---0" << endl;
    // rep(i,n+1){
    //     rep(j,10) cout << dp[i][j][0] << ", "; cout << endl;
    // }
    // cout << "---1" << endl;
    // rep(i,n+1){
    //     rep(j,10) cout << dp[i][j][1] << ", "; cout << endl;
    // }


    ll res = 0;
    rep(j,10)rep(k,2) res += dp[n][j][k];
    return res;

}




void solve(){
    ll K;
    cin >> K;

    // cout << f(27) << "!" << endl;
    // return;


    ll l=0,r=1e13;
    while(r-l>1){
        ll mid = (l+r)/2;
        if(f(mid)>=K) r=mid;
        else l=mid;
    }

    cout << r << endl;

}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
