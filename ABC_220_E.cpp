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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,D;
    cin >> N >> D;

    ll M = 2000020;
    vec(mint) two(M+1);
    two[0] = 1;
    rep1(i,M) two[i] = two[i-1]*2;

    mint x = 0;
    mint ans = 0;
    repr(i,N){
        ll rem = (N-1-i);
        if(rem<D && 2*rem >= D){
            ll a = rem;
           ll b = D-rem;
            ll c = (a==b)?1:2 ;
            // cerr << i << " " << a << " " << b << endl;
            x += two[a-1] * two[b-1] * c;
        }
        ans += two[i] * x;
        // cerr << i << ":" << two[i].val() << " " <<  x.val() << " " << ans.val() << endl;
    }
    rep(i,N-D){
        ans += two[i] * two[D];
        // cerr << i << "/" << two[i].val() << " " << two[i+D].val() << " " << ans.val() << endl;
    }
    ans *= 2;

    cout << ans.val() << endl;
    





    // vec(mint) cum(N+1);
    // rep(i,N) cum[i+1] = cum[i]+two[i];


    // auto f = [&](ll th)->mint{
    //     mint res = 0;
    //     cerr << th << endl;
    //     rep(i,N){
    //         ll l = max(0LL,i-th);
    //         ll r = min(N,i+th+1);
    //         res += two[i] * (cum[r]-cum[l]);
    //         cerr << i << " " << l << " " << r << " " << two[i].val() << " " << (cum[r]-cum[l]).val() << endl;
    //     }
    //     return res;
    // };

    // mint ans = f(D) - f(D-1);
    // ans/=2;
    // cout << ans.val() << endl;  

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
