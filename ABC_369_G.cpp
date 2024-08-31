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



Pll op(Pll a, Pll b){
    if(a.first > b.first) return a;
    return b;
}
Pll ee(){return {-1,-1};}
Pll mapping(ll f, Pll x){return {x.first+f, x.second};}
ll composition(ll f,ll g){return f+g;}
ll id(){return 0;}
// lazy_segtree<ll, op, ee, ll, mapping, composition, id> ls(N+1);




void solve(){
    ll N;
    cin >> N;

    vec(ll) U(N-1),V(N-1),L(N-1);
    rep(i,N-1) cin >> U[i] >> V[i] >> L[i];
    rep(i,N-1) U[i]--, V[i]--;

    vvec(Pll) g(N);
    rep(i,N-1){
        g[U[i]].emplace_back(V[i],L[i]);
        g[V[i]].emplace_back(U[i],L[i]);
    }


    vec(ll) idmap;
    vec(Pll) dist;
    // vec(Pll) lr(N);
    vec(ll) rs(N);
    vec(ll) par(N);
    

    auto f = [&](auto f, ll now, ll frm, ll p, ll d)->void{
        ll l = dist.size();
        dist.emplace_back(d,l);
        idmap.push_back(now);
        par[l] = p;
        // cerr << l << "<-" << p << endl;
        // rs.push_back(l);

        for(auto [nxt,len]:g[now]){
            if(nxt==frm) continue;
            f(f,nxt,now,l,d+len);
        }
        rs[l] = dist.size();
        // lr[now] = {l,dist.size()};
    };

    f(f,0,0,0,0);

    // rep(i,N) cerr <<rs[i] << endl;
    // rep(i,N) cerr << par[i] << endl;

    lazy_segtree<Pll,op,ee,ll,mapping,composition,id> lseg(dist);

    vec(bool) used(N);
    // used[0] = true;
    // cerr << "--- " << endl;
    // rep(i,N) cerr << lseg.get(i).first << " "; cerr << endl;

    ll res = 0;
    rep(_,N){
        auto [dmax,idx] = lseg.all_prod();
        res += dmax*2;

        cout << res << endl;

        ll now = idx;
        while(!used[now]){
            // cerr << now << endl;
            lseg.apply(now, rs[now], -lseg.get(now).first);
            used[now] = true;
            now = par[now];
        }

        // cerr << "--- " << endl;
        // rep(i,N) cerr << lseg.get(i).first << " "; cerr << endl;

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
