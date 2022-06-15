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

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    vvec(ll) dp;
    ll N;
    vec(Pll) v;


    ll f(ll l,ll r){
        if(dp[l][r]>=0) return dp[l][r];

        ll res = 0;
        ll x = l+r-1;
        if(l>0) chmax(res, f(l-1,r) +  v[x].first*abs(l-1-v[x].second)  );
        if(r>0) chmax(res, f(l,r-1) +  v[x].first*abs(N-r-v[x].second)  );
        dp[l][r]=res;
        return res;
    }



    void solve(){
        cin >> N;
        rep(i,N){
            ll a; cin >> a;
            v.emplace_back(a,i);
        }
        sort(all(v),greater<Pll>());

        dp = vvec(ll)(N+1,vec(ll)(N+1,-llINF));
        dp[0][0]=0;

        ll ans = 0;
        rep(i,N+1) chmax(ans, f(i,N-i));
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
