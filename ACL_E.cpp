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
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------



mint ten[200020]; // 10^i
mint one[200020]; // 1がi個


struct S{
    ll sz;
    mint val;
};
struct F{ll k;};

S op(S l,S r){return S{l.sz+r.sz, l.val*ten[r.sz]+r.val};} // opは左,右の順に受け取るっぽい
S ee(){return S{0,0};}

S mapping(F f, S x){
    if(f.k>=0) return S{ x.sz, one[x.sz]*f.k};
    return x;
}
F composition(F f,F g){
    if(f.k>=0) return f;
    return g;
}
F id(){return F{-1};}


void solve(){
    ll N, Q;
    cin >> N  >> Q;

    ten[0] = 1;
    rep1(i,N) ten[i] = ten[i-1]*10;

    one[0] = 0;
    rep1(i,N) one[i] = one[i-1]*10 +1;


    vec(S) v(N);
    rep(i,N) v[i] = {1,1};

    lazy_segtree<S,op,ee,F,mapping,composition,id> lseg(v);


    while(Q--){
        ll l,r,d;
        cin >> l >> r >> d;
        lseg.apply(l-1,r, F{d});

        cout << lseg.all_prod().val.val() << endl;
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
