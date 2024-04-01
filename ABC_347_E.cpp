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


void solve(){
    ll N,Q;
    cin >> N >> Q;

    vec(ll) x(Q);
    rep(i,Q) cin >> x[i];

    vvec(ll) vv(N+1);
    rep(i,Q) vv[x[i]].push_back(i);
    rep1(i,N){
        if(vv[i].size()%2==1) vv[i].push_back(Q);
    }

    vec(ll) sz(Q+1);
    vec(bool) used(N+1);
    ll now = 0;
    rep(i,Q){
        if(used[x[i]]) now--;
        else now++;
        used[x[i]] = !used[x[i]];
        sz[i+1] = now;
    }

    vec(ll) cum(Q+1);
    rep(i,Q) cum[i+1] = cum[i] + sz[i+1];

    auto f = [&](ll _l, ll _r){
        return cum[_r] - cum[_l];
    };


    // rep(i,Q+1) cerr << sz[i] <<" "; cerr << endl;
    // rep(i,Q+1) cerr << cum[i] <<" "; cerr << endl;



    vec(ll) ans(N+1);
    rep1(i,N){
        ll res = 0;
        assert(vv[i].size()%2==0);
        // cerr << "i: " << i << endl;
        for(ll l=0; l<vv[i].size(); l+=2){
            ll r = l+1;
            // cerr << vv[i][l] <<" "<< vv[i][r] << endl;
            res += f(vv[i][l],vv[i][r]);
        }
        ans[i] = res;
    }
    rep1(i,N) cout << ans[i] <<" "; cout << endl;






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
