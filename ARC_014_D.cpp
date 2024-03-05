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

void solve(){
    ll A,N,M;
    cin >> A >> N >> M;

    vec(ll) L(N);
    rep(i,N) cin >> L[i];
    sort(all(L));

    vec(ll) d(N-1);
    rep(i,N-1) d[i] = L[i+1] - L[i] -1;
    sort(all(d));

    vec(ll) cum(N);
    rep(i,N-1) cum[i+1] = cum[i] + d[i];

    // rep(i,N-1) cerr << d[i] << ","; cerr << endl;
    // rep(i,N-1) cerr << cum[i] << ","; cerr << endl;

    auto f = [&](ll w)->ll{
        if(N==1) return 0LL;
        if(w<d[0]){
            return w*(N-1);
        }
        
        ll l=0,r=N-1;
        while(r-l>1){
            ll mid = (l+r)/2;
            if(d[mid] <= w) l = mid;
            else r = mid;
        }

        ll res = cum[r] + w*(N-1-r);
        return res;
    };


    while(M--){
        ll x,y;
        cin >> x >> y;

        ll ans = f(x+y);
        // cerr << ans << ", ";
        ans += N;
        // cerr << ans << ", ";
        ans += min(L[0]-1, x);
        // cerr << ans << ", ";
        ans += min(A - L.back(),y);

        cout << ans << endl;
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
