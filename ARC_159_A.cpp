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
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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
        ll N, K;
        cin >> N >> K;

        vvec(ll) A(N,vec(ll)(N));
        rep(i,N)rep(j,N) cin >> A[i][j];

        // vvec(ll) dp(N,vec(ll)(N,llINF));
        // rep(i,N) dp[i][i] = 0;

        // rep(i,N)rep(j,N){
        //     if(A[i][j]==0) continue;
        //     rep(k,N) chmin(dp[i][k], dp[i][j]+dp[j][k]);
        // }

        // rep(i,N)rep(j,N) if(dp[i][j]==llINF) dp[i][j]= -1;




        vvec(ll) dp = A;
        rep(i,N)rep(j,N) if(dp[i][j]==0) dp[i][j]=llINF;
        // rep(i,N) dp[i][i] = 0;


        rep(k,N)rep(i,N)rep(j,N) chmin(dp[i][j], dp[i][k] + dp[k][j]);

        rep(i,N)rep(j,N) if(dp[i][j]==llINF) dp[i][j]= -1;

        ll Q;
        cin >> Q;

        while(Q--){
            ll s,t;
            cin >> s >> t;
            s--; t--;
            
            if(s==t){
                cout << 0 << endl;
                continue;
            }
            
            s%=N; t%=N;


            cout << dp[s][t] << endl;

        }




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
