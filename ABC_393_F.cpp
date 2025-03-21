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


ll op(ll a,ll b){
    return max(a,b);
}
ll ee(){
    return -llINF;
}


void solve(){
    ll N,Q;
    cin >> N >> Q;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vec(ll) R(Q),X(Q);
    rep(i,Q) cin >> R[i] >> X[i];


    set<ll> st;
    st.insert(0);
    rep(i,N) st.insert(A[i]);
    rep(i,Q) st.insert(X[i]);
    map<ll,ll> mp;
    ll nn = 0;
    for(ll x:st){
        mp[x] = nn;
        nn++;
    }


    rep(i,N) A[i] = mp[A[i]];
    rep(i,Q) X[i] = mp[X[i]];


    vvec(Pll) qs(N);
    rep(i,Q){
        qs[R[i]-1].emplace_back(X[i],i);
    }

    vec(ll) ans(Q);



    segtree<ll,op,ee> seg(nn+10);
    seg.set(0,0);
    rep(i,N){
        ll maxlen = seg.prod(0,A[i]);
        seg.set(A[i],maxlen+1);

        for(auto [x,idx]:qs[i]){
            ans[idx] = seg.prod(0,x+1);
        }
    }

    rep(i,Q){
        cout << ans[i] << endl;
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
