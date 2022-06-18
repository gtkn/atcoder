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

    ll A,B;
    vec(ll) va,vb;

    vvec(Pll) dp;

    Pll f(ll a,ll b){
        if(dp[a][b].first>0 || dp[a][b].second>0) return dp[a][b];
        bool nu = ((a+b)%2==0);

        Pll x;
        if(nu){
            if(a<A){
                x = f(a+1,b);
                x.first += va[a];
                if(x.first>=dp[a][b].first) dp[a][b]=x;
            }
            if(b<B){
                x = f(a,b+1);
                x.first += vb[b];
                if(x.first>=dp[a][b].first) dp[a][b]=x;
            }
        }else{
            if(a<A){
                x = f(a+1,b);
                x.second += va[a];
                if(x.second>=dp[a][b].second) dp[a][b]=x;
            }
            if(b<B){
                x = f(a,b+1);
                x.second += vb[b];
                if(x.second>=dp[a][b].second) dp[a][b]=x;
            }
        }
        return dp[a][b];
    }


    void solve(){
        cin >> A >> B;
        va.resize(A);
        vb.resize(B);
        dp = vvec(Pll)(A+1,vec(Pll)(B+1,{0,0}));
        rep(i,A) cin >> va[i];
        rep(i,B) cin >> vb[i];

        Pll ans = f(0,0);
        cout << ans.first << endl;
        
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
