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


void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N-1);
    rep(i,N-1) cin >> A[i];

    vec(mint) e(N),p(N);
    p[0] = 1;

    vec(mint) ed(N+1),pd(N+1);
    mint sumed=0,sumpd=0;

    rep(i,N){
        sumed += ed[i];
        sumpd += pd[i];
        e[i] += sumed;
        p[i] += sumpd;

        if(i==N-1) break;   

        ll ai = A[i];
        mint q = mint(ai+1).inv();
        mint c = q/(1-q);
        
        mint ee = c*e[i] + c*c/q*p[i];
        mint pp = c*p[i];

        ed[i+1] += ee;
        ed[i+ai+1] -= ee;
        pd[i+1] += pp;
        pd[i+ai+1] -= pp;
    }

    cout << e[N-1].val() << endl;


    // rep(i,N) cerr << e[i].val() << " "; cerr << endl;
    // rep(i,N) cerr << p[i].val() << " "; cerr << endl;
    // rep(i,N+1) cerr << ed[i].val() << " "; cerr << endl;
    // rep(i,N+1) cerr << pd[i].val() << " "; cerr << endl;
    // cerr << sumed.val() << " " << sumpd.val() << endl;
    // sumed += ed[N];
    // sumpd += pd[N];
    // cerr << sumed.val() << " " << sumpd.val() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
