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

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
 
    void solve(){
        ll N;
        cin >> N;

        vec(ll) A(N+10);
        rep1(i,N-1) cin >> A[i];
        A[N]=1;


        vec(mint) pb(N+10);
        vec(mint) wa(N+10);
        wa[1]=1; wa[2]=-1;
        rep1(i,N){
            pb[i]=pb[i-1]+wa[i];
            mint x = pb[i]/(A[i]);
            wa[i+1] += x;
            wa[i+A[i]+1] -= x;
        }
        //rep1(i,N) cout << pb[i].val() <<" ";cout<< endl;


        vec(mint) dp(N+10);
        rep(i,N+10) wa[i]=0;
        rep1(i,N){
            dp[i] = dp[i-1]+wa[i];

            mint aa = A[i];
            mint x =  dp[i]/aa + pb[i]*(aa+1)/aa/aa;

            wa[i+1] += x;
            wa[i+A[i]+1] -= x;

        }
        
        cout << dp[N].val() << endl;



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
