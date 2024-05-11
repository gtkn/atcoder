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


void solve(){
    ll N,K;
    cin >> N >> K;

    vec(ll) A(N+2);
    rep1(i,N) cin >> A[i];

    vvec(ll) vv(K,vec(ll)(N+1));
    rep(i,N+1){
        vv[i%K][i] = A[i+1] - A[i];
    }

    // vector<segtree<ll,op,ee>> segv(K);
    // rep(i,K) segv[i] = segtree<ll,op,ee>(vv[i]);

    vector<fenwick_tree<ll>> fws(K,fenwick_tree<ll>(N+1));
    rep(i,K)rep(j,N+1) fws[i].add(j,vv[i][j]);

    ll Q;
    cin >> Q;
    while(Q--){
        ll l,r;
        cin >> l >> r;
        l--;

        fws[l%K].add(l,A[l]);
        fws[r%K].add(r,-A[r+1]);

        bool isok = true;
        rep(i,K) if(fws[i].sum(l,r+1)!=0) isok=false;
        if(isok) sayyn;

        fws[l%K].add(l,-A[l]);
        fws[r%K].add(r,A[r+1]);

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
