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
// using mint = modint998244353;
using mint = modint;
// mint::set_mod(P);


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

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
    ll N,P;
    cin >> N >> P;
    mint::set_mod(P);


    ll n = N/2;
    mint x = 1;
    rep1(i,N-1) x *= i;

    mcomb mc(1000);

    for(ll M=N-1; M<=n*(N-1); M++){
        vvec(mint) dp(n+1,vec(mint)(n+1));
        rep1(i,n)rep1(j,n){
            dp[i][j] = mc.c(i*j,M);
            rep1(ii,i)rep1(jj,j){
                if(ii==i && jj==j) continue;
                dp[i][j] -= dp[ii][jj]*mc.c(i,ii)*mc.c(j,jj);
            }
        }
        mint res = x * dp[n][n];
        cout << res.val() << endl;
    }



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
