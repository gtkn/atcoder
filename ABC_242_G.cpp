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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N;
    cin >> N;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    ll Q;
    cin >> Q;
    vec(ll) l(Q),r(Q);
    rep(i,Q) cin >> l[i] >> r[i];
    rep(i,Q) l[i]--;

    vec(ll) q(Q);
    rep(i,Q) q[i] = i;

    ll M = sqrt(N);
    sort(all(q),[&](ll i, ll j){
        if(l[i]/M != l[j]/M) return l[i] < l[j];
        return r[i] < r[j];
    });


    vec(ll) cnt(N+1);
    ll res = 0;
    vec(ll) ans(Q);

    ll l0 = 0, r0 = 0;
    for(ll qi:q){
        ll l1 = l[qi], r1 = r[qi];

        while(l0<l1){
            ll a = A[l0];
            cnt[a]--;
            if(cnt[a]&1) res--;
            l0++;
        }

        while(l0>l1){
            l0--;
            ll a = A[l0];
            if(cnt[a]&1) res++;
            cnt[a]++;
        }

        while(r0<r1){
            ll a = A[r0];
            if(cnt[a]&1) res++;
            cnt[a]++;
            r0++;
        }

        while(r0>r1){
            r0--;
            ll a = A[r0];
            cnt[a]--;
            if(cnt[a]&1) res--;
        }

        ans[qi] = res;
    }

    rep(i,Q) cout << ans[i] << endl;







}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
