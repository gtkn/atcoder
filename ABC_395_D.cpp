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
    ll N,Q;
    cin >> N >> Q;

    vec(ll) pos(N);
    rep(i,N) pos[i] = i;

    vec(ll) p(N);
    vec(ll) q(N);
    rep(i,N) p[i] = i;
    rep(i,N) q[i] = i;


    while(Q--){
        ll t;
        cin >> t;
        if(t==1){
            ll a,b;
            cin >>  a >> b;
            --a; --b;

            pos[a] = q[b];
        }
        if(t==2){
            ll a,b;
            cin >> a >> b;
            --a; --b;

            ll pa = q[a];
            ll pb = q[b];

            p[pa] = b;
            p[pb] = a;
            q[a] = pb;
            q[b] = pa;
        }
        if(t==3){
            ll a;
            cin >> a;
            --a;
            cout << p[pos[a]]+1 << endl;
        }

    }


    


    // vector<set<ll>> mem(N);
    // rep(i,N) mem[i].insert(i);

    // while(Q--){
    //     ll t;
    //     cin >> t;
    //     if(t==1){
    //         ll a,b;
    //         cin >>  a >> b;
    //         --a; --b;
    //         pos[a] = b;
    //         mem[a].erase(a);
    //         mem[b].insert(a);            
    //     }
    //     if(t==2){
    //         ll a,b;
    //         cin >> a >> b;
    //         --a; --b;
    //         for(ll x:mem[a]){
    //             pos[x] = b;
    //         }
    //         for(ll x:mem[b]){
    //             pos[x] = a;
    //         }
    //         swap(mem[a],mem[b]);
    //     }
    //     if(t==3){
    //         ll a;
    //         cin >> a;
    //         --a;
    //         cout << pos[a]+1 << endl;            
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
