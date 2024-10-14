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
};



void solve(){
    ll B,K,sx,sy,gx,gy;
    cin >> B >> K >> sx >> sy >> gx >> gy;

    Coordinate s(sx,sy),g(gx,gy);

    auto dist = [&](Coordinate a, Coordinate b){
        return abs(a.x-b.x)+abs(a.y-b.y);
    };


    auto f = [&](Coordinate a, Coordinate b){
        if(a.x==b.x && a.x%B==0 || a.y==b.y && a.y%B==0) return dist(a,b);

        vec(Coordinate) as,bs;
        if(a.x%B!=0){
            ll n = a.x/B;
            as.emplace_back( n*B, a.y );
            as.emplace_back( (n+1)*B, a.y );
        }
        if(a.y%B!=0){
            ll n = a.y/B;
            as.emplace_back( a.x, n*B );
            as.emplace_back( a.x, (n+1)*B );
        }
        if(a.x%B == 0 && a.y%B == 0) as.push_back(a);

        if(b.x%B!=0){
            ll n = b.x/B;
            bs.emplace_back( n*B, b.y );
            bs.emplace_back( (n+1)*B, b.y );
        }
        if(b.y%B!=0){
            ll n = b.y/B;
            bs.emplace_back( b.x, n*B );
            bs.emplace_back( b.x, (n+1)*B );
        }
        if(b.x%B == 0 && b.y%B == 0) bs.push_back(b);

        assert(!as.empty() && !bs.empty());

        ll res = llINF;
        for(Coordinate ai:as)for(Coordinate bi:bs){
            chmin(res, dist(a,ai) + dist(ai,bi) + dist(bi,b) );
        }

        return res;
    };




    vec(Coordinate) ss,gs;
    {
        ll n = s.x/B;
        ss.emplace_back( n*B, s.y );
        ss.emplace_back( (n+1)*B, s.y );
    }
    {
        ll n = s.y/B;
        ss.emplace_back( s.x, n*B );
        ss.emplace_back( s.x, (n+1)*B );
    }

    {
        ll n = g.x/B;
        gs.emplace_back( n*B, g.y );
        gs.emplace_back( (n+1)*B, g.y );
    }
    {
        ll n = g.y/B;
        gs.emplace_back( g.x, n*B );
        gs.emplace_back( g.x, (n+1)*B );
    }



    ll ans = dist(s,g)*K;
    for(Coordinate si:ss)for(Coordinate gi:gs){
        chmin(ans, dist(s,si)*K + f(si,gi) + dist(gi,g)*K );
    }

    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
