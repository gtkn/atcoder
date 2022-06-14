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

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c,d;
        edge(ll to=0, ll c=0, ll d=0):to(to),c(c),d(d){}
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

        vvec(edge) g(N);
        rep(_,M){
            ll a,b,c,d;
            cin >> a >> b >> c >> d;
            a--;b--;
            g[a].emplace_back(b,c,d);
            g[b].emplace_back(a,c,d);
        }


        vec(ll) dp(N,llINF);
        priority_queue<Pll,vector<Pll>,greater<Pll>> pq;
        if(chmin(dp[0],0LL)) pq.emplace(0,0);

        while(!pq.empty()){
            Pll pq0 = pq.top();
            pq.pop();
            ll now = pq0.second;
            ll t0 = pq0.first;
            if(dp[now]<t0) continue;

            for(edge gi:g[now]){
                ll x0 = -t0-1+sqrt(gi.d);
                ll t1 = llINF;
                
                rep(dx,5){
                    ll x = max(x0-2,t0)+dx;
                    chmin(t1,x+gi.c+ (gi.d)/(x+1) );
                }
                if(chmin(dp[gi.to], t1)) pq.emplace(t1, gi.to);
            }
        }

        ll ans = dp[N-1];
        if(ans==llINF) ans=-1;
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
