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



struct Point {
    double x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};


vector<Point> convex_hull(vector<Point>& points, bool is_lower=true) {
    sort(points.begin(), points.end());
    vector<Point> hull;
    for (const auto& p : points) {
        while (hull.size() >= 2) {
            Point q = hull[hull.size() - 1];
            Point r = hull[hull.size() - 2];
            if ((q.x - r.x) * (p.y - r.y) - (q.y - r.y) * (p.x - r.x) <= 0) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(p);
    }
    return hull;
}





void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N),B(N),C(N);
    rep(i,N) cin >> A[i] >> B[i] >> C[i];

    vec(double) a(N),b(N);
    rep(i,N) a[i] = 1.*A[i]/C[i], b[i] = 1.*B[i]/C[i];

    vec(Point) points;
    rep(i,N) points.push_back({a[i],b[i]});

    auto hull = convex_hull(points,true);

    ll nn = hull.size();

    double ans = max(hull[0].x,hull[0].y);

    rep(i,nn-1){
        double x1 = hull[i].x, y1 = hull[i].y; // P1
        double x2 = hull[i+1].x, y2 = hull[i+1].y; // P2

        bool b1 = (y1 >= x1);
        bool b2 = (y2 >= x2);


        if( b1 == b2){
            double res = min(max(x1,y1),max(x2,y2));
            chmin(ans,res);
        }else{
            double d1 = x1-y1, d2 = x2-y2;
            double t = -d2/(d1-d2);
            double res = t*x1+(1-t)*x2; 
            chmin(ans,res);
        }
    }

    ans = 1/ans;

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
