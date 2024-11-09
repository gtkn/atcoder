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
// using mint = modint;
// mint::set_mod(P);


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


ll op(ll a,ll b){
    return max(a,b);
}

ll ee(){
    return 0;
}


void solve(){
    ll N,Q;
    cin >> N >> Q;
    vec(ll) H(N);
    rep(i,N) cin >> H[i];

    vec(ll) l(Q),r(Q);
    rep(i,Q) cin >> l[i] >> r[i];
    rep(i,Q) --l[i];
    rep(i,Q) --r[i];


    vvec(Pll) qs(N);
    rep(i,Q) qs[r[i]].push_back({l[i],i}); 





    segtree<ll,op,ee> segh(H);
    vec(ll) ans(Q);
    vec(ll) v = {llINF};

    auto f = [&](ll x)->ll{
        ll n = v.size();
        ll l = 0, r = n;
        while(r-l>1){
            ll m = (l+r)/2;
            if(v[m] < x) r = m;
            else l = m;
        }
        return l;
    };



    repr(jj,N){
        for(auto [ii,idx]:qs[jj]){
            ll th = segh.prod(ii+1,jj+1);
            ll res = f(th);
            ans[idx] = res;
        }

        ll hj = H[jj];
        while(v.back() < hj){
            v.pop_back();
        }
        v.push_back(hj);

    }

    rep(i,Q) cout << ans[i] << nl;










    // segtree<ll,op,ee> segh(H);
    // segtree<ll,op,ee> segl(N+1);


    // vec(ll) ans(Q);

    // repr(jj,N){
    //     for(auto [ii,idx]:qs[jj]){
    //         // cerr << ii << " " << jj << " " << idx << endl;
    //         ll h0 = segh.prod(ii+1,jj+1);
    //         // cerr << h0 << endl;
    //         ll res = segl.prod(h0,N+1);
    //         ans[idx] = res;
    //         // cerr << res << endl;

    //         // ans[idx] = segl.prod(h0,N+1);
    //     }
    //     ll tmp = segl.prod(H[jj],N+1);
    //     segl.set(H[jj], tmp+1);
    // }

    // rep(i,Q) cout << ans[i] << nl;







}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
