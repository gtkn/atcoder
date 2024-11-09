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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};

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
    ll N;
    cin >> N;

    vec(ll) R(N),C(N);
    rep(i,N) cin >> R[i];
    rep(i,N) cin >> C[i];

    vec(ll) rcnt(3),ccnt(3);
    rep(i,N) rcnt[R[i]]++;
    rep(i,N) ccnt[C[i]]++;

    if(rcnt[1]+2*rcnt[2] != ccnt[1]+2*ccnt[2]){
        cout << 0 << endl;
        return;
    }


    // mcomb mc(5050);



    vvec(mint) dp(N+1,vec(mint)(N+1));
    dp[0][ccnt[2]] = 1;

    ll M = ccnt[1]+ccnt[2]*2;

    ll rcum = 0;

    rep(i,N){
        if(R[i]==0){
            rep(j,N+1) dp[i+1][j] = dp[i][j];
        }
        if(R[i]==1){
            rep1(j,N){
                dp[i+1][j-1] += dp[i][j]*j;
            }
            rep(j,N+1){
                ll y = M - rcum -2*j;
                dp[i+1][j] += dp[i][j]*y;
            }
        }
        if(R[i]==2){
            rep(j,N+1){
                ll y = M - rcum -2*j;
                dp[i+1][j] += dp[i][j]*(y*(y-1)/2);
                if(j>0) dp[i+1][j-1] += dp[i][j]*y*j;
                if(j>0) dp[i+1][j-1] += dp[i][j]*j;
                if(j>1) dp[i+1][j-2] += dp[i][j]*(j*(j-1)/2);
            }
        }
        rcum += R[i];
    }

    mint ans = dp[N][0];
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
