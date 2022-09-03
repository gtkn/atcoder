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

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

Pll op(Pll a,Pll b){
    if(a.first<=b.first) return a;
    return b;
}
Pll ee(){return {llINF,llINF};}


struct Solver{


    void solve(){
        ll N, M ;
        cin >> N >> M ;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        vvec(ll) g(N);
        rep(_,M){
            ll u,v;
            cin >> u >> v;
            u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }


        vec(ll) dp(N);
        rep(i,N){
            for(ll j:g[i]) dp[i] += A[j];
        }

        vec(ll) cost(N);

        ll ans = 0;
        priority_queue<Pll,vector<Pll>,greater<Pll>> q;
        rep(i,N) q.emplace(dp[i],i);

        vec(bool) used(N);
        while(!q.empty()){
            Pll q0 = q.top();
            q.pop();
            ll now = q0.second;

            if(q0.first>dp[now]) continue;

            chmax(ans,q0.first);
            used[now] = true;

            for(ll to:g[now]){
                if(used[to]) continue;
                dp[to]-=A[now];
                q.emplace(dp[to],to);
            }
        }

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
