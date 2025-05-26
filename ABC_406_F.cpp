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

ll op(ll a,ll b){return a+b;}
ll ee(){return 0;}


void solve(){
    ll N;
    cin >> N;
    vvec(ll) g(N);
    vec(ll) U(N-1),V(N-1);
    rep(i,N-1){
        ll a,b;
        cin >> a >> b;
        --a; --b;
        U[i] = a;
        V[i] = b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll Q;
    cin >> Q;


    vec(ll) ws;
    vec(ll) st(N), gl(N);
    auto f = [&](auto f, ll now, ll frm)->void{
        st[now] = ws.size();
        ws.push_back(1);

        for(ll nxt:g[now]) if(nxt!=frm){
            f(f,nxt,now);
        }

        gl[now] = ws.size();
    };
    f(f,0,0);
    assert(ws.size() == N);


    segtree<ll, op, ee> seg(ws);

    // rep(i,N) cerr << st[i] << " " << gl[i] << endl;


    while(Q--){
        ll t;
        cin >> t;
        if(t==1){
            ll x,w;
            cin >> x >> w;
            --x;
            seg.set(st[x], seg.get(st[x]) + w);

            // rep(i,N) cerr << seg.get(i) << " ";
            // cerr << endl;
        }else{
            ll y;
            cin >> y;
            --y;
            ll u = U[y], v = V[y];
            ll w1 = min(seg.prod(st[u], gl[u]), seg.prod(st[v], gl[v]));
            ll w2 = seg.all_prod() - w1;
            ll res = abs(w1 - w2);
            cout << res << endl;

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
