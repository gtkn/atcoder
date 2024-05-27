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
constexpr ll llINF = 1LL << 62;
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

    vec(ll) X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];

    ll nn = 2*N;
    vec(ll) xx(nn),yy(nn);
    rep(i,N) xx[i] = X[i], yy[i] = Y[i];
    rep(i,N) xx[i+N] = X[i], yy[i+N] = Y[i];


    auto f = [](ll x0,ll y0, ll x1, ll y1){
        return abs(x0*y1 - x1*y0)*4;
    };


    ll s = 0;
    rep(i,N){
        s += f( xx[i]-xx[0], yy[i]-yy[0], xx[i+1]-xx[0], yy[i+1]-yy[0] );
    }

    

    ll ans = llINF;
    ll a = s/4;

    ll th = s/4;
    ll b = 0, r = 0;
    rep(l,N){
        while(b<th){
            b += f( xx[r]-xx[l], yy[r]-yy[l], xx[r+1]-xx[l], yy[r+1]-yy[l] );
            ++r;
            chmin(ans, abs(a-b));
        }
        b -= f( xx[l+1]-xx[l], yy[l+1]-yy[l], xx[r]-xx[l], yy[r]-yy[l] );
        chmin(ans, abs(a-b));
    }

    th = s-s/4;
    b = 0, r = 0;
    rep(l,N){
        while(b<th){
            b += f( xx[r]-xx[l], yy[r]-yy[l], xx[r+1]-xx[l], yy[r+1]-yy[l] );
            ++r;
            chmin(ans, abs(a-(s-b)));
        }
        b -= f( xx[l+1]-xx[l], yy[l+1]-yy[l], xx[r]-xx[l], yy[r]-yy[l] );
        chmin(ans, abs(a-(s-b)));
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
