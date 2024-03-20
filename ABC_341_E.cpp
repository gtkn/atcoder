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

struct S{
    bool l,r,isok,emp;
    S(bool l=false, bool r=false, bool isok=true, bool emp=true):
    l(l),r(r),isok(isok),emp(emp){}
};

S op(S a,S b){
    bool l = a.l;
    bool r = b.r;

    bool isok = false;
    if(a.emp){
        isok = b.isok;
    }else if(b.emp){
        isok = a.isok;
    }else{
        if(a.isok && b.isok && a.r != b.l) isok = true;        
    }

    bool emp = (a.emp & b.emp);

    return S{l,r,isok,emp};
}


S ee(){
    return S();
}


S mapping(bool f, S x){
    x.l ^= f;
    x.r ^= f;
    return x;
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

    vec(S) v(N);
    rep(i,N){
        bool b = (ss[i]=='1');
        v[i].l = b;
        v[i].r = b;
        v[i].isok = true;
        v[i].emp = false;
    }


    lazy_segtree<S,op,ee, bool, mapping, composition, id> lseg(v);

    while(Q--){
        ll t,l,r;
        cin >> t >> l >> r;
        if(t==1){
            lseg.apply(l-1,r,true);
        }else{
            if(lseg.prod(l-1,r).isok) sayyn;
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
