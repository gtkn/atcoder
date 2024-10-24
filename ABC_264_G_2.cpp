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

const ll M = 26;
const ll mm = M*M;

ll v1[M];
ll v2[M][M];
ll v3[M][M][M];


void solve(){
    rep(i,M) v1[i] = 0;
    rep(i,M)rep(j,M) v2[i][j] = 0;
    rep(i,M)rep(j,M)rep(k,M) v3[i][j][k] = 0;

    
    ll N;
    cin >> N;

    rep(_,N){
        string t;
        ll p;
        cin >> t >> p;

        if(t.size()==1){
            ll i = t[0] - 'a';
            v1[i] = p;
        }
        if(t.size()==2){
            ll i = t[0] - 'a';
            ll j = t[1] - 'a';
            v2[i][j] = p;
        }
        if(t.size()==3){
            ll i = t[0] - 'a';
            ll j = t[1] - 'a';
            ll k = t[2] - 'a';
            v3[i][j][k] = p;
        }
    }


    vvec(Pll) g(mm);
    rep(i,M)rep(j,M){
        ll now = i*M + j;
        rep(k,M){
            ll nxt = j*M + k;
            ll w = v1[k] + v2[j][k] + v3[i][j][k];
            g[now].emplace_back(nxt,w);
        }
    }


    vec(ll) dist(mm,llINF);
    dist[0]=0;
    bool update;
    rep(_,mm){
        update = false;
        rep(now,mm) for(auto [nxt,w]:g[now]) if(chmin(dist[nxt], dist[now]-w)) update = true;
    }
    if(update){
        cout << "Infinity" << endl;
        return;
    }


    ll ans = -llINF;
    rep(i,M) chmax(ans,v1[i]);

    vec(ll) dp(mm);
    rep(i,M)rep(j,M) dp[i*M+j] = v2[i][j] + v1[i] + v1[j];
    rep(_,mm+10){
        rep(now,mm) chmax(ans,dp[now]);
        vec(ll) dp2(mm,-llINF);
        rep(now,mm)for(auto [nxt,w]:g[now]) chmax(dp2[nxt],dp[now]+w);
        swap(dp,dp2);        
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
