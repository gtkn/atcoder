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
#define watch(x) cout << (#x) << " is " << (x) << endl
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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


void solve(){
    ll N, Q;
    cin >> N >> Q;

    vec(string) P(N);
    rep(i,N) cin >> P[i];

    vvec(ll) cum(N+1,vec(ll)(N+1));
    rep1(i,N)rep1(j,N){
        cum[i][j] = cum[i-1][j] + cum[i][j-1] - cum[i-1][j-1] + (P[i-1][j-1]=='B');
    }

    // rep(i,N+1){
    //     rep(j,N+1) cerr << cum[i][j] << " "; cerr << endl;
    // }


    auto f = [&](ll h,ll w){
        ll res = 0;
        res += cum[N][N] * (h/N) * (w/N);
        res += cum[h%N][N] * (w/N);
        res += cum[N][w%N] * (h/N);
        res += cum[h%N][w%N];

        return res;
    };

    while(Q--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;

        ll ans = f(c+1,d+1) - f(c+1,b) - f(a,d+1) + f(a,b);
        cout << ans << endl;
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
