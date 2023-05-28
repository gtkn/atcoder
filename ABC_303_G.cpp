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
using ld = long double;

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

ll op(ll a,ll b){return min(a,b);}
ll ee(){return llINF;}


struct Solver{

 
    void solve(){
        ll N,A,B,C,D;
        cin >> N >> A>> B >> C >> D;

        vec(ll) x(N);
        rep(i,N) cin >> x[i];

        vec(ll) tot(N+1);
        rep(i,N) tot[i+1] = tot[i]+x[i];

        auto f = [&](ll l, ll r){
            return tot[r]-tot[l];
        };

        vector dp(N+1,vector<ll>(N+1,-llINF));
        rep(i,N+1) dp[i][i] = 0;

        using seg = segtree<ll,op,ee>;
        vector<seg> segv(N+1, seg(N+1));
        

        for(ll n=1; n<=N; n++){
            for(ll l=0; l+n<=N; l++){
                ll r=l+n;

                chmax(dp[l][r], x[l] - dp[l+1][r] );
                chmax(dp[l][r], x[l+n-1] - dp[l][r-1] );

                if(n<=B){
                    chmax(dp[l][r], f(l,l+n) - A);
                }else{
                    chmax(dp[l][r], f(l,l+n) - A - segv[n-B].prod(l,l+B+1) );
                }

                if(n<=D){
                    chmax(dp[l][r], f(l,l+n) - C);
                }else{
                    chmax(dp[l][r], f(l,l+n) - C - segv[n-D].prod(l,l+D+1 ) );
                }
                
                segv[n].set(l,dp[l][r]+f(l,r));
            }
        }

        cout << dp[0][N] << endl;

        

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
