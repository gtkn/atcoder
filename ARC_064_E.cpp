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
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------
using Pdl = pair<double,ll>;

void solve(){

    vec(ll) x(2),y(2),r(2);
    rep(i,2) cin >> x[i] >> y[i];

    ll N;
    cin >> N;

    rep(_,N){
        ll xi,yi,ri;
        cin >> xi >> yi >> ri;
        x.push_back(xi);
        y.push_back(yi);
        r.push_back(ri);
    }

    ll nn = N+2;
    vvec(double) costs(nn,vec(double)(nn));

    rep(i,nn)rep(j,i){
        ll dx,dy;
        dx = x[i]-x[j];
        dy = y[i]-y[j];

        double d = sqrt(dx*dx + dy*dy);
        costs[i][j] = max(d-r[i]-r[j], 0.);
        costs[j][i] = costs[i][j];
    }

    // rep(i,nn){
    //     rep(j,nn) cout << costs[i][j] << " "; cout << endl;
    // }


    vec(double) dp(nn,llINF);
    queue<Pdl> q; 
    auto qpush = [&](double c, double x){
        if(chmin(dp[x],c)) q.emplace(c,x);
    };

    qpush(0,0);

    while(!q.empty()){
        auto [c0, now] = q.front(); q.pop();
        if(dp[now] < c0) continue;
        rep(nxt,nn) qpush(c0+costs[now][nxt], nxt);
    }

    // rep(i,nn) cout << dp[i] << " "; cout << endl;

    printf("%.10f\r\n",dp[1]);





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
