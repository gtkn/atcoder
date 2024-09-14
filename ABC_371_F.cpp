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

struct S{ll sz,val;};
struct F{ll k;};

S op(S a,S b){return S{a.sz+b.sz, a.val+b.val};}
S ee(){return S{0,0};}

S mapping(F f, S x){
    if(f.k>-llINF) return S{ x.sz, x.sz*f.k};
    return x;
}
F composition(F f,F g){
    if(f.k>-llINF) return f;
    return g;
}
F id(){return F{-llINF};}




void solve(){
    ll N;
    cin >> N;
    vec(ll) X(N);
    rep(i,N) cin >> X[i];

    vec(S) xx;
    rep(i,N) xx.push_back(S{1,X[i]-i});

    lazy_segtree<S,op,ee,F,mapping,composition,id> lseg(xx);


    ll Q;
    cin >> Q;
    ll ans = 0;
    while(Q--){
        ll t,g;
        cin >> t >> g;
        t--;
        g-=t;

        ll res = 0;
        if(lseg.get(t).val <= g){
            ll l=t, r=N;
            while(r-l>1){
                ll mid = (l+r)/2;
                if(lseg.get(mid).val >= g) r=mid;
                else l=mid;
            }
            S s = lseg.prod(t,r);
            res = s.sz*g - s.val;
            lseg.apply(t,r,F{g});
        }else{
            ll l=-1, r=t;
            while(r-l>1){
                ll mid = (l+r)/2;
                if(lseg.get(mid).val <= g) l=mid;
                else r=mid;
            }
            S s = lseg.prod(r,t+1);
            res = s.val - s.sz*g;
            lseg.apply(r,t+1,F{g});

            // cerr << r << "~"<<t+1<<endl;
        }
        // cerr << res << "," << t << "," << g << endl;
        // rep(i,N) cerr << lseg.get(i).val+i << " "; cerr << endl;


        ans += res;

    }

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
