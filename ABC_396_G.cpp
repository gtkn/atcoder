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
using mint = modint998244353;
// using mint = modint;
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



void solve(){
    ll H,W;
    cin >> H >> W;

    vec(ll) A(H);
    rep(i,H){
        string s;
        cin >> s;
        ll num = 0;
        rep(j, W) {
            if (s[j] == '1') {
            num |= (1LL << j);
            }
        }
        A[i] = num;

    }

    ll ww = (1<<W);


    vvvec(ll) dp(ww,vvec(ll)(W+1,vec(ll)(W+1,0)));
    rep(i,H) dp[A[i]][0][0]++;

    repr(i,ww)rep(j,W)rep(k,W){
        ll mask = (1<<j)-1;
        ll t = i&mask;
        ll s = i&(~mask);
        ll mask2 = (2<<j)-1;
        ll ss = i&(~mask2);
        ll tt = t | (1<<j);
        ll ii = ss|tt;
        ll kk = k + !(bit(s,j));
        dp[ii][j+1][kk] += dp[i][j][k];
        ii = ss|t;
        kk = k + (bit(s,j));
        dp[ii][j+1][kk] += dp[i][j][k];
    }


    ll ans = llINF;
    rep(x,ww){
        ll res = 0;
        rep(k,W+1) res += min(k,W-k) * dp[x][W][k];
        chmin(ans,res);
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
