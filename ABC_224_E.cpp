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



map<ll,ll> compressCoordinates(vec(ll) v){
    // 値の集合vを受け取って座標圧縮する
    // res[val] = idx
    // v[idx] = val となるように入力のvも変更する

    sort(all(v));
    v.erase(unique(all(v)),v.end());

    ll nn = v.size();
    map<ll,ll> res;
    rep(i,nn) res[ v[i] ] = i;

    return res;
}


void solve(){
    ll H, W, N;
    cin >> H >> W >> N;

    vec(ll) r(N),c(N),a(N);
    rep(i,N) cin >> r[i] >> c[i] >> a[i];

    vec(ll) rowmax(H+1,-1), colmax(W+1,-1);

    map<ll,ll> cc = compressCoordinates(a);
    // for(auto p:cc) cerr << p.first << " " << p.second << endl;
    ll nn = cc.size();

    vvec(ll) vv(nn);
    rep(i,N) vv[ cc[a[i]] ].push_back(i);

    vec(ll) ans(N);
    repr(x,nn){
        for(ll i:vv[x]){
            // cerr << i << ", " << x << endl;
            chmax(ans[i], rowmax[r[i]]+1);
            chmax(ans[i], colmax[c[i]]+1);
        }
        for(ll i:vv[x]){
            chmax(rowmax[r[i]], ans[i]);
            chmax(colmax[c[i]], ans[i]);
        }
    }

    rep(i,N) cout << ans[i] << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
