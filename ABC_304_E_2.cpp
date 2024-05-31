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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


void solve(){
    ll N,M;
    cin >> N >> M;

    vec(ll) u(M),v(M);
    rep(i,M){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
    }

    ll K;
    cin >> K;
    vec(ll) x(K),y(K);
    rep(i,K){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }


    dsu uf(N);
    rep(i,M) uf.merge(u[i],v[i]);

    set<Pll> st;
    rep(i,K){
        ll lx = uf.leader(x[i]);
        ll ly = uf.leader(y[i]);
        if(ly < lx) swap(lx,ly);
        st.insert({lx,ly});
    }

    ll Q;
    cin >> Q;
    while(Q--){
        ll p,q;
        cin >> p >> q;
        p--; q--;
        ll lp = uf.leader(p);
        ll lq = uf.leader(q);
        if(lq < lp) swap(lp,lq);
        if(st.find({lp,lq}) == st.end()) sayyn;
    }


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
