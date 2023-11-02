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
#define watch(x) cout << (#x) << " is " << (x) << endl
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

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vec(ll) cum(N+1);
    rep(i,N) cum[i+1] = cum[i]+A[i];


    ll ans = llINF;

    auto f = [](Pll a,Pll b){
        vec(ll) tmp = {a.first, a.second, b.first, b.second};
        // for(ll t:tmp) cout << t << " "; cout << endl;
        sort(all(tmp));
        return tmp.back()-tmp[0];
    };

    for(ll x=2; x<N-1; x++){
        // cout << x << "---" << endl;
        Pll a0,a1,b0,b1;

        ll tot = cum[x];
        ll tgt = tot/2;

        auto itr = lower_bound(all(cum), tgt);
        a0.first = *itr;
        a0.second = tot-a0.first;

        itr--;
        a1.first = *itr;
        a1.second = tot-a1.first;


        tot = cum[N]-cum[x];
        tgt = cum[x] + tot/2;
        
        itr = lower_bound(all(cum),tgt);
        b0.first = *itr-cum[x];
        b0.second = tot-b0.first;

        itr--;
        b1.first = *itr-cum[x];
        b1.second = tot-b1.first;

        chmin(ans,f(a0,b0));
        chmin(ans,f(a1,b0));
        chmin(ans,f(a0,b1));
        chmin(ans,f(a1,b1));

    }

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
