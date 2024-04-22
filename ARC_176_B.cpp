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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


// x^n % mod を求める関数
ll pow_mod(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}


void solve(){
    ll N,M,K;
    cin >> N >> M >> K;

    // while(N >= M) N -= (M-K);

    ll d = N-M+1, l = M-K;
    ll x = (d+l-1)/l;
    if(N<M) x=0;
    N-=x*l;

    if(N==M-1 && K==M-1){
        cout << 0 << endl;
        return;
    }



    ll ans = pow_mod(2,N,10);

    cout << ans << endl;



}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
