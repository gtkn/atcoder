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

    struct edge{
        ll to,id,dr;
        edge(ll to=0, ll id=0, ll dr=0):to(to),id(id),dr(dr){}
    };


    ll N,M;
    ll A[200020];
    ll B[200020];
    vvec(edge) g;
    vec(ll) ans;
    vec(bool) used;

    void dfs(ll now){
        if(used[now]) return;
        used[now] = true;

        for(edge gi:g[now]){
            if(ans[gi.id]>=0) continue;
            ans[gi.id] = gi.dr;
            if(!used[gi.to]) dfs(gi.to);
        }

    }




    void solve(){
        cin >> N >> M;
        rep(i,M) cin >> A[i];
        rep(i,M) cin >> B[i];
        
        g.resize(N+1);
        rep(i,M){
            ll a,b;
            a = A[i]; b=B[i];
            g[a].emplace_back(b,i,0);
            g[b].emplace_back(a,i,1);
        }

        ans = vec(ll)(M,-1);
        used = vec(bool)(N+1);

        rep1(i,N) dfs(i);

        for(ll ai:ans) cout << ai; cout << endl;


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
