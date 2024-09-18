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
    ll H,W,N;
    cin >> H >> W >> N;
    ll sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;

    vec(ll) X(N), Y(N);
    rep(i,N) cin >> X[i] >> Y[i];

    set<ll> xset, yset;
    xset.insert(sx), xset.insert(gx);
    yset.insert(sy), yset.insert(gy);
    rep(i,N)for(ll d:{-1,0,1}){ 
        xset.insert(X[i]+d);
        yset.insert(Y[i]+d);
    }
    map<ll,ll> xmap, ymap;
    ll xi = 1;
    for(auto x:xset) xmap[x] = xi++;
    ll yi = 1;
    for(auto y:yset) ymap[y] = yi++;


    vvec(ll) r(xi), c(yi);
    rep(i,N){
        r[xmap[X[i]]].push_back(ymap[Y[i]]);
        c[ymap[Y[i]]].push_back(xmap[X[i]]);
    }

    rep(i,xi) sort(all(r[i]));
    rep(i,yi) sort(all(c[i]));


    map<Pll,ll> dp;
    rep(i,N)for(auto [dx,dy]:dhw){
        ll x = xmap[X[i]] + dx, y = ymap[Y[i]] + dy;
        dp[{x, y}] = llINF;
    }
    dp[{xmap[sx],ymap[sy]}] = llINF;
    dp[{xmap[gx],ymap[gy]}] = llINF;

    priority_queue<tri,vector<tri>,greater<tri>> pq;
    auto push = [&](ll d, ll x, ll y)->void{
        if(chmin(dp[{x,y}],d)) pq.push({d,x,y});
    };
    push(0,xmap[sx],ymap[sy]);


    // for(auto [p,d]: dp){
    //     auto [x,y] = p;
    //     cerr << x << " " << y << " " << d << endl;
    // }


    while(!pq.empty()){
        auto [d,x,y] = pq.top(); pq.pop();
        if(dp[{x,y}] < d) continue;

        {
            auto itr = upper_bound(all(r[x]),y);
            if(itr != r[x].end()){
                ll yr = *itr -1;
                push(d+1,x,yr);
            }    
        }
        {
            auto itr = upper_bound(all(c[y]),x);
            if(itr != c[y].end()){
                ll xd = *itr -1;
                push(d+1,xd,y);
            }
        }
        {
            auto itr = lower_bound(all(r[x]),y);
            if(itr != r[x].begin()){
                ll yl = *(--itr) +1;
                push(d+1,x,yl);
            }
        }
        {
            auto itr = lower_bound(all(c[y]),x);
            if(itr != c[y].begin()){
                ll xu = *(--itr) +1;
                push(d+1,xu,y);
            }
        }
    }



    ll ans = dp[{xmap[gx],ymap[gy]}];
    if(ans == llINF) ans = -1;
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
