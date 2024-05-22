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

ll op(ll a, ll b){
    return max(a,b);
}
ll ee(){
    return 0;
}



void solve(){
    ll N;
    cin >> N;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    set<ll> st;
    rep(i,N) st.insert(A[i]);
    map<ll,ll> mp;
    ll idx = 0;
    for(auto p: st){
        mp[p] = idx;
        idx++;
    }
    vec(ll) B(N);
    rep(i,N) B[i] = mp[A[i]];


    vec(ll) fv(N),rv(N);

    segtree<ll,op,ee> segf(N),segr(N);

    rep(i,N){
        fv[i] = segf.prod(0,B[i]);
        segf.set(B[i], fv[i]+1);
    }
    repr(i,N){
        rv[i] = segr.prod(B[i]+1,N);
        segr.set(B[i], rv[i]+1);
    }

    ll L = segf.all_prod();
    vec(ll) ans;
    rep(i,N) if(fv[i]+1+rv[i]==L) ans.push_back(i+1);

    cout << ans.size() << endl;
    for(ll a: ans) cout << a << " "; cout << endl;



}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
