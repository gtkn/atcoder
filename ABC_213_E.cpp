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


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};
// vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll H,W;
    cin >> H >> W;

    vec(string) S(H);
    rep(i,H) cin >> S[i];

    vvec(ll) dp(H,vec(ll)(W,llINF));

    priority_queue<tri,vector<tri>,greater<tri>> pq;
    auto push = [&](ll cost,ll h, ll w)->void{
        if(chmin(dp[h][w], cost)) pq.emplace(cost,h,w);
    };
    push(0,0,0);

    auto isout = [&](ll h,ll w)->bool{
        return (h<0 || h>=H || w<0 || w>=W);
    };

    while(!pq.empty()){
        auto [c0,h0,w0] = pq.top();
        pq.pop();
        if(dp[h0][w0] < c0) continue;

        rep(k,4){
            ll h1 = h0 + dh[k], w1 = w0 + dw[k];
            if(isout(h1,w1)) continue;
            if(S[h1][w1]=='.'){
                push(c0,h1,w1);
            }else{
                for(ll pm:{1,-1})rep(dk,4){
                    ll kk = (k+dk*pm + 4)%4;
                    h1 += dh[kk]; w1 += dw[kk];
                    if(isout(h1,w1)) continue;
                    push(c0+1,h1,w1);
                }
            }
        }
    }

    cout << dp[H-1][W-1] << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
