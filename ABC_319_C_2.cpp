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
    // vvec(ll) c(3,vec(ll)(3));
    // rep(i,3) rep(j,3) cin >> c[i][j];
    vec(ll) c(9);
    rep(i,9) cin >> c[i];

    vvec(ll) vv;

    auto f = [&](ll i0, ll i1, ll i2)->void{
        if (c[i0]==c[i1]) vv.push_back({i0,i1,i2});
        if (c[i0]==c[i2]) vv.push_back({i0,i2,i1});
        if (c[i2]==c[i1]) vv.push_back({i2,i1,i0});
    };

    f(0,1,2);
    f(3,4,5);
    f(6,7,8);

    f(0,3,6);
    f(1,4,7);
    f(2,5,8);

    f(0,4,8);
    f(2,4,6);


    ll cnt = 0;
    vec(ll) v(9);
    rep(i,9) v[i] = i;
    do{
        vec(ll) p(9);
        rep(i,9) p[v[i]] = i;
        bool isok = true;
        for(auto& is:vv){
            if( p[is[0]] < p[is[2]] && p[is[1]] < p[is[2]] ) isok = false;
        }
        if(isok) cnt++;
    } while (next_permutation(all(v)));


    ll tot = 1;
    rep(i,9) tot *= (i+1);

    double ans = 1.*cnt/tot;
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
