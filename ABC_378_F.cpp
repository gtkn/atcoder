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

    vvec(ll) g(N);
    vec(ll) d(N);
    rep(_,N-1){
        ll u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u]++;
        d[v]++;
    }

    // dsu uf(N);
    // rep(i,N)for(ll j:g[i]){
    //     if(d[i]==3 && d[j]==3) uf.merge(i,j);
    // }

    // ll ans = 0;
    // for(auto grp:uf.groups()){
    //     ll cnt = 0;
    //     for(ll i:grp)for(ll j:g[i]){
    //         if(d[j]==2) cnt++;
    //     }
    //     ans += cnt*(cnt-1)/2;
    // }

    // cout << ans << endl;





    ll ans = 0;

    auto f = [&](auto f, ll now, ll frm)->ll{
        // cerr << "now " << now << " , " << d[now] << endl;

        vec(Pll) v;
        for(ll nxt:g[now])if(nxt!=frm){
            ll x = f(f,nxt,now);
            if(d[nxt]==2) v.emplace_back(x,0);
            else v.emplace_back(x,1);
        }
        // for(ll vi:v) cerr << vi << " "; cerr << endl;


        if(d[now]==3){
            ll vtot = 0;
            for(auto [v0,v1]:v){
                ans += v0*vtot;
                vtot += v0;
            }
            return vtot;
        }else if(d[now]==2){
            for(auto [v0,v1]:v){
                if(v1==1) ans += v0;
            }
            return 1LL;
        }else{
            return 0LL;
        }

    };

    f(f,0,0);

    cout << ans << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
