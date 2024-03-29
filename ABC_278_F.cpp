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

struct Solver{

    ll N;
    vvec(ll) g;
    vvec(ll) dp;

    ll dfs(ll state, ll now){
        if(dp[state][now]!=0) return dp[state][now];

        bool win = false;
        for(ll nxt:g[now]){
            if(bit(state,nxt)) continue;
            if(dfs( (state | (1<<nxt)) ,nxt) == -1) win=true;
        }

        dp[state][now] = (win ? 1 : -1);
        return dp[state][now];
    }



    void solve(){
        cin >> N;
        g.resize(N+1);
        dp = vvec(ll)(1<<N, vec(ll)(N+1));

        vec(string) S(N);
        rep(i,N) cin >> S[i];
        rep(i,N)rep(j,N){
            if(i==j) continue;
            if(S[i].back() == S[j].front()) g[i].push_back(j);
        }
        rep(i,N) g[N].push_back(i);


        string ans = "Second";
        if( dfs( 0, N ) == 1) ans = "First";

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
