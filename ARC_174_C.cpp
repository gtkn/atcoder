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

void solve(){
    ll N;
    cin >> N;

    vvec(mint) dpx(N+1,vec(mint)(2));
    vvec(mint) dpy(N+1,vec(mint)(2));
    dpy[1][0] = 1;

    mint ninv = mint(N).inv();

    rep(i,N){
        mint p = i*ninv;
        mint q = 1-p;
        mint pp = mint(1-p*p).inv();
        mint ppp = pp*pp*p*p;

        {
            mint x = dpx[i][0], y = dpy[i][0];
            dpx[i+1][0] += p*q*( x*pp + y*ppp );
            dpx[i+1][1] +=   q*( x*pp + y*ppp );
            dpy[i+1][0] += p*q*y*pp;
            dpy[i+1][1] +=   q*y*pp;
        }
        {
            mint x = dpx[i][1], y = dpy[i][1];
            dpx[i+1][0] +=   q*( x*pp + y*ppp );
            dpx[i+1][1] += p*q*( (x+y)*pp + y*ppp );
            dpy[i+1][0] +=   q*y*pp;
            dpy[i+1][1] += p*q*y*pp;
        }
    }

    mint ans0 = dpx[N][0] + dpx[N][1];



    rep(i,N+1)rep(j,2) dpx[i][j]=0;
    rep(i,N+1)rep(j,2) dpy[i][j]=0;
    dpy[1][1] = 1;


    rep(i,N){
        mint p = i*ninv;
        mint q = 1-p;
        mint pp = mint(1-p*p).inv();
        mint ppp = pp*pp*p*p;

        {
            mint x = dpx[i][0], y = dpy[i][0];
            dpx[i+1][0] += p*q*( x*pp + y*ppp );
            dpx[i+1][1] +=   q*( x*pp + y*ppp );
            dpy[i+1][0] += p*q*y*pp;
            dpy[i+1][1] +=   q*y*pp;
        }
        {
            mint x = dpx[i][1], y = dpy[i][1];
            dpx[i+1][0] +=   q*( x*pp + y*ppp );
            dpx[i+1][1] += p*q*( (x+y)*pp + y*ppp );
            dpy[i+1][0] +=   q*y*pp;
            dpy[i+1][1] += p*q*y*pp;
        }
    }

    mint ans1 = dpx[N][0] + dpx[N][1];



    cout << ans0.val() << " " << ans1.val() << endl;






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
