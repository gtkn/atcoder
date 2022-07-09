//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    ll N;
    vec(ll) d;
    vvec(Pll) g;


    Pll dfs(ll now, ll frm){
        vec(Pll) v;
        for(Pll gi:g[now]){
            if(gi.first==frm) continue;
            Pll x = dfs(gi.first, now);
            x.first += gi.second;
            v.push_back(x);
        }

        sort(all(v),[](Pll const& a,Pll const& b){
            return a.first-a.second > b.first-b.second;
        });

        ll p0=0,p1=0;
        rep(i,v.size()){
            if(d[now]-1>i && v[i].first>=v[i].second) p0 += v[i].first;
            else p0 += v[i].second;

            if(d[now]>i && v[i].first>=v[i].second) p1 += v[i].first;
            else p1 += v[i].second;
        }
        if(d[now]==0) p0=-llINF;

        return {p0,p1};
    }




    void solve(){
        cin >> N;
        d.resize(N);
        g.resize(N);
        
        rep(i,N) cin >> d[i];
        rep(i,N-1){
            ll u,v,w;
            cin >> u >> v >> w;
            u--;v--;
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
        }

        Pll x = dfs(1,1);
        ll ans = max(x.first,x.second);
        cout << ans << endl;

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
