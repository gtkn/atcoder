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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

void solve(){
    ll T;
    cin >> T;

    auto f = [](ll m,ll h, ll w){
        mint res=1;
        if(m<h || m<w){
            cout << "invalid : " << m << ", " << h << ", " << w << endl;
            return mint(0);
        }
        res *= (m-h+1);
        res *= (m-w+1);
        return res;
    };


    auto sum0 = [](ll n)->mint{ // sigma(i^0)_i=1~n
        return n;
    };
    auto sum1 = [](ll n)->mint{ // sigma(i^1)_i=1~n
        mint res = n;
        res *= (n+1);
        res /= 2;
        return res;
    };
    auto sum2 = [](ll n)->mint{ // sigma(i^2)_i=1~n // https://math.nakaken88.com/textbook/basic-sum-of-square-numbers/
        mint res = n;
        res*=(n+1);
        res*=(2*n+1);
        res/=6;
        return res;
    };
    auto sum3 = [](ll n)->mint{ // sigma(i^3)_i=1~n // https://math.nakaken88.com/textbook/basic-sum-of-cube-numbers/
        mint res = n;
        res *= (n+1);
        res /= 2;
        return res*res;
    };


    while(T--){
        ll N,A,B;
        cin >> N >> A >> B;
        if(A<B) swap(A,B);

        mint n = N-A+1;
        mint nn = n*n;
        ll bb = min(B-1,N-A);
        mint g0=sum0(bb), g1=sum1(bb);



        mint x0,x1,x2;
        x0 = f(N,A,A)*f(A,B,B);
        x1 = 4*(A-B+1)*(nn*g0-n*g1);
        x2 = n*g0-g1;
        x2 = 4*x2*x2;
        mint ans = f(N,A,A)*f(N,B,B);
        // cout << ans.val() << " - " << x0.val() << ", " << x1.val() <<", " << x2.val() << endl;
        ans -= x0+x1+x2;

        cout << ans.val() << endl;



        // ans = f(N,A,A)*f(N,B,B);
        // mint x4 = 0;
        // if(N-A-B>=0) x4 = (N-A-B+2)*(N-A-B+1)/2;
        // x2 = f(N,A,B)-2*x4;
        // x1 = x2*x2;
        // cout << x1.val() << endl;
        // ans -= x1;
        // cout << ans.val() << endl;
        



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
