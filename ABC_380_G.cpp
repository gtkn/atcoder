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



//---転倒数-fenwicktree--
ll inversions(vector<ll> A){
  ll N = A.size();
  ll ans=0;
  fenwick_tree<ll> ft(N);
  for(auto ai:A){
    ans += ft.sum(ai,N);
    ft.add(ai,1);
  }
  return ans;
}





void solve(){
    ll N,K;
    cin >> N >> K;

    vec(ll) P(N);
    rep(i,N) cin >> P[i];
    rep(i,N) P[i]--;

    ll t0 = inversions(P);

    mint q0 = mint(N-K+1).inv();
    // mint q1 = 1;
    // rep1(i,K) q1*=i;
    // q1 = q1.inv();


    fenwick_tree<ll> fw(N);
    ll t = 0;

    auto add = [&](ll x)->void{
        t += fw.sum(x,N);
        fw.add(x,1);
    };

    auto del = [&](ll x)->void{
        fw.add(x,-1);
        t -= fw.sum(0,x);
    };

    rep(i,K){
        add(P[i]);
    }


    mint a = K*(K-1);
    a/=4;

    // cerr << a.val() << endl;

    mint ans = 0;
    for(ll i=K; i<=N; ++i){
        ans += q0 * (t0 -t + a);

        if(i==N) break;
        del(P[i-K]);
        add(P[i]);
    }

    cout << ans.val() << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
