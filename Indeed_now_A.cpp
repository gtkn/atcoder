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

vec(ll) rev = {2,3,0,1,-1};

void solve(){
    ll H,W;
    cin >> H >> W;
    vvec(ll) c(H,vec(ll)(W));
    rep(i,H)rep(j,W) cin >> c[i][j];

    vvec(ll) a(H,vec(ll)(W));
    rep(i,H)rep(j,W) a[i][j] = i*W + j + 1;
    a[H-1][W-1] = 0;


    map<vvec(ll),ll> dp;

    auto f = [&](auto f, vvec(ll) &vv, ll h, ll w, ll cnt, ll prev)->void{
        if( dp.count(vv) ) chmin(dp[vv], cnt);
        else dp[vv]=cnt;
        if(cnt>=12) return;

        cnt++;
        rep(k,4){
            if(rev[k]==prev) continue;
            ll h2 = h+dh[k];
            ll w2 = w+dw[k];
            if(h2<0 || h2>=H || w2<0 || w2>=W) continue;
            swap(vv[h][w], vv[h2][w2]);
            f(f,vv,h2,w2,cnt,k);
            swap(vv[h][w], vv[h2][w2]);
        }
    };

    ll zh,zw;
    rep(i,H)rep(j,W){
        if(c[i][j]==0){
            zh=i; zw=j;
        }
    }
    f(f,c,zh,zw,0,4);


    ll ans = 24;
    auto f2 = [&](auto f2, vvec(ll) &vv, ll h, ll w, ll cnt, ll prev)->void{
        if( dp.count(vv) ) chmin(ans, cnt + dp[vv]);
        if(cnt>=12) return;

        cnt++;
        rep(k,4){
            if(rev[k]==prev) continue;
            ll h2 = h+dh[k];
            ll w2 = w+dw[k];
            if(h2<0 || h2>=H || w2<0 || w2>=W) continue;
            swap(vv[h][w], vv[h2][w2]);
            f2(f2,vv,h2,w2,cnt,k);
            swap(vv[h][w], vv[h2][w2]);
        }
    };



    f2(f2,a,H-1,W-1,0,4);


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
