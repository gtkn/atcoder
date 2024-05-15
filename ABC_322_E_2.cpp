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
constexpr ll llINF = 1LL << 60;
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


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N,K,P;
    cin >> N >> K >> P;

    vec(ll) C(N);
    vvec(ll) A(N,vec(ll)(K));

    rep(i,N){
        cin >> C[i];
        rep(j,K) cin >> A[i][j];
    }


    ll pp = P+1;
    vec(ll) t(K+1);
    t[0] = 1;
    rep(i,K) t[i+1] = t[i]*pp;

    ll nn = t[K];

    auto f = [&](ll now, vec(ll) &a)->ll{
        vec(ll) v(K);
        ll tmp = now;
        rep(i,K){
            v[i] = tmp%pp;
            tmp /= pp;
        }

        rep(i,K){
            v[i] += a[i];
            chmin(v[i],P);
        }

        ll res = 0;
        rep(i,K) res += v[i]*t[i];
        return res;
    };


    vec(ll) dp(nn,llINF);
    dp[0] = 0;
    rep(i,N)repr(j,nn){
        ll k = f(j,A[i]);
        chmin(dp[k],dp[j]+C[i]);
    }

    ll ans = dp[nn-1];
    if(ans>=llINF) ans = -1;
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
