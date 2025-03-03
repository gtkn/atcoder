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


bool is_prime(ll n){
    if(n<=1) return false;
    for(ll i=2; i*i<=n; ++i){
        if(n%i==0) return false;
    }
    return true;
}


void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];
    rep(i,N)if(A[i]==1){
        swap(A[i],A[0]);
        swap(B[i],B[0]);
    }


    vvec(ll) vv(N);
    rep(i,N)rep(j,N){
        if(is_prime(A[i]+A[j])){
            vv[i].push_back(j);
        }
    }

    ll nn = 2*N;
    ll st = nn, gl = nn+1;

    mf_graph<ll> g(nn+2);
    rep(i,N) g.add_edge(st,i,B[i]);
    rep(i,N) g.add_edge(i+N,gl,B[i]); 
    rep(i,N)for(ll j:vv[i]){
        g.add_edge(i,j+N,B[i]);
    }

    ll ans = g.flow(st,gl)/2;

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
