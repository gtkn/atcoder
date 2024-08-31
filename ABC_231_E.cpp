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



void solve(){
    ll N,X;
    cin >> N >> X;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vec(ll) b(N);
    rep(i,N-1) b[i] = A[i+1]/A[i];

    auto f = [&](ll x)->vec(ll){
        vec(ll) res(N);
        repr(i,N){
            res[i] = x/A[i];
            x %= A[i];
        }
        return res;
    };

    auto f2 = [&](vec(ll) v)->ll{
        ll res = 0;
        rep(i,N) res += v[i]*A[i];
        return res;
    };


    map<ll,ll> mp;
    mp[0] = llINF;


    auto g = [&](auto g, ll x)->ll{
        if(mp.find(x)!=mp.end()) return mp[x];
        vec(ll) v = f(x);
        ll res = 0;
        rep(i,N) res += v[i];
        rep(i,N-1){
            if(v[i]==0) continue;
            ll n = v[i];
            v[i] = 0;
            chmin(res, n + g(g,f2(v)));
            v[i+1]++;
            chmin(res, b[i] - n + g(g,f2(v)));
            break;
        }
        // cerr << x << " " << res << endl;
        return mp[x] = res;
    };

    ll ans = g(g,X);    

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
