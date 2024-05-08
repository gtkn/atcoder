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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


double op(double a, double b){ return min(a,b); }
double ee(){ return llINF; }

double mapping(double f, double x){ return f+x; }
double composition(double f, double g){ return f+g; }
double id(){ return 0; }




void solve(){
    ll N, K;
    cin >> N >> K;

    Pll st;
    cin >> st.first >> st.second;
    vec(Pll) xy(N+1);
    rep1(i,N) cin >> xy[i].first >> xy[i].second;
    xy[0] = st;

    auto dist = [&](Pll a, Pll b)->double{
        return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
    };

    lazy_segtree<double, op, ee, double, mapping, composition, id> lseg(2*N+10);
    lseg.set(0,0);

    rep(i,N){
        double d = lseg.prod(i,i+K);
        d += dist(xy[i],st);
        d += dist(xy[i+1],st);
        lseg.set(i+K,d);
        lseg.apply(i,i+K, dist(xy[i],xy[i+1]));
    }

    double ans = lseg.prod(N, N+K) + dist(xy[N],st);
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
