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


ll sqrt_floor(ll x){
    ll xx = sqrt(x);
    ll res = xx;
    for(ll a=max(1LL,xx-10); a<=xx+10; ++a){
        if(a*a <= x) res = a;
    }
    return res;
}


void solve(){
    ll T;
    cin >> T;


    ll M = 1e5;
    vec(ll) v(M+1);
    v[1] = 1;
    for(ll i=2; i<=M; i++){
        rep1(j,sqrt_floor(i)) v[i] += v[j];
    }

    vec(ll) l(M),r(M),c(M);
    ll sum = 0;
    rep(i,M){
        sum += v[i+1];
        l[i] = (i+1)*(i+1);
        r[i] = (i+2)*(i+2);
        c[i] = sum;
    }

    // rep(i,20) cerr << i << " : " << v[i] << endl;
    // rep(i,20) cerr << l[i] << " " << r[i] << " " << c[i] << endl;

    auto f = [&](ll xx)->ll{
        ll res = 0;
        rep(i,M){
            if(r[i] <= xx){
                res += c[i] * (r[i]-l[i]);
            }else{
                res += c[i] * (xx+1-l[i]);
                break;
            }
        }
        return res;
    };


    ll d = 109;
    rep(_,T){
        ll X; cin >> X;
        ll res = f( sqrt_floor(X) );
        cout << res << endl;
    }


    // rep1(i,M) if(f(sqrt(i)) != v[i]) cerr << i << " : " << f(sqrt(i)) << " " << v[i] << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
