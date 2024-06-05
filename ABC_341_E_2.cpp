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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------



struct S{bool l,r,isok,isee;};
struct F{bool k;};

S op(S a,S b){
    if(a.isee) return b;
    if(b.isee) return a;
    bool isok = a.isok & b.isok & (a.r!=b.l);
    return S{a.l,b.r,isok};
}
S ee(){
    return S{0,0,0,1};
}

S mapping(F f, S x){
    if(f.k) return S{!x.l, !x.r, x.isok, x.isee};
    return x;
}
F composition(F f,F g){
    if(f.k) return F{ bool(f.k^g.k) };
    return g;
}
F id(){
    return F{0};
}



void solve(){
    ll N, Q;
    cin >> N >> Q;
    
    string ss;
    cin >> ss;

    lazy_segtree<S,op,ee,F,mapping,composition,id> lseg(N);
    rep(i,N){
        bool x = (ss[i]=='1');
        lseg.set(i, S{x,x,1,0});
    }

    while(Q--){
        ll t,l,r;
        cin >> t >> l >> r;
        l--;
        if(t==1){
            lseg.apply(l,r,F{1});
        }else{
            if(lseg.prod(l,r).isok) sayyn;
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
