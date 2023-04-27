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
using ld = long double;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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
    ll N,M;
    vvec(Pll) g;
    vec(ll) memo;
    string ans = "Yes";

    void dfs(ll now,ll frm, ll cost){
        // cout << now << ", " << frm << " , " << cost << endl;
        if(memo[now]!=llINF &&  memo[now]!=cost){
            ans="No";
            return;
        }
        
        
        if(memo[now]==llINF){
            memo[now]=cost;
            for(Pll gi:g[now]){
                if(gi.first == frm) continue;
                dfs(gi.first, now, cost+gi.second);
            }

        }

    }


 
    void solve(){
        cin >> N >> M;
        g.resize(N);
        memo = vec(ll)(N,llINF);


        rep(i,M){
            ll l,r,d;
            cin >> l >> r >> d;
            l--; r--;
            g[l].emplace_back(r,d);
            g[r].emplace_back(l,-d);
        }

        rep(st,N){
            if(memo[st]==llINF) dfs(st,st,0);
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
