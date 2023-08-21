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
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

void solve(){
    ll N;
    cin >> N;

    ll nn = N+N-1;

    vvec(ll) g(nn);
    vec(ll) par(nn,-1);
    vec(ll) sz(nn,1);
    vec(mint) cum(nn);


    auto findpar = [&](auto findpar, ll now)->ll{
        if(par[now]==-1) return now;
        par[now] = findpar(findpar, par[now]);
        return par[now];
    };


    for(ll i=N; i<nn; i++){
        ll p,q;
        cin >> p >> q;
        --p; --q;

        p = findpar(findpar, p);
        q = findpar(findpar, q);

        mint a = sz[p], b=sz[q];
        
        cum[p] = a/(a+b);
        cum[q] = b/(a+b);

        par[p] = i;
        par[q] = i;
        sz[i] = (a+b).val();

        g[i].push_back(p);
        g[i].push_back(q);
    }


    vec(mint) res(nn);
    
    auto dfs = [&](auto dfs, ll now, mint tot)->void{
        tot += cum[now];
        res[now] = tot;
        for(ll nxt:g[now]) dfs(dfs, nxt, tot);
    };

    dfs(dfs,nn-1,0);

    rep(i,N) cout << res[i].val() << " "; cout << endl;

 

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
