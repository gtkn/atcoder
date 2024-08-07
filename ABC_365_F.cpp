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


struct S{
    ll l,r,d;
    S(ll l=0, ll r=llINF, ll d=-1):l(l),r(r),d(d){}

    Pll operator()(ll s){
        if(d==-1){ // A
            if(s<l) return {l,l-s};
            if(s>r) return {r,s-r};
            return {s,0};
        }else{
            return {r, d+abs(s-l)};
        }
    }

};

S op(S a, S b){
    if(a.d==-1){
        if(b.d==-1){
            if(a.r < b.l) return S(a.r, b.l, b.l-a.r);
            if(a.l > b.r) return S(a.l, b.r, a.l-b.r);
            return S(max(a.l,b.l), min(a.r,b.r), -1);
        }else{ // A->B
            auto [t,d] = a(b.l);
            return S(t, b.r, b.d+d);
        }
    }else{ // B->?
        auto [t,d] = b(a.r);
        return S(a.l, t, a.d+d);

    }
}
S ee(){
    return S();
}





void solve(){
    ll N;
    cin >> N;

    vec(ll) L(N+1),U(N+1);
    rep1(i,N) cin >> L[i] >> U[i];

    segtree<S,op,ee> seg(N+1);
    rep1(i,N) seg.set(i,S(L[i],U[i],-1));

    ll Q;
    cin >> Q;
    while(Q--){
        ll sx,sy,tx,ty;
        cin >> sx >> sy >> tx >> ty;
        if(sx>tx) swap(sx,tx), swap(sy,ty);
        S f = seg.prod(sx,tx);
        auto [y,d] = f(sy);
        d += abs(y-ty);
        d += abs(sx-tx);
        cout << d << endl;
    }





    // ll Q;
    // cin >> Q;
    // vec(ll) sx(Q),sy(Q),tx(Q),ty(Q);
    // rep(i,Q) cin >> sx[i] >> sy[i] >> tx[i] >> ty[i];


    // vector<set<ll>> vs(N+1);
    // // vvec(ll) vv(N+1);
    // // rep1(i,N) vv[i].push_back(L[i]);
    // // rep1(i,N) vv[i].push_back(L[i]);

    // vec(Pll) rng(N+1);

    // rep1(i,N-1){
    //     ll l = max(L[i],L[i+1]);
    //     ll u = min(U[i],U[i+1]);
    //     vs[i].insert(l);
    //     vs[i].insert(u);
    //     rng[i] = {l,u};
    // }

    // rep(i,Q){
    //     vs[sx[i]].insert(sy[i]);
    // }
    // rep(i,Q){
    //     vs[tx[i]].insert(ty[i]);
    // }

    // rep1(i,N-1){
    //     for(ll y:vs[i]){
    //         if(rng[i].first<=y && y<=rng[i].second){
    //             vs[i+1].insert(y);
    //         }
    //     }
    // }


    // vvec(ll) vv(N+1);
    // rep1(i, N) {
    //     for (ll y : vs[i]) {
    //         vv[i].push_back(y);
    //     }
    // }


    // ll nn = 0;
    // // rep1(i,N) nn += vs[i].size();

    // map<Pll,ll> mp;
    // rep1(x,N)for(ll y:vv[x]){
    //     mp[{x,y}] = nn++;
    // }


    // vvec(Pll) g(nn);
    // rep1(x,N){
    //     ll sz = g[x].size();
    //     rep(i,sz-1){
    //         ll y0 = vv[x][i];
    //         ll y1 = vv[x][i+1];
    //         g[mp[{x,y0}]].emplace_back(mp[{x,y1}],abs(y1-y0));
    //         g[mp[{x,y1}]].emplace_back(mp[{x,y0}],abs(y1-y0));
    //     }
    // }


    // rep1(x,N-1){
    //     for(ll y:vv[x]){
    //         if(rng[x].first <= y && y <= rng[x].second){
    //             g[mp[{x,y}]].emplace_back(mp[{x+1,y}],1);
    //         }
    //     }
    // }


    // ll rt = sqrt(N);
    // map<Pll,ll> wp;   
    // for(ll a = 1; a<=N; a+=rt){
    //     ll b = a+rt;
    //     map<Pll,ll> dp;
    //     for(ll y:vv[a]) dp[ {mp[{a,y}], mp[{a,y}] } ] = 0;
    //     for(ll x=a; x<a+rt; x++){

    //     }
    // }









}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
