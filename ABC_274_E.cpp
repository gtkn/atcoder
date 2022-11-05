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
        ll a,b;
        double c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,M;
        cin >> N >> M;
        ll nm = N+M;
        vec(ll) xp(nm+1),yq(nm+1);
        rep1(i,nm) cin >> xp[i] >> yq[i];

        vvec(double) dist(nm+1,vec(double)(nm+1));
        rep(i,nm+1)rep(j,nm+1){
            double dx = xp[i]-xp[j];
            double dy = yq[i]-yq[j];
            dist[i][j] = sqrt(dx*dx+dy*dy);
        }


        vvec(double) dp(1<<(nm+1),vec(double)(nm+1,1e12) );
        dp[1][0] = 0.;
        rep(used,(1<<(nm+1))-1){
            ll sp = 1;
            for(ll i=N+1; i<=nm; i++) if(bit(used,i)) sp*=2;
            
            rep(now,nm+1)rep(nxt,nm+1){
                if(bit(used,nxt)) continue;
                chmin(dp[used|(1<<nxt)][nxt], dp[used][now] + dist[now][nxt]/sp );
            }
        }

        double ans = 1e12;
        ll mask = (1<<(N+1))-1;
        rep(used,(1<<(nm+1)))rep(now,nm+1){
            ll sp = 1;
            for(ll i=N+1; i<=nm; i++) if(bit(used,i)) sp*=2;
            if((used&mask)==mask) chmin(ans, dp[used][now] + dist[now][0]/sp);
        }

        printf("%.7f\r\n",ans);


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
