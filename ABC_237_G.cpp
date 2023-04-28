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

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


struct S{ll sz,val;};
struct F{ll k;};

S op(S a,S b){return S{a.sz+b.sz, a.val+b.val};}
S ee(){return S{0,0};}

S mapping(F f, S x){
    if(f.k>=0) return S{ x.sz, x.sz*f.k};
    return x;
}
F composition(F f,F g){
    if(f.k>=0) return f;
    return g;
}
F id(){return F{-1};}


struct Solver{
 
    void solve(){
        ll N,Q,X;
        cin >> N >> Q >> X;

        vec(ll) P(N);
        rep(i,N) cin >> P[i];


        vec(S) v0(N),v1(N);
        rep(i,N) v0[i] = S{1, (P[i]>=X) };
        rep(i,N) v1[i] = S{1, (P[i]>X) };
        
        // rep(i,N) cout << v0[i]<< " "; cout<< endl;
        // rep(i,N) cout << v1[i]<< " "; cout<< endl;

        lazy_segtree<S,op,ee,F,mapping,composition,id> ls0(v0),ls1(v1);


        auto lssort = [](lazy_segtree<S, op, ee, F, mapping, composition, id> &ls, ll c, ll l, ll r){
            l--;
            ll b = ls.prod(l,r).val;
            
            if(c==1){
                ls.apply(l,r-b,F{0});
                ls.apply(r-b,r,F{1});
            }else{
                ls.apply(l,l+b,F{1});
                ls.apply(l+b,r,F{0});
            }
        };



        while(Q--){
            ll c,l,r;
            cin >> c >> l >> r;
            lssort(ls0,c,l,r);
            lssort(ls1,c,l,r);
        }

        ll ans = -1;
        rep(i,N) if(ls0.get(i).val != ls1.get(i).val) ans = i+1;
        cout << ans << endl;






    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
