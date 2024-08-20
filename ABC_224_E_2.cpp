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


void solve(){
    ll H,W,N;
    cin >> H >> W >> N;

    vec(ll) r(N),c(N),a(N);
    rep(i,N) cin >> r[i] >> c[i] >> a[i];

    set<ll> st;
    for(ll ai:a) st.insert(ai);
    map<ll,ll> mp;
    ll nn = 0;
    for(ll ai:st) mp[ai] = nn++;

    vvec(ll) vv(nn);
    rep(i,N) vv[ mp[a[i]] ].push_back(i);

    vec(ll) ans(N);
    vec(ll) dp_r(H+1,-1),dp_c(W+1,-1);

    repr(ai,nn){
        for(ll ii:vv[ai]){
            chmax(ans[ii],dp_r[r[ii]]+1);
            chmax(ans[ii],dp_c[c[ii]]+1);
        }
        for(ll ii:vv[ai]){
            chmax(dp_r[r[ii]],ans[ii]);
            chmax(dp_c[c[ii]],ans[ii]);
        }
    }

    rep(i,N) cout << ans[i] << endl;











    // vvec(Pll) vv(H+W+10);

    // rep(i,N){
    //     ll r,c,a;
    //     cin >> r >> c >> a;
    //     vv[r].push_back({a,i});
    //     vv[H+c].push_back({a,i});
    // }


    // vvec(ll) g(N);
    // for(vec(Pll) &v:vv){
    //     // for(auto [a,ii]:v) cerr << ii << " "; cerr << endl;
    //     sort(all(v));
    //     vvec(ll) memo;
    //     ll pred = -1;
    //     for(auto [a,ii]:v){
    //         if(pred!=a) memo.push_back({});
    //         pred = a;
    //         memo.back().push_back(ii);
    //     }
    //     rep(i,(int)memo.size()-1){
    //         for(ll u:memo[i]) g[u].push_back(memo[i+1][0]);
    //     }
    // }


    // vec(ll) ans(N);
    // vec(bool) used(N);
    // auto f = [&](auto f, ll now)->ll{
    //     if(used[now]) return ans[now];
    //     used[now] = true;
    //     for(ll nxt:g[now]) chmax(ans[now],f(f,nxt)+1);
    //     return ans[now];
    // };

    // // rep(i,N){
    // //     cerr << i << " : ";
    // //     for(ll u:g[i]) cerr << u << " ";
    // //     cerr << endl;
    // // }


    // rep(i,N) cout << f(f,i) << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
