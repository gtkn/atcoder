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


mint op(mint a, mint b){
    return a+b;
}
mint ee(){
    return 0;
}



void solve(){
    ll N,Q;
    cin >> N >> Q;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vec(mint) c2(N),c1(N),c0(N);
    rep(i,N) c2[i] = 1;
    rep(i,N) c1[i] = (-2*i+3);
    rep(i,N) c0[i] = (i-1)*(i-2);

    vec(mint) a2(N),a1(N),a0(N);
    rep(i,N) a2[i] = A[i]*c2[i];
    rep(i,N) a1[i] = A[i]*c1[i];
    rep(i,N) a0[i] = A[i]*c0[i];

    segtree<mint,op,ee> seg2(a2), seg1(a1), seg0(a0);

    while(Q--){
        ll t;
        cin >> t;
        if(t==1){
            ll x,v;
            cin >> x >> v;
            --x;
            A[x] = v;
            seg2.set(x, A[x]*c2[x]);
            seg1.set(x, A[x]*c1[x]);
            seg0.set(x, A[x]*c0[x]);
        }else{
            ll x;
            cin >> x;
            --x;
            mint res = seg2.prod(0,x+1)*x*x/2 + seg1.prod(0,x+1)*x/2 + seg0.prod(0,x+1)/2;
            cout << res.val() << endl;
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
