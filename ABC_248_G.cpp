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
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

//------------------------------------------------

using mm = map<ll,pair<mint,mint>>;

struct Solver{
    ll N;
    vec(ll) A;
    vvec(ll) g;
    vec(bool) used;

    mint ans = 0;

    mm dfs(ll now){
        used[now]=true;

        mm res;
        res[A[now]] = {1,1};

        for(ll to:g[now]){
            if(used[to]) continue;
            mm tmp = dfs(to);

            for(auto mi:res)for(auto mj:tmp){
                ll x = __gcd(mi.first, mj.first);
                ans += x*(mi.second.first*mj.second.second + mi.second.second*mj.second.first);
            }

            for(auto mi:tmp){
                ll x = __gcd(mi.first,A[now]);
                res[x].first += mi.second.first;
                res[x].second += mi.second.first + mi.second.second;
            }
        }
        return res;
    }


    void solve(){
        cin >> N;
        A.resize(N);
        g.resize(N);
        used.resize(N);

        rep(i,N) cin >> A[i];
        rep(_,N-1){
            ll u,v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0);

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
