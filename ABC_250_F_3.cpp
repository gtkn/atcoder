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
//using mint = modint998244353;


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
    ll N;
    cin >> N;
    vec(ll) X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];

    auto f = [&](ll i0, ll i1, ll i2)->ll{
        ll x01 = X[i1]-X[i0], y01 = Y[i1]-Y[i0];
        ll x02 = X[i2]-X[i0], y02 = Y[i2]-Y[i0];
        return abs(x01*y02-x02*y01)*4;
    };

    ll tot = 0;
    rep(i,N){
        ll j = (i+1)%N;
        tot += f(0,i,j);
    }

    ll a = tot/4;
    // cerr << tot << " " << a << endl;

    ll ans = llINF;
    ll b = 0, r = 0;
    rep(l,N){
        while(b<a){
            ll nr = (r+1)%N;
            b += f(l,r,nr);
            r = nr;
            chmin(ans,abs(a-b));
        }
        b -= f(l,(l+1)%N,r);
        chmin(ans,abs(a-b));
    }

    b = 0, r = N-1;
    repr(l,N){
        while(b<a){
            ll nr = (r+N-1)%N;
            b += f(l,r,nr);
            r = nr;
            chmin(ans,abs(a-b));
        }
        b -= f(l,(l-1+N)%N,r);
        chmin(ans,abs(a-b));
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
