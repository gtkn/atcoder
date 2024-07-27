//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct S {
    ll dist;
    ll value;
    
    S() : dist(llINF), value(0) {}
    S(ll dist, ll value) : dist(dist), value(value) {}

    bool operator<(const S& other) const {
        if(dist != other.dist) return dist < other.dist;
        return value > other.value;
    }

    bool operator>(const S& other) const {
        if(dist != other.dist) return dist > other.dist;
        return value < other.value;
    }

    S operator+(const S& other)  {
        return S(dist+other.dist,value+other.value);
    }
};



void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    // vvec(ll) g(N);
    // rep(i,N){
    //     string S;
    //     cin >> S;
    //     rep(j,N) if(S[i]=='Y') g[i].push_back(j);
    // }
    vvec(bool) g(N,vec(bool)(N));
    rep(i,N){
        string S;
        cin >> S;
        rep(j,N) g[i][j] = (S[j]=='Y');
    }

    vvec(S) dp(N,vec(S)(N));
    rep(i,N) dp[i][i] = S(0,0);
    rep(i,N)rep(j,N)if(g[i][j]) dp[i][j] = S(1,A[j]);

    rep(k,N){
        rep(i,N)rep(j,N){
            chmin(dp[i][j], dp[i][k] + dp[k][j] );
        }
    }

    ll Q;
    cin >> Q;
    while(Q--){
        ll u,v;
        cin >> u >> v;
        --u; --v;

        S res = dp[u][v];

        if(res.dist>=llINF){
            cout << "Impossible" << endl;
        }else{
            cout << res.dist << " " << res.value + A[u] << endl;
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
