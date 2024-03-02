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
constexpr ll llINF = 1LL << 60;
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
    ll v1,v2,v3;
    cin >> v1 >> v2 >> v3;

    ll nn = 14;

    ll a1=7, b1=7, c1=7;


    auto f = [](vec(ll) as, vec(ll) bs, vec(ll) cs)->ll{
        ll amin = llINF, amax = -llINF;
        for(ll a:as) chmin(amin, a);
        for(ll a:as) chmax(amax, a);

        ll bmin = llINF, bmax = -llINF;
        for(ll b:bs) chmin(bmin, b);
        for(ll b:bs) chmax(bmax, b);

        ll cmin = llINF, cmax = -llINF;
        for(ll c:cs) chmin(cmin, c);
        for(ll c:cs) chmax(cmax, c);

        ll x,y,z;
        x = max(0LL,amin+7-amax);
        y = max(0LL,bmin+7-bmax);
        z = max(0LL,cmin+7-cmax);

        return x*y*z;
    };


    rep(a2,nn)rep(b2,nn)rep(c2,nn)rep(a3,nn)rep(b3,nn)rep(c3,nn){
        ll w12 = f({a1,a2},{b1,b2},{c1,c2});
        ll w23 = f({a3,a2},{b3,b2},{c3,c2});
        ll w31 = f({a1,a3},{b1,b3},{c1,c3});
        ll w123 = f({a1,a2,a3},{b1,b2,b3},{c1,c2,c3});

        ll w1,w2,w3;
        w3 = w123;
        w2 = w12 + w23 + w31 - 3*w123;
        w1 = 3*7*7*7 - 2*w2 - 3*w3;

        if(w1==v1 && w2==v2 && w3==v3){

            cout << "Yes" << endl;
            cout << a1 <<" " << b1 <<  " " << c1 << " ";
            cout << a2 <<" " << b2 <<  " " << c2 << " ";
            cout << a3 <<" " << b3 <<  " " << c3 << " " << endl;
            return;

        }

    }

    cout << "No" << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
