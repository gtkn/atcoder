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


struct S{
    ll left_len0, right_len0, left_len1, right_len1, max_len0, max_len1, len;
    
    S(ll left_len0=0, ll right_len0=0, ll left_len1=0, ll right_len1=0, ll max_len0=0, ll max_len1=0, ll len=0):
    left_len0(left_len0), right_len0(right_len0), left_len1(left_len1), right_len1(right_len1), max_len0(max_len0), max_len1(max_len1),len(len){}
};


S op(S lh, S rh){
    S res;
    res.left_len0 = lh.left_len0;
    if(lh.left_len0 == lh.len) res.left_len0 += rh.left_len0;

    res.right_len0 = rh.right_len0;
    if(rh.right_len0 == rh.len) res.right_len0 += lh.right_len0;

    res.left_len1 = lh.left_len1;
    if(lh.left_len1 == lh.len) res.left_len1 += rh.left_len1;

    res.right_len1 = rh.right_len1;
    if(rh.right_len1 == rh.len) res.right_len1 += lh.right_len1;

    res.max_len0 = max({lh.max_len0, rh.max_len0, lh.right_len0+rh.left_len0});
    res.max_len1 = max({lh.max_len1, rh.max_len1, lh.right_len1+rh.left_len1});

    res.len = lh.len + rh.len;

    return res;
}


S ee(){
    return S{0,0,0,0,0,0,0};
}


S mapping(bool f, S x){
    S res = x;
    if(f){
        res.left_len0 = x.left_len1;
        res.left_len1 = x.left_len0;
        res.right_len0 = x.right_len1;
        res.right_len1 = x.right_len0;
        res.max_len0 = x.max_len1;
        res.max_len1 = x.max_len0;
    }
    return res;
}


bool composition(bool f, bool g){
    return f^g;
}

bool id(){
    return false;
}





void solve(){
    ll N,Q;
    cin >> N >> Q;
    string ss;
    cin >> ss;

    vector<S> v(N);
    rep(i,N){
        if(ss[i]=='0') v[i] = S{1,1,0,0,1,0,1};
        else v[i] = S{0,0,1,1,0,1,1};
    }

    lazy_segtree<S,op, ee, bool, mapping, composition, id> lseg(v);

    while(Q--){
        ll c,l,r;
        cin >> c >> l >> r;
        l--;

        if(c==1){
            lseg.apply(l,r,true);
        }else{
            S res = lseg.prod(l,r);
            cout << res.max_len1 << endl;
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
