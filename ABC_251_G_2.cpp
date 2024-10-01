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


struct Coordinate
{
    ll x,y;
    Coordinate(ll x=0, ll y=0):x(x),y(y){}

    Coordinate operator+(const Coordinate& c) const{
        return Coordinate(x+c.x,y+c.y);
    }
};


struct S{
    Coordinate p1, p2;
    S(Coordinate p1=Coordinate(0,0), Coordinate p2=Coordinate(0,0)):p1(p1),p2(p2){}

    ll cross(Coordinate p){
        ll x1 = p1.x - p.x;
        ll y1 = p1.y - p.y;
        ll x2 = p2.x - p.x;
        ll y2 = p2.y - p.y;
        return x1*y2 - x2*y1;
    }
};


void solve(){
    ll N;
    cin >> N;
    vec(ll) x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];
    vec(Coordinate) xy(N+1);
    rep(i,N) xy[i] = Coordinate(x[i],y[i]);
    xy[N] = xy[0];

    ll M;
    cin >> M;
    vec(ll) u(M),v(M);
    rep(i,M) cin >> u[i] >> v[i];
    vec(Coordinate) uv(M);
    rep(i,M) uv[i] = Coordinate(u[i],v[i]);

    ll Q;
    cin >> Q;
    vec(ll) a(Q),b(Q);
    rep(i,Q) cin >> a[i] >> b[i];
    vec(Coordinate) ab(Q);
    rep(i,Q) ab[i] = Coordinate(a[i],b[i]);


    vec(S) line(N);
    rep(i,N) line[i] = S(xy[i]+uv[0],xy[i+1]+uv[0]);

    rep(i,N){
        rep(j,M){
            if(line[i].cross(xy[i]+uv[j]) > 0){
                line[i] = S(xy[i]+uv[j],xy[i+1]+uv[j]);
            }
        }
    }

    rep(i,Q){
        bool isok = true;
        rep(j,N) if(line[j].cross(ab[i]) < 0) isok = false;
        if(isok) sayyn;
    }







}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
