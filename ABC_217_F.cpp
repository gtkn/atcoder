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
    ll N,M;
    cin >> N >> M;
    vec(ll) A(M),B(M);
    rep(i,M) cin >> A[i] >> B[i];
    rep(i,M) A[i]--, B[i]--;

    ll nn = 2*N;
    vvec(bool) g(nn,vec(bool)(nn));
    rep(i,M) g[A[i]][B[i]] = true;

    // rep(i,nn){
    //     rep(j,nn) cerr << g[i][j] << " "; cerr << endl;
    // }


    mcomb mc(500);

    vvec(mint) dp(nn+1,vec(mint)(nn+1));
    vvec(bool) used(nn+1,vec(bool)(nn+1));
    rep(i,nn+1) dp[i][i] = 1;
    rep(i,nn+1) used[i][i] = true;

    auto f = [&](auto f, ll l, ll r) -> mint{
        // cerr << l << " " << r << endl;
        if(r<l) return 0;
        if(used[l][r]){
            return dp[l][r];
        }

        used[l][r] = true;
        mint res = 0;

        for(ll m=l+1; m<r; m+=2){
            if(g[l][m]){
                mint lc = f(f,l+1,m);
                mint rc = f(f,m+1,r);
                ll nl = (m-l-1)/2, nr = (r-m-1)/2;
                res += lc*rc*mc.c(nl+nr+1,nl+1);
            }
        }

        // if(g[l][r-1]) res += f(f,l+1,r-1);
        // for(ll m=l+2; m<r; m+=2){
        //     mint lc = f(f,l,m);
        //     mint rc = f(f,m,r);
        //     ll nl = (m-l)/2, nr = (r-m)/2;
        //     res += lc*rc*mc.c(nl+nr,nl);
        // }

        dp[l][r] = res;
        return res;
    };


    mint ans = f(f,0,nn);
    cout << ans.val() << endl;

    // rep(i,nn+1){
    //     rep(j,nn+1) cerr << dp[i][j].val() << " "; cerr << endl;
    // }


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
