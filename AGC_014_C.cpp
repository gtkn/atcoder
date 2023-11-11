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
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll H, W,K;
    cin >> H >> W >> K;


    ll ans = llINF;

    auto f = [&](ll h, ll w){
        ll res = llINF;
        chmin(res, (h+K-1)/K);
        chmin(res, (w+K-1)/K);
        chmin(res, (H-1-h+K-1)/K);
        chmin(res, (W-1-w+K-1)/K);
        return res;
    };

    vec(string) A(H);
    rep(i,H) cin >> A[i];


    vvec(ll) dp(H,vec(ll)(W,llINF));
    queue<Pll> q;
    ll sx,sy;
    rep(i,H)rep(j,W){
        if(A[i][j]=='S'){
            sx=i; sy=j;
            dp[i][j]=0;
            q.emplace(i,j);
        }
    }

    while(!q.empty()){
        auto [h0,w0] = q.front();
        q.pop();
        rep(i,4){
            ll h1,w1;
            h1 = h0+dh[i]; w1 = w0+dw[i];
            if(h1<0 || h1>=H || w1<0 || w1>=W) continue;
            if(A[h1][w1]=='#') continue;
            if(chmin(dp[h1][w1], dp[h0][w0]+1)) q.emplace(h1,w1);
        }
    }

    rep(i,H)rep(j,W) if(dp[i][j]<=K) chmin(ans, f(i,j)+1);

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
