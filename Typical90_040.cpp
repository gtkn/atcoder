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



void solve(){
    ll N, W;
    cin >> N >> W;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vvec(ll) vv(N);
    rep(i,N){
        ll k; cin >> k;
        rep(_,k){
            ll c; cin >> c; c--;
            vv[i].push_back(c);
        }
    }

    vec(ll) B(N);
    rep(i,N) B[i] = A[i]-W;

    ll st = N, gl=N+1;
    mf_graph<ll> g(N+2);

    rep(i,N){
        if(B[i]>=0) g.add_edge(st,i,0);
        else g.add_edge(st,i,-B[i]);
    }
    rep(i,N){
        if(B[i]>=0) g.add_edge(i,gl,B[i]);
        else g.add_edge(i,gl,0);
    }
    rep(i,N)for(ll j:vv[i]){
        g.add_edge(j,i,llINF);
    }

    ll ans = 0;
    rep(i,N) ans += max(0LL,B[i]);
    ans -= g.flow(st,gl);

    cout << ans << endl;

    for(auto e:g.edges()){
        cout << e.from <<  " " << e.to << " " << e.cap << " " << e.flow << endl;
    }
    for(auto b:g.min_cut(st)){
        cout << b << endl;
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
