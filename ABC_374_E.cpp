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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,X;
    cin >> N >> X;
    vec(ll) A(N),B(N),P(N),Q(N);
    rep(i,N) cin >> A[i] >> P[i] >> B[i] >> Q[i];


    auto fi = [&](ll w, ll idx)->ll{
        ll res = llINF;
        ll a = A[idx], b = B[idx], p = P[idx], q = Q[idx];

        auto cost = [&](ll n) -> ll {
            ll ww = w - n * a;
            if(ww<=0) return n * p; 
            ll m = (ww + b - 1) / b;
            assert(n * a + m * b >= w);
            return n * p + m * q;
        };

        ll nmax = (w + a - 1) / a;
        chmin(res,  cost(nmax) );
        chmin(res,  cost(0) );

        ll lo = 0, hi = nmax; // upper bound for n
        while (hi - lo > 2) {
            ll mid1 = (2 * lo + hi) / 3;
            ll mid2 = (lo + 2 * hi) / 3;
            if (cost(mid1) < cost(mid2)) {
                hi = mid2;
            } else {
                lo = mid1;
            }
        }

        ll d = 1000;
        for (ll n = max(lo-d,0LL); n <= min(hi+d,nmax); ++n) {
            chmin(res, cost(n));
        }

        return res;
    };


    auto fj = [&](ll w,ll idx )->ll{
        ll res = llINF;
        ll a = A[idx], b = B[idx], p = P[idx], q = Q[idx];

        

        if(a/p > b/q){
            swap(a,b);
            swap(p,q);
        }
        auto cost = [&](ll n) -> ll {
            ll m = (w - n * a + b - 1) / b;
            chmax(m,0LL);
            return n * p + m * q;
        };

        ll n0 = (w+a-1)/a;
        ll d = 100;
        for(ll n=max(n0-d,0LL); n<=n0+d; ++n){
            chmin(res,cost(n));
        }
        return res;
    };



    auto f = [&](ll w)->bool{
        ll tot = 0;
        rep(i,N){
            tot += fi(w,i);
            // tot += fj(w,i);
            if(tot>X) return false;
            if(tot<0) return false;
        }
        return true;
    };



    ll l = 0, r = 1000000010;
    while(r-l>1){
        ll mid = (l+r)/2;
        if(f(mid)) l = mid;
        else r = mid;
    }

    cout << l << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
