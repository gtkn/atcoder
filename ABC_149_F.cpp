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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    ll N;
    vvec(ll) g;
    vec(Pll) e;
    vec(ll) sz;

    void dfs(ll now,ll frm){
        ll res = 1;
        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            dfs(nxt,now);
            res += sz[nxt];
        }
        sz[now]=res;
    }


    void solve(){
        ll N;
        cin >> N;
        g.resize(N);
        sz.resize(N);

        rep(_,N-1){
            ll a,b;
            cin >> a >> b;
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);
            e.emplace_back(a,b);
        }

        dfs(0,0);

        mint ans = 0;

        vec(mint) two(N+1);
        two[0]=1;
        rep(i,N) two[i+1] = two[i]*2;

        for(Pll ei:e){
            ll a,b; tie(a,b) = ei;
            ll nx = min(sz[a],sz[b]);
            mint aa=1,bb=1;
            aa -= two[nx].inv();
            bb -= two[N-nx].inv();
            ans += aa*bb;
        }

        ans += 1-two[N].inv();
        ans -= N*two[1].inv();

        cout << ans.val() << endl;

    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
