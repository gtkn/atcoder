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
using Pdl = pair<double,ll>;

using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

const double EPS = 1e-10;

void solve(){
    ll N;
    cin >> N;
    vec(ll) x(N),y(N),t(N),r(N);
    rep(i,N) cin >> x[i] >> y[i] >> t[i] >> r[i];

    auto dist = [&](ll i, ll j)->double{
        return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
    };

    vvec(double) c(N,vec(double)(N));
    rep(i,N)rep(j,N){
        double d = dist(i,j);
        double v = min(t[i],r[j]);
        c[i][j] = d/v;
    }

    vec(double) dp(N,llINF);
    priority_queue<Pdl,vector<Pdl>,greater<Pdl>> pq;

    auto qpush = [&](double time, ll pos)->void{
        // cerr << time << " " << pos << endl;
        if(chmin(dp[pos],time)) pq.push({time,pos});
        // cerr << dp[pos] << endl;
    };
    qpush(0,0);

    while(!pq.empty()){
        auto [time,now] = pq.top(); pq.pop();
        if(dp[now]+EPS<time) continue;
        rep(nxt,N) qpush(time+c[now][nxt],nxt);
    }

    sort(all(dp), greater<double>());
    double ans = 0;
    repr(i,N-1){
        // cerr << dp[i] << endl;
        chmax(ans, dp[i]+i);
    }

    printf("%.10f\n",ans);



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
