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
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct edge{
    ll to,c;
    edge(ll to=0, ll c=0):to(to),c(c){}
};

struct abc{
    ll a,b,c;
    abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N,M;
    cin >> N >> M;

    vvec(bool) vv(N+1,vec(bool)(M));

    rep(i,N){
        string S;
        cin >> S;
        rep(j,M) vv[i][j] = (S[j]=='#');
    }

    rep1(i,N)rep(j,M){
        if(vv[i-1][j]) vv[i][j]=true;
        if(j>0) if(vv[i-1][j-1]) vv[i][j] = true;
    }


    vvec(mint) dp(N+2,vec(mint)(M+1));
    dp[N][0] = 1;

    rep(j,M){
        vec(mint) cum(N+3);
        rep(i,N+1){
            cum[0] += dp[i][j];
            cum[i+2] -= dp[i][j];
        }

        mint tmp = 0;
        rep(i,N+1){
            if(i>0) if(vv[i][j] && vv[i-1][j]) break;
            tmp += cum[i];
            dp[i][j+1] = tmp;
        }
        // cout << j << "!" << endl;
    }

    // rep(i,N+2){
    //     rep(j,M+1) cout << dp[i][j].val() << " "; cout << endl;
    // }

    mint ans = 0;
    rep(i,N+1) ans += dp[i][M];
    cout << ans.val() << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
