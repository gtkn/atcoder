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
using ll4 = tuple<ll,ll,ll,ll>;

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


struct S{
    Pll p1,p2;
};

S op(S l,S r){
    map<ll,ll> m;
    vec(Pll) v = {l.p1, l.p2, r.p1, r.p2};
    for(Pll vi:v) m[vi.first] += vi.second;

    vec(Pll) v2;
    for(auto mi:m) v2.push_back(mi);
    reverse(all(v2));

    return {v2[0], v2[1]};
}

S ee(){return S{{-1,0},{-2,0}};}



void solve(){
    ll N,Q;
    cin >> N >> Q;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    vec(S) v(N);
    rep(i,N) v[i] = S{ {A[i],1},{0,0} };

    segtree<S, op, ee> seg(v);

    while(Q--){
        ll t; cin >> t;
        if(t==1){
            ll p,x; cin >> p >> x;
            seg.set(p-1, S{ {x,1},{0,0} } );
        }else{
            ll l,r; cin >> l >> r;
            S res = seg.prod(l-1,r);
            cout << res.p2.second << endl;
        }
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
