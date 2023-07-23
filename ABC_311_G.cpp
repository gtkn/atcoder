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
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

// https://nyaannyaan.github.io/library/tree/cartesian-tree.hpp.html
// return value : pair<graph, root>
template <typename T>
pair<vector<vector<ll>>, ll> CartesianTree(vector<T> &a) {
  ll N = (ll)a.size();
  vector<vector<ll>> g(N);
  vector<ll> p(N, -1), st;
  st.reserve(N);
  for (int i = 0; i < N; i++) {
    int prv = -1;
    while (!st.empty() && a[i] < a[st.back()]) {
      prv = st.back();
      st.pop_back();
    }
    if (prv != -1) p[prv] = i;
    if (!st.empty()) p[i] = st.back();
    st.push_back(i);
  }
  int root = -1;
  for (int i = 0; i < N; i++) {
    if (p[i] != -1)
      g[p[i]].push_back(i);
    else
      root = i;
  }
  return make_pair(g, root);
}


void solve(){
    ll N,M;
    cin >> N >> M;
    vvec(ll) A(N,vec(ll)(M));
    rep(i,N)rep(j,M) cin >> A[i][j];

    vvec(ll) sum(N+1,vec(ll)(M+1));
    rep1(i,N)rep1(j,M) sum[i][j] = A[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

    auto f = [&](ll lx,ll rx, ll ly, ll ry){
        return sum[rx][ry] - sum[lx][ry] - sum[rx][ly] + sum[lx][ly];
    };


    vvvec(ll) imin(N,vvec(ll)(M,vec(ll)(M+1,llINF)));
    rep(i,N){
        rep1(ry,M)rep(ly,ry){
            chmin(imin[i][ly][ry], imin[i][ly][ry-1] );
            chmin(imin[i][ly][ry], A[i][ry-1] );
        }
    }


    ll ans = 0;

    rep1(ry,M)rep(ly,ry){
        vec(ll) B(N),C(N,llINF);
        rep(i,N) B[i] = f(i, i+1, ly, ry);
        rep(i,N) C[i] = imin[i][ly][ry];

        auto ct = CartesianTree(C);
        vvec(ll) g=ct.first;
        
        vec(ll) bcum(N+1);
        rep1(i,N) bcum[i] = bcum[i-1] + B[i-1];

        auto f2 = [&](ll lx,ll rx)->ll{
            return bcum[rx]-bcum[lx];
        };

        auto dfs = [&](auto dfs, ll lx,ll rx,ll now)->ll{
            ll res = f2(lx,rx) * C[now];

            for(ll nxt:g[now]){
                if(nxt<now) chmax(res, dfs(dfs, lx, now, nxt));
                else chmax(res, dfs(dfs, now+1, rx, nxt));                
            }

            return res;
        };

        
        chmax(ans, dfs(dfs,0,N,ct.second));

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
