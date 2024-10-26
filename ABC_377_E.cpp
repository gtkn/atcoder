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

ll pow_mod(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

void solve(){
    ll N,K;
    cin >> N >> K;

    vec(ll) P(N);
    rep(i,N) cin >> P[i];
    rep(i,N) P[i]--;

    vec(bool) used(N);
    vvec(ll) vv;
    vec(ll) pos(N);
    vec(ll) idx(N);
    vec(ll) sz(N);
    vec(ll) d(N);

    rep(st,N){
        if(used[st]) continue;
        ll ii = vv.size();

        vec(ll) v = {st};
        ll now = P[st];
        while(now!=st){
            v.push_back(now);
            now = P[now];
        }
        for(ll i:v) used[i] = true;

        vv.push_back(v);
        for(ll i:v) idx[i] = ii;

        ll m = v.size();
        for(ll i:v) sz[i] = m;

        ll dd = pow_mod(2,K,m);
        for(ll i:v) d[i] = dd;

        rep(i,m) pos[v[i]] = i;
    }

    vec(ll) ans(N);
    rep(i,N){
        ll x = (pos[i] + d[i])%sz[i];
        ans[i] = vv[ idx[i] ][x];
    }

    rep(i,N) cout << ans[i]+1 << " "; cout << endl;






    // rep(_,10){
    //     rep(i,N) cerr << P[i] << " "; cerr << endl;
    //     vec(ll) p2(N);
    //     rep(i,N) p2[i] = P[P[i]];
    //     P = p2;
    // }


    // ll M = 60;

    // vvec(ll) db(N,vec(ll)(M));
    // rep(i,N) db[i][0] = P[P[i]];

    // rep(j,M-1)rep(i,N){
    //     db[i][j+1] = db[db[i][j]][j];
    // }

    // vec(ll) ans = P;
    // rep(j,M) if(bit(K,j)) rep(i,N) ans[i] = db[ans[i]][j];

    // rep(i,N) cout << ans[i]+1 << " "; cout << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
