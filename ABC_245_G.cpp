//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (int i = (n); i > 0; --i)
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
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

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
        ll N,M,K,L;
        cin >> N >> M >> K >> L;
        vec(ll) A(N+1);
        rep1(i,N) cin >> A[i];        
        vec(ll) B(L);
        rep(i,L) cin >> B[i];

        vvec(Pll) g(N+1);
        rep(_,M){
            ll u,v,c;
            cin >> u >> v >> c;
            g[u].emplace_back(v,c);
            g[v].emplace_back(u,c);
        }
        for(ll bi:B) g[0].emplace_back(bi,0);


        vvec(ll) dp(N+1,vec(ll)(2,llINF));

        auto cmp = [](abc x, abc y){
            return x.c>y.c;
        };
        priority_queue<abc,vector<abc>, decltype(cmp)> q{cmp};

        auto qpush = [&](ll to,ll id,ll c){
            if(!chmin(dp[to][(id!=A[to])],c)) return;
            q.emplace(to,id,c);
        };
        qpush(0,-1,0);

        while(!q.empty()){
            abc q0 = q.top();
            q.pop();
            ll now,id,c0;
            now = q0.a; id = q0.b; c0 = q0.c;

            //cout << now << " ; " << id << ", " << c0 << endl;

            if(dp[now][id!=A[now]] < c0) continue;

            for(Pll gi:g[now]){
                qpush(gi.first, ( (id<0)? A[gi.first] : id ), c0+gi.second);
            }
        }

        rep1(i,N){
            cout << ( (dp[i][1]==llINF)? -1 : dp[i][1] ) << " ";
        }
        cout << endl;

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
