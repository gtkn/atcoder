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
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N,M;
    cin >> N >> M;
    vec(ll) X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];
    vec(ll) P(M),Q(M);
    rep(i,M) cin >> P[i] >> Q[i];

    ll nn = 1+N+M;
    vec(Pll) pos(nn);
    pos[0] = {0,0};
    rep(i,N) pos[i+1] = {X[i],Y[i]};
    rep(i,M) pos[N+1+i] = {P[i],Q[i]};


    auto calc_speed = [&](ll st){
        ll res = 1;
        rep(i,M) if(bit(st,N+1+i)) res*=2;
        return res;
    };

    vvec(double) dist(nn,vec(double)(nn));
    rep(i,nn)rep(j,nn){
        ll dx = pos[i].first - pos[j].first;
        ll dy = pos[i].second - pos[j].second;
        dist[i][j] = sqrt(dx*dx + dy*dy);
    }


    ll b = (1<<nn);
    vvec(double) dp(b,vec(double)(nn,llINF));
    dp[0][0] = 0;

    rep(st,b)rep(now,nn){
        ll spd = calc_speed(st);
        rep(nxt,nn){
            if(bit(st,nxt)) continue;
            chmin(dp[st|(1<<nxt)][nxt], dp[st][now] + dist[now][nxt]/spd);
        }
    }

    double ans = llINF;
    ll chk = (1<<(N+1)) - 1;
    rep(st,b){
        if( (st&chk) == chk ) chmin(ans,dp[st][0]);
    }

    printf("%.10f\r\n",ans);








}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
