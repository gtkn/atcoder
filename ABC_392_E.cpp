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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,M;
    cin >> N >> M;

    vec(ll) A(M),B(M);  
    rep(i,M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    // vvec(Pll) g(N);
    // rep(i,M){
    //     g[A[i]].push_back({B[i],i});
    //     g[B[i]].push_back({A[i],i});
    // }


    vec(bool) used(M);
    dsu d(N);
    rep(i,M){
        if(d.same(A[i],B[i])) continue;
        d.merge(A[i],B[i]);
        used[i] = true;
    }


    auto grps = d.groups();
    ll nn = grps.size();
    
    vec(ll) ls(nn);
    rep(i,nn) ls[i] = grps[i][0];

    vec(ll) pos(N);
    rep(i,nn)for(ll x:grps[i]) pos[x] = i;


    vvec(ll) cands(nn);
    rep(i,M){
        if(used[i]) continue;
        ll x = pos[A[i]];
        cands[x].push_back(i);
    }

    // cerr << "ok" << nl;


    vec(Pll) v(nn);
    rep(i,nn) v[i] = {i,cands[i].size()};
    sort(all(v),[](Pll x, Pll y){return x.second>y.second;});


    vec(tri) ans;
    ll v0f = v[0].first;
    rep(_,nn-1){
        ll idx = cands[v0f].back();
        cands[v0f].pop_back();
        ll a = A[idx];

        ll vbf = v.back().first;
        ans.push_back({idx,a,ls[vbf]});

        d.merge(a,ls[vbf]);
        cands[v0f].insert(cands[v0f].end(), all(cands[vbf]));

        v.pop_back();
    }

    cout << ans.size() << nl;
    for(auto [a,b,c]:ans){
        cout << a+1 << ' ' << b+1 << ' ' << c+1 << nl;
    }
 
    // assert(d.groups().size()==1);


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
