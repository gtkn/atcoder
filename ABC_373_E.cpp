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
    ll N,M,K;
    cin >> N >> M >> K;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    if(N==M){
        rep(i,N) cout << 0 << endl;
        return;
    }



    vec(Pll) v(N);
    rep(i,N) v[i] = {A[i],i};
    sort(all(v));

    vec(ll) ans(N);
    rep(i,N) K-=A[i];

    vec(ll) cum(N+1);
    rep(i,N) cum[i+1] = cum[i] + v[i].first;


    rep(i,N-M){
        auto [a0,idx] = v[i];

        ll l = v[N-M].first-1, r = a0+K+1;

        while(r-l>1){
            ll mid = (r+l)/2;

            auto itr = upper_bound(all(v), Pll(mid,llINF));
            ll x = distance(v.begin(), itr);
            ll n = x - (N-M);

            ll tot = cum[x] - cum[N-M];
            ll xx = (mid+1)*n - tot ;

            if(xx<=K - (mid-a0)) l = mid;
            else r = mid;
        }
        ans[idx] = r - a0;
        if(r==a0+K+1) ans[idx] = -1;
    }




    for(ll i=N-M; i<N; i++){
        auto [a0,idx] = v[i];

        ll l = v[i].first-1, r = a0+K+1;

        while(r-l>1){
            ll mid = (r+l)/2;

            auto itr = upper_bound(all(v), Pll(mid,llINF));
            ll x = distance(v.begin(), itr);
            ll n = x - (N-M);

            ll tot = cum[x] - cum[N-M] - a0 + v[N-M-1].first;
            ll xx = (mid+1)*n - tot ;

            if(xx<=K - (mid-a0)) l = mid;
            else r = mid;
        }
        ans[idx] = r - a0;
        if(r==a0+K+1) ans[idx] = -1;


    }



    rep(i,N) cout << ans[i] << " "; cout << endl;


    // for(auto [a0,idx]:v){
    //     auto itr = upper_bound(all(v),Pll(a0,-1));
    //     ll rem = distance(itr,v.end());
    //     if(rem<M) continue;
    //     // ll ii = distance(v.begin(), itr);
    //     // ll a1 = v[ii+]
    //     ll a1 = v[N-M].first;
    //     ll x = a1-a0;
    //     if(x>K) x = -1;
    //     ans[idx] = x;
    // }

    // rep(i,N) cout << ans[i] << " "; cout << endl;




    // set<ll> st;
    // rep(i,N) st.insert(A[i]);
    // ll nn = 0;
    // map<ll,ll> mp;
    // for(ll a:st) mp[a] = nn++;
    // vec(ll) pm(nn);
    // for(auto [a,i]:mp) pm[i] = a;

    // vvec(ll) vv(nn);
    // rep(i,N) vv[ mp[A[i]] ].push_back(i);

    // vec(ll) ans(N);

    // rep(i,nn){
    //     ll a0 = pm[i];



    // }












}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
