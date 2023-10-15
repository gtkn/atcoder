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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

//---modintで組み合わせ扱う用の構造体---
struct mcomb{
    ll nmax;
    vec(mint) fa,af;
    mcomb(ll sz=200020){
        nmax = sz;
        fa.resize(nmax+1);
        fa[0]=1;
        rep1(i,nmax) fa[i]=fa[i-1]*i;
        af.resize(nmax+1);
        rep(i,nmax+1) af[i]=fa[i].inv();
    }
    mint c(ll n, ll k){
        if(n<k || k<0 || n>nmax) return 0;
        return fa[n]*af[k]*af[n-k];
    }
};


void solve(){
    ll R,C,X,Y,D,L;
    cin >> R >> C >> X >> Y >> D >> L;

    mcomb mc(R*C+10);

    vvec(mint) memo(X+1,vec(mint)(Y+1));
    rep1(x,X)rep1(y,Y){
        memo[x][y] = mc.c(x*y,D)*mc.c(x*y-D,L);
    }

    auto f = [&](ll x_,ll y_)->mint{
        if(x_>0 && x_<=X && y_>0 && y_<=Y) return memo[x_][y_];
        else return mint(0);
    };


    vvec(mint) dp(X+1,vec(mint)(Y+1));
    rep1(x,X)rep1(y,Y){
        dp[x][y] = f(x,y);

        dp[x][y] -= f(x-1,y)*2;
        dp[x][y] -= f(x,y-1)*2;

        dp[x][y] += f(x-1,y-1)*4;
        dp[x][y] += f(x-2,y);
        dp[x][y] += f(x,y-2);

        dp[x][y] -= f(x-2,y-1)*2;
        dp[x][y] -= f(x-1,y-2)*2;
        
        dp[x][y] += f(x-2,y-2);
    }

    // rep1(i,X){
    //     rep1(j,Y) cout << dp[i][j].val() << " "; cout << endl;
    // }

    mint ans = 0;
    rep1(i,R)rep1(j,C){
        if(i+X-1<=R && j+Y-1<=C) ans+=dp[X][Y];
    }

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
