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

double op(double a, double b){ return min(a,b);}
double ee(){return llINF;}
double mapping(double f, double x){return f+x;}
double composition(double f,double g){return f+g;}
double id(){return 0;}

void solve(){
    ll N,K;
    cin >> N >> K;

    ll sx,sy;
    cin >> sx >> sy;
    vec(ll) X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];

    auto f = [](double x0, double y0, double x1, double y1 ){
        double dx = x0-x1;
        double dy = y0-y1;
        return sqrt(dx*dx + dy*dy);
    };

    vec(double) ds(N);
    rep(i,N) ds[i] = f(sx,sy,X[i],Y[i]);

    vec(double) dc(N);
    rep(i,N-1) dc[i] = f(X[i],Y[i],X[i+1],Y[i+1]);
    dc[N-1] = ds[N-1];


    vec(double) v(N+1,llINF);
    lazy_segtree<double, op, ee, double, mapping, composition, id> ls(v);
    ls.set(0, ds[0]);

    rep1(i,N-1){
        ll l = max(i-K,0LL);
        ls.set( i, ls.prod(l,i) + ds[i-1]+ds[i] );
        ls.apply(l,i, dc[i-1]);
    }

    double ans = ls.prod(N-K,N) + ds[N-1];
    printf("%.8f\r\n",ans);



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
