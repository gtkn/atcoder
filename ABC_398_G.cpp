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
    vvec(ll) g(N);
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vec(bool) v(N),used(N);
    vec(ll) ids(N);

    auto f = [&](auto f, ll now, ll frm, ll id)->ll{
        ids[now] = id;
        used[now] = true;
        ll res = 0;
        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            v[nxt] = !v[now];
            res += f(f,nxt,now,id);
            res++;
        }
        return res;
    };

    ll idcnt = 0;
    rep(i,N){
        if(used[i]) continue;
        f(f,i,i,idcnt);
        idcnt++;
    }

    vvec(ll) vv(idcnt);
    rep(i,N){
        vv[ids[i]].push_back(i);
    }

    ll gr = 0;  
    for(auto vi:vv){
        ll tmp = 0;
        ll c0=0,c1=0;
        for(ll vii:vi){
            if(vii==0){
                tmp += c1;
                c0++;
            }else{
                tmp += c0;
                c1++;
            }            
        }
        gr ^= tmp;
    }

    if(gr==0){
        cout << "Takahashi" << nl;
    }else{
        cout << "Aoki" << nl;
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
