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
        ll N,M;
        cin >> N >> M;

        vector<set<ll>> v(M+1);
        rep1(i,N){
            ll ai; cin >> ai;
            rep(_,ai){
                ll xi; cin >> xi;
                v[xi].insert(i);
            }
        }

        ll mm = N+M+10;
        vvec(ll) g(mm);
        rep1(xi,M){
            for(ll si:v[xi]){
                g[si].push_back(N+xi);
                g[N+xi].push_back(si);
            }
        }
        for(ll si:v[1]){
            g[0].push_back(si);
        }
        for(ll si:v[M]){
            g[si].push_back(N+M+1);
        }


        vec(ll) dp(mm,llINF);
        queue<Pll> q;
        auto qpush = [&](ll _cost, ll _now){
            if(chmin(dp[_now], _cost)) q.emplace(_cost,_now);
        };
        qpush(0,0);

        while(!q.empty()){
            ll cost,now;
            tie(cost,now) = q.front();
            q.pop();

            if(dp[now]<cost) continue;

            for(ll nxt:g[now]) qpush(cost+ (nxt>N? 1 : 0) , nxt);
        }

        if(dp[N+M+1]>=llINF) dame;
        ll ans = dp[N+M+1]-1;
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
