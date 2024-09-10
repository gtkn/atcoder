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

// 区間和,区間更新のlseg
struct S{
    ll sz, val;
    S(ll sz=0, ll val=0):sz(sz),val(val){}    
};
struct F{
    ll k;
    F(ll k=0):k(k){}    
};
S op(S a, S b){
    return S{a.sz+b.sz, a.val+b.val};
}
S ee(){
    return S{0,0};
}

S mapping(F f, S x){
    if(f.k>=0) return S{ x.sz, x.sz*f.k};
    return x;
}
F composition(F f, F g){
    if(f.k>=0) return f;
    return g;
}
F id(){
    return F{-1};
}




void solve(){
    ll N,Q,X;
    cin >> N >> Q >> X;
    vec(ll) P(N);
    rep(i,N) cin >> P[i];

    vec(S) v0(N),v1(N);
    rep(i,N) v0[i] = S{1,(P[i]>=X)};
    rep(i,N) v1[i] = S{1,(P[i]>X)};

    lazy_segtree<S,op,ee,F,mapping,composition,id> lseg0(v0),lseg1(v1);


    while(Q--){
        ll c,l,r; cin >> c >> l >> r;
        l--;
        if(c==1){
            ll b0 = lseg0.prod(l,r).val;
            lseg0.apply(l,r-b0,F{0});
            lseg0.apply(r-b0,r,F{1});
            ll b1 = lseg1.prod(l,r).val;
            lseg1.apply(l,r-b1,F{0});
            lseg1.apply(r-b1,r,F{1});
        }else{
            ll b0 = lseg0.prod(l,r).val;
            lseg0.apply(l,l+b0,F{1});
            lseg0.apply(l+b0,r,F{0});
            ll b1 = lseg1.prod(l,r).val;
            lseg1.apply(l,l+b1,F{1});
            lseg1.apply(l+b1,r,F{0});
        }
    }

    ll ans = 0;
    rep(i,N) if(lseg0.get(i).val != lseg1.get(i).val) ans = i+1;
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
