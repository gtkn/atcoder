//title
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
using mint = modint998244353;
// using mint = modint;
// mint::set_mod(P);


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


double get_dist(ll x1, ll y1, ll x2, ll y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


void solve(){
    ll N,M;
    cin >> N >> M;

    vec(ll) X(N),Y(N);
    vec(ll) P(M),Q(M);

    rep(i,N) cin >> X[i] >> Y[i];
    rep(i,M) cin >> P[i] >> Q[i];


    ll nn = N + 1 + M;
    ll b = (1<<nn);

    vec(ll) xs(nn),ys(nn);
    rep(i,N){
        xs[i] = X[i];
        ys[i] = Y[i];
    }
    xs[N] = 0;
    ys[N] = 0;
    rep(i,M){
        xs[N+1+i] = P[i];
        ys[N+1+i] = Q[i];
    }


    vvec(double) dist(nn,vec(double)(nn,0));
    rep(i,nn)rep(j,nn){
        dist[i][j] = get_dist(xs[i],ys[i],xs[j],ys[j]);
    }

    // rep(i,nn){
    //     rep(j,nn) cerr << dist[i][j] << " ";
    //     cerr << endl;
    // }

    vvec(double) dp(b,vec(double)(nn,llINF));
    dp[(1<<N)][N] = 0;


    auto get_speed = [&](ll bit){
        double speed = 1;
        for(ll i=N+1; i<nn; i++) if(bit & (1<<i)) speed *=2;
        return speed;
    };

    rep(bit,b){
        double speed = get_speed(bit);
        rep(i,nn){
            if(bit & (1<<i)){
                rep(j,nn){
                    if(bit & (1<<j)) continue;
                    chmin(dp[bit|(1<<j)][j], dp[bit][i] + dist[i][j]/speed);
                }
            }
        }
    }

    ll mask = (1<<N)-1;

    double ans = llINF;
    rep(bit,b){
        if( (bit&mask)!=mask ) continue;
        double speed = get_speed(bit);
        rep(i,N){
            chmin(ans, dp[bit][i] + dist[i][N]/speed);
        }
    }

    printf("%.10f\n", ans);



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
