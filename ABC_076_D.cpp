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
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

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
    ll N;
    cin >> N;

    ll nn = N+2;
    vec(double) t(nn),v(nn);
    rep1(i,N) cin >> t[i];
    rep1(i,N) cin >> v[i];


    vec(double) l(nn),r(nn);
    double tot = 0;
    rep(i,nn){
        l[i] = tot;
        tot += t[i];
        r[i] = tot;
    }


    auto ff = [&](double now, ll idx){
        if(now < l[idx]) return v[idx] + abs(now-l[idx]);
        else if(now < r[idx]) return v[idx];
        return v[idx] + abs(now-r[idx]);
    };

    double prev = 0.;
    double ans = 0.;

    for(double ti = 0.; ti<=tot; ti+=0.5){
        double nowv = llINF;
        rep(i,nn) chmin(nowv, ff(ti,i));
        
        ans += (prev + nowv)*0.25;
        prev = nowv;
    }

    printf("%.5f\r\n",ans);




    // auto f = [](ll v0, ll v1, ll tt, ll th){
    //     double res = 0;
    //     if( abs(v0-v1)>tt ) return res;

    //     if( v0 > v1) swap(v0,v1);


    //     double t0 = v1-v0;
    //     res += t0*t0*0.5;
    //     res += v0*t0;

    //     double t1 = tt-t0;
    //     res += t1*t1*0.25;
    //     res += t1*v1;

    //     double t2 = 1.*v0 + t0 + t1*0.5 - 1.*th;
    //     if(t2>0.) res -= t2*t2;

    //     return res;
    // };


    


    // vvec(double) dp(N+1,vec(double)(101,-llINF));
    // dp[0][0] = 0;

    // t.push_back(0); v.push_back(0);

    // rep(i,N)rep(j,101){
    //     if(dp[i][j]<=-llINF) continue;

    //     rep(k,min(v[i],v[i+1])+1){
    //         chmax(dp[i+1][k], dp[i][j] + f(j,k,t[i], v[i]));
    //     }
    // }


    // printf("%.5f\r\n",dp[N][0]);



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
