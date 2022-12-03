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
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,M,K;
        cin >> N >> M >> K;


        vvec(Pll) g(N);
        rep(_,M){
            ll ui,vi,ai;
            cin >> ui >> vi >> ai;
            ui--;vi--;
            g[ui].emplace_back(vi,ai);
            g[vi].emplace_back(ui,ai);
        }


        set<ll> s;
        rep(_,K){
            ll si;cin >> si;
            si--;
            s.insert(si);
        }

        vvec(ll) dp(N,vec(ll)(2,llINF));

        queue<Pll> q;
        auto qpush = [&](ll to,ll cost, ll ab){
            if(chmin(dp[to][ab],cost)) q.emplace(to,ab);
        };

        qpush(0,0,1);
        if(sfind(s,0)) qpush(0,0,0);

        while(!q.empty()){
            Pll q0 = q.front();
            q.pop();

            ll now = q0.first;
            ll ab = q0.second;

            for(Pll gi:g[now]){
                if(gi.second!=ab) continue;
                qpush(gi.first, dp[now][ab]+1, ab);
                if(sfind(s,gi.first)) qpush(gi.first, dp[now][ab]+1, 1-ab);
            }
        }

        ll ans = min(dp[N-1][0],dp[N-1][1]);
        if(ans==llINF) ans = -1;
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
