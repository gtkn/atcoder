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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

void solve(){
    ll N,H;
    cin >> N >> H;

    vec(ll) X(N+1);
    rep1(i,N) cin >> X[i];

    vec(ll) P(N+1), F(N+1);
    rep1(i,N-1) cin >> P[i] >> F[i];

    vvvec(ll) dp(N+1,vvec(ll)(H+1,vec(ll)(H+1,llINF)));
    rep(j,H+1) dp[N][j][j]=0;


    rep1r(i,N){
        ll d = X[i]-X[i-1], ii=i-1;

        rep(j,H+1)rep(k,H+1){
            ll jj = j+d, kk = k-d;
            
            // cout << i << " " << j << " " << k << " : " << ii << " " << jj << " " << kk << endl;
            
            if(jj>H || kk<0) continue;


            chmin(dp[ii][jj][kk], dp[i][j][k]);
            ll jjj = jj-F[ii];
            if(jjj>=0){
                chmin(dp[ii][jjj][kk], dp[i][j][k]+P[ii]);
            }
            if(jj==H){
                rep(dh,F[ii]) chmin(dp[ii][jj-dh][kk], dp[i][j][k]+P[ii]);
            }

            ll kkk = min(kk+F[ii],H);
            chmin(dp[ii][jj][kkk], dp[i][j][k]+P[ii]);
        }
    }     


    ll ans = llINF;
    rep(j,H+1)rep(k,H+1) chmin(ans, dp[0][j][k]);
    // rep(k,H+1) chmin(ans, dp[0][H][k]);

    if(ans>=llINF) ans = -1;
    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
