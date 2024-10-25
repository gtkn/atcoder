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


// struct S{ll sz,val;};
// struct F{ll k;};

// S op(S a,S b){return S{a.sz+b.sz, a.val+b.val};}
// S ee(){return S{0,0};}

// S mapping(F f, S x){
//     if(f.k>=0) return S{ x.sz, x.sz*f.k};
//     return x;
// }
// F composition(F f,F g){
//     if(f.k>=0) return f;
//     return g;
// }
// F id(){return F{-1};}


struct S {
    array<ll, 3> cnt;
    array<array<ll, 3>, 3> p;
    S() {
        cnt.fill(0);
        p.fill({0,0,0});
    }
    S(ll x){
        cnt.fill(0);
        p.fill({0,0,0});
        cnt[x] = 1;
    }

    ll get(){
        ll res = 0;
        rep(i,3) rep(j,i) res += p[i][j];
        return res;
    }

};

struct F{
    array<ll,3> f;
    F(){
        f = {0,1,2};
    }

    F(ll a,ll b,ll c){
        f = {a,b,c};
    }

};


S op(S a, S b){
    S res;
    rep(i,3) res.cnt[i] = a.cnt[i] + b.cnt[i];
    rep(i,3) rep(j,3) res.p[i][j] = a.p[i][j] + b.p[i][j];
    rep(i,3) rep(j,3) res.p[i][j] += a.cnt[i] * b.cnt[j];
    return res;
}

S ee(){
    return S();
}

S mapping(F f, S x){
    S res;
    rep(i,3) res.cnt[ f.f[i] ] += x.cnt[i];
    rep(i,3) rep(j,3) {
        ll ii = f.f[i], jj = f.f[j];
        res.p[ii][jj] += x.p[i][j];
    }
    return res;
}
F composition(F f,F g){
    F res;
    rep(i,3) res.f[i] = f.f[g.f[i]];
    return res;
}
F id(){return F();}





void solve(){
    ll N,Q;
    cin >> N >> Q;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vec(S) v(N);
    rep(i,N) v[i] = S(A[i]);


    lazy_segtree<S, op, ee, F, mapping, composition, id> seg(v);

    while(Q--){
        ll t;
        cin >> t;
        if(t==1){
            ll L,R;
            cin >> L >> R;
            L--;
            ll res = seg.prod(L,R).get();
            cout << res << endl;
        }else{
            ll L,R,S,T,U;
            cin >> L >> R >> S >> T >> U;
            L--;
            seg.apply(L,R,F{S,T,U});
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
