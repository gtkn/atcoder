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

    segtree<mint,op,ee> seg0(N), seg1(N), seg2(N);

    rep(i,N) seg0.set(i,mint(A[i])*(i*i-i));
    rep(i,N) seg1.set(i,A[i]*(-2*i+1));
    rep(i,N) seg2.set(i,A[i]);


    while(Q--){
        ll t;
        cin >> t;
        if(t==1){
            ll x,v;
            cin >> x >> v;
            x--;
            seg0.set(x,mint(v)*(x*x-x));
            seg1.set(x,v*(-2*x+1));
            seg2.set(x,v);
        }else{
            ll x;
            cin >> x;            
            mint res = x*x*seg2.prod(0,x) + x*seg1.prod(0,x) + seg0.prod(0,x);
            res/=2;
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
