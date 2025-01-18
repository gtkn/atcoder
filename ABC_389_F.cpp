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

//---prod:区間max, apply:区間addのlazy_segtreeのテンプレート---
ll op(ll a, ll b){ return max(a,b);}
ll ee(){return 0;}
ll mapping(ll f, ll x){return f+x;}
ll composition(ll f,ll g){return f+g;}
ll id(){return 0;}



void solve(){
    ll N;
    cin >> N;
    vec(ll) L(N),R(N);
    rep(i,N) cin >> L[i] >> R[i];
    rep(i,N) R[i]++;


    ll M = 500050;
    vec(ll) v(M);
    rep(i,M) v[i]=i;
    lazy_segtree<ll, op, ee, ll, mapping, composition, id> ls(v);


    rep(i,N){

        ll tl,tr;        
        {
            ll l=0, r=M;
            while(r-l>1){
                ll mid = (l+r)/2;
                if(ls.get(mid) >= L[i]) r=mid;
                else l=mid;
            }
            tl = r;
        }
        {
            ll l=0, r=M;
            while(r-l>1){
                ll mid = (l+r)/2;
                if(ls.get(mid) >= R[i]) r=mid;
                else l=mid;
            }
            tr = r;
        }
        ls.apply(tl,tr,1);

        // rep(i,10) cerr << ls.get(i) << " "; cerr << endl;

    }



    ll Q;
    cin >> Q;
    while(Q--){
        ll x;
        cin >> x;
        cout << ls.get(x) << endl;
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
