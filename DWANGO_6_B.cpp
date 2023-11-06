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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;
    vec(ll) x(N);
    rep(i,N) cin >> x[i];


    ll nn = N-1;
    vec(ll) d(nn);
    rep(i,nn) d[i] = x[i+1]-x[i];

    vec(mint) fa(N+1),af(N+1);
    fa[0] = 1;
    rep1(i,N) fa[i] = fa[i-1]*i;
    rep(i,N+1) af[i] = fa[i].inv();


    mint a = 0, ans = 0;
    rep(i,nn){
        a += mint(i+1).inv()*fa[nn];
        ans += a*d[i];
        // cout << i << " : " << ans.val() << ", " << a.val() << endl;
    }

    // ans *= fa[nn];
    cout << ans.val() << endl;


    // auto comb = [&](ll n,ll k){
    //     return fa[n]*af[k]*af[n-k];
    // };

    // mint ans = 0;
    // mint w = 0;
    // rep(i,nn){
    //     w += comb(nn,i+1)*fa[i]*fa[nn-i];
    //     cout << i <<" : " << ans.val() << ", " << w.val() << endl;
    //     ans += d[i]*w;
    // }

    // cout << ans.val() << endl;




    // ll tmp = x[N-1]-x[0];
    // ll tot = tmp;

    // vec(ll) v;
    // rep(i,nn/2){
    //     v.push_back(tot);
    //     tmp -= d[i];
    //     tmp -= d[nn-1-i];
    //     tot += tmp;
    // }
    // if(tmp>0) v.push_back(tot+tmp);
    // repr(i,nn/2) v.push_back(v[i]);



    // mint ans = 0;
    // rep1(w,nn){
    //     ans += comb(nn,w+1) * fa[N-w-2] * fa[w-1] * v[w];
    // }

    // cout << ans.val() << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
