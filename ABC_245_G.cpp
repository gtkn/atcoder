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

        vec(ll) A(N);
        rep(i,N) cin >> A[i];
        vec(ll) B(L);
        rep(i,L) cin >> B[i];
        rep(i,L) B[i]--;

        vvec(Pll) g(N);
        rep(_,M){
            ll u,v,c;
            cin >> u >> v >> c;
            u--;v--;
            g[u].emplace_back(v,c);
            g[v].emplace_back(u,c);
        }

        vec(ll) dp1(N,-1),dp2(N,-1);
        priority_queue<tuple<ll,ll,ll>> q;
        for(ll bi:B) q.emplace(0,bi,A[bi]);

        vec(ll) from(N),cnt(N);
        while(!q.empty()){
            auto [c,x,y] = q.top();
            q.pop();
            if(cnt[x]==0){
                dp1[x]=-c;
                from[x]=y;
            }else if(cnt[x]==1 && from[x]!=y){
                dp2[x]=-c;
            }else continue;

            cnt[x]++;
            for(Pll to:g[x]) q.emplace(c-to.second, to.first, y);
        }

        rep(i,N) cout << ( (from[i]!=A[i])? dp1[i] :dp2[i] ) <<" ";
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
