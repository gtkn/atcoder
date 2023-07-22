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
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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
    ll H,W,N;
    cin >> H >> W >> N;

    vvec(ll) vv(H,vec(ll)(W));
    rep(_,N){
        ll a,b;
        cin >> a >> b;
        vv[a-1][b-1]=1;
    } 

    vvec(ll) dp(H+1,vec(ll)(W+1));
    rep(i,H)rep(j,W) dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + vv[i][j];

    auto f = [&](ll ii,ll jj, ll nn){
        if(ii+nn > H || jj+nn > W) return llINF;
        return dp[ii+nn][jj+nn] - dp[ii][jj+nn] - dp[ii+nn][jj] + dp[ii][jj];

    };

    ll ans = 0;
    rep(i,H)rep(j,W){
        ll l = 0, r = min(H-i,W-j)+1;

        while(r-l>1){
            ll mid = (l+r)/2;
            // cout << i << " , " << j << "  : " << mid << endl;

            if(f(i,j,mid)==0) l=mid;
            else r=mid;
        }
        ans += l;
    }

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
