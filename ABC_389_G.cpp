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

    ll nn = N*(N-1)/2;
    ll hf = N/2;

    mint dp[2][hf+1][hf+1][nn+1][hf+1]; // 偶奇、偶数の数、奇数の数、使った辺の数、今の距離の頂点数 // 偶奇要らないかも
    rep(i,2)rep(j,hf+1)rep(k,hf+1)rep(l,nn+1)rep(m,hf+1) dp[i][j][k][l][m] = 0;
    dp[0][1][0][0][1] = 1;

    rep(ne,hf)rep(no,hf)rep(ed,nn)rep(now,hf)rep(eo,2){
        ll rem = N - ne - no;
        ll ed_rem = nn - ed;

        vvec(mint) dp2(rem+1,vec(mint)(ed_rem+1));
        dp2[0][0] = 1;
        rep(i,rem)rep(j,ed_rem+1){
            mint a = now;
            rep1(k,ed_rem){
                if(j+k>ed_rem) continue;
                dp2[i+1][j+k] += dp2[i][j] * a;
                a *= now-k;
            }
        }

        rep1(nxt,rem)for(ll ed2=nxt; ed2<=ed_rem; ed2++){
            mint x = 1;
            rep(i,nxt) x*=(rem-i);
            x *= dp2[nxt][ed2];
            rep(ed3,ed_rem){
                if(ed2+ed3>ed_rem) break;
                dp[1-eo][ne+nxt][no][ed+ed2][ed3] += dp[eo][ne][no][ed][now] * x;
            }


        }

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
