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
    ll N,M;
    cin >> N >> M;

    vec(ll) D(N);
    rep(i,N) cin >> D[i];

    vvec(ll) g(N);
    rep(i,M){
        ll A,B;
        cin >> A >> B;
        --A,--B;
        g[A].push_back(B);
        g[B].push_back(A);
    }

    dsu uf(N);
    rep(i,N)for(ll j : g[i]) uf.merge(i,j);

    vec(ll) rem(N);
    rep(i,N) rem[i] = D[i] - g[i].size();

    // rep(i,N) cerr << i << " " << rem[i] << endl;

    ll tot = 0;
    rep(i,N){
        if(rem[i] < 0) dame;
        tot += rem[i];
    }

    if((N-M-1)*2 != tot) dame;

    // for(auto &grp : uf.groups()){
    //     for(ll x:grp) cerr << x << ' '; cerr << endl;
    // }


    vvec(ll) vv;
    for(auto &grp : uf.groups()){
        vec(ll) v;
        for(ll ii:grp){
            if(rem[ii]>0) v.push_back(ii);
        }
        if(v.empty()) dame;
        vv.push_back(v);
    }

    sort(all(vv), [&](vec(ll) &a, vec(ll) &b){
        ll ra = 0, rb = 0;
        for(ll ii:a) ra += rem[ii];
        for(ll ii:b) rb += rem[ii];
        return ra < rb;
    });

    vec(Pll) ans;
    vec(ll) a = vv.back(); vv.pop_back();

    while(!vv.empty()){
        vec(ll) b = vv.back(); vv.pop_back();

        if(a.empty() || b.empty()) dame;

        ll ai = a.back(); a.pop_back();
        ll bi = b.back(); b.pop_back();

        // cerr << ai << " " << bi << " , " << rem[ai] << " " << rem[bi] << endl;

        ans.push_back({ai,bi});
        rem[ai]--;
        rem[bi]--;

        if(a.size() < b.size()) swap(a,b);
        for(ll ii:b) a.push_back(ii);
        if(rem[ai]>0) a.push_back(ai);
        if(rem[bi]>0) a.push_back(bi);

    }

    for(auto [ai,bi]:ans) cout << ai + 1 << ' ' << bi + 1 << nl;    


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
