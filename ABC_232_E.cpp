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
constexpr ll llINF = 1LL << 60;
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
    ll H,W,K;
    cin >> H >> W >> K;
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    mcomb mc(K+10);

    vvec(mint) dph(K+1,vec(mint)(2));
    if(x1==x2) dph[0][0] = 1;
    else dph[0][1] = 1;
    rep(i,K){
        dph[i+1][0] += dph[i][1];
        dph[i+1][1] += dph[i][0]*(H-1);
        dph[i+1][1] += dph[i][1]*(H-2);
    }

    vvec(mint) dpw(K+1,vec(mint)(2));
    if(y1==y2) dpw[0][0] = 1;
    else dpw[0][1] = 1;
    rep(i,K){
        dpw[i+1][0] += dpw[i][1];
        dpw[i+1][1] += dpw[i][0]*(W-1);
        dpw[i+1][1] += dpw[i][1]*(W-2);
    }


    mint ans = 0;
    rep(nx,K+1){
        ll ny = K-nx;
        mint tmp = 1;
        tmp *= mc.c(K,nx);
        tmp *= dph[nx][0];
        tmp *= dpw[ny][0];
        ans += tmp;
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
