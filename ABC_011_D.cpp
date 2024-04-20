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

#define dame { puts("0"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N,D,X,Y;
    cin >> N >> D >> X >> Y;

    if(X%D!=0 || Y%D!=0) dame;

    ll cx = abs(X/D), cy = abs(Y/D);
    ll rem = N-cx-cy;
    if(rem&1) dame;

    // cerr << cx << " " << cy << " " << rem << endl;

    vvec(double) dp(N+1,vec(double)(N+1));
    dp[0][0] = 1;
    rep1(i,N){
        dp[i][0] = 1;
        rep(j,i) dp[i][j+1] = dp[i][j] *  (i-j) / (j+1) / 4;
    }

    // rep(i,N+1){
    //     rep(j,N+1) cerr << dp[i][j] << " "; cerr << endl;
    // }

    double ans = 0;
    rep(dx,rem+1){
        ll dy = (rem-2*dx)/2;
        if(dy<0) continue;

        double now = 1;
        ll nn = N;
        for(ll a:{cx+dx,dx,cy+dy,dy}){
            now *= dp[nn][a];
            nn -= a;
        }
        // cerr << dx << " , " << now << endl;
        // assert(nn==0);
        ans += now;
    }

    printf("%.10f\n",ans);



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
