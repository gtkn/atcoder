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
    ll N;
    cin >> N;

    vvec(ll) A(N,vec(ll)(N));
    rep(i,N) rep(j,N) cin >> A[i][j];  

    ll K = 4;
    ll st = N*N*K, gl = st+1;
    mf_graph<ll> g(gl+1);

    auto id = [&](ll i,ll j,ll k){
        if(k==-1) return st;
        if(k==K) return gl;
        return (i*N+j)*K + k;
    };

    rep(i,N)rep(j,N){
        rep(k,K-1){
            g.add_edge(id(i,j,k+1),id(i,j,k),llINF);
        }
    }

    rep(i,N)rep(j,N){
        if(A[i][j]==0) continue;
        rep(k,K+1){
            if(k+1==A[i][j]) continue;
            g.add_edge(id(i,j,k-1),id(i,j,k),llINF);
        }
    }

    auto add = [&](ll i0,ll j0,ll i1,ll j1){
        rep(k0,K)rep(k1,k0+1){
            ll c = 2;
            if(k0==k1) c=1;
            g.add_edge(id(i0,j0,k0),id(i1,j1,k1),c);
        }
    };

    rep(i,N)rep(j,N){
        if(i>0){
            add(i,j,i-1,j);
            add(i-1,j,i,j);
        }
        if(j>0){
            add(i,j,i,j-1);
            add(i,j-1,i,j);
        }
    }

    ll ans = g.flow(st,gl);
    cerr << ans << endl;

    auto x = g.min_cut(st);
    rep(i,N)rep(j,N)rep(k,K+1){
        if( x[id(i,j,k-1)] && !x[id(i,j,k)] ){
            A[i][j] = k+1;
        }
    }

    rep(i,N){
        rep(j,N) cout << A[i][j] << " "; cout << endl;
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
