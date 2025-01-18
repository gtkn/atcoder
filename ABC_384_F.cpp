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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    auto f = [&](auto f, vec(ll) a, vec(ll) b)->ll{
        // cerr << "---" << endl;
        // for(ll x:a) cerr << x << " ";
        // cerr << endl;
        // for(ll x:b) cerr << x << " ";
        // cerr << endl;

        if(a.empty() || b.empty()) return 0;

        vec(ll) ae,ao,be,bo;
        for(ll x:a){
            if(x&1) ao.push_back(x);
            else ae.push_back(x);
        }
        for(ll x:b){
            if(x&1) bo.push_back(x);
            else be.push_back(x);
        }

        ll ae_sum = 0, ao_sum = 0, be_sum = 0, bo_sum = 0;
        for(ll x:ae) ae_sum += x;
        for(ll x:ao) ao_sum += x;
        for(ll x:be) be_sum += x;
        for(ll x:bo) bo_sum += x;


        ll res = 0;
        // ae,bo
        res += ae_sum*bo.size();
        res += bo_sum*ae.size();
        // ao,be
        res += ao_sum*be.size();
        res += be_sum*ao.size();
        // ae,be
        for(ll& x:ae) x/=2;
        for(ll& x:be) x/=2;
        res += f(f,ae,be);
        // ao,bo
        for(ll& x:ao) x = x/2 + 1;
        for(ll& x:bo) x/=2;
        res += f(f,ao,bo);

        return res;

    };


    auto g = [](ll x)->ll{
        while(x%2==0) x/=2;
        return x;
    };


    ll ans = f(f,A,A);
    rep(i,N) ans += g(A[i]);
    ans/=2;
    cout << ans << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
