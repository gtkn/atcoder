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

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N;
        cin >> N;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        ll x = 0;
        for(ll i=2; i<N; i++) x^=A[i];

        ll a0,a1;
        a0 = A[0]; a1=A[1];

        vvec(ll) dp(51,vec(ll)(4,llINF));

        dp[0][0] = 0;

        rep(i,50)rep(j,4){
            ll b0,b1,bx;
            b0 = bit(a0,i);
            b1 = bit(a1,i);
            bx = bit(x,i);

            ll jj=0;
            
            if(bit(j,0)) b0--;
            if(b0<0) b0=1, jj |= 1;
            if(bit(j,1)) b1++;
            if(b1>1) b1=0, jj |= 2;

            if(b0^b1 == bit(x,i)) chmin(dp[i+1][jj], dp[i][j]);

            b0--;
            if(b0<0) b0=1, jj |= 1;
            b1++;
            if(b1>1) b1=0, jj |= 2;

            if(b0^b1 == bit(x,i)) chmin(dp[i+1][jj], dp[i][j]+(1LL<<i));
        }

        ll ans = dp[50][0];
        if(ans>=a0) ans = -1;
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
