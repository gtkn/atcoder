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




// 約数列挙
// set<ll> divisor(ll n){
//     set<ll> res;
//     ll x=1;
//     while(x<=n){
//         res.insert(n/x);
//         x = n/(n/x)+1;
//     }
//     res.erase(n);
//     return res;
// }

vec(ll) divisor(ll n){
    vec(ll) res = {1};
    for(ll i=2; i*i<=n; i++){
        if(n%i!=0) continue;
        res.push_back(i);
        res.push_back(n/i);
    }
    return res;
}



void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    ll M = 1e5;
    vec(ll) gr(M+1);
    gr[1]=0;

    vec(bool) used(M+1);

    for(ll i = 2; i<=M; i++){
        // set<ll> d = divisor(i);
        vec(ll) d = divisor(i);
        // cerr << i << endl;
        // for(ll di:d) cerr << di << " "; cerr << endl;
        for(ll di:d) used[gr[di]] = true;
        rep(k,M){
            if(used[k]) continue;
            gr[i] = k;
            break;
        }
        for(ll di:d) used[gr[di]] = false;
    }

    ll x = 0;
    for(ll ai:A) x ^= gr[ai];

    if(x) cout << "Anna" << endl;
    else cout << "Bruno" << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
