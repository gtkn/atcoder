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

ll op(ll a, ll b){ return max(a,b);}
ll ee(){return 0;}
ll mapping(ll f, ll x){return max(f,x);}
ll composition(ll f,ll g){return max(f,g);}
ll id(){return 0;}


void solve(){
    ll H,W,N;
    cin >> H >> W >> N;

    vec(ll) R(N),C(N),L(N);
    rep(i,N) cin >> R[i] >> C[i] >> L[i];

    vvec(ll) ids(H+1);
    rep(i,N) ids[R[i]].push_back(i);

    lazy_segtree<ll, op, ee, ll, mapping, composition, id> ls(W+2);
    vec(ll) ans(N);

    rep1r(h,H)for(ll idx:ids[h]){
        ll l = C[idx], r = C[idx]+L[idx];
        ll cnt = ls.prod(l,r);

        ans[idx] = H-cnt;
        ls.apply(l,r,cnt+1);

        // cerr << idx << "=====" << nl;
        // cerr << l << " " << r << " " << cnt << nl;
        // rep1(i,W) cerr << ls.get(i) << " "; cerr << nl;


    }

    rep(i,N) cout << ans[i] << nl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
