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


/**
 * 2つの数値の拡張ユークリッドの互除法（GCD）を計算します。
 *
 * 2つの数値 `a` と `b` の拡張ユークリッドの互除法（GCD）は、次の条件を満たす `(g, x, y)` というタプルです：
 *   - `g` は `a` と `b` の最大公約数です
 *   - `x` と `y` は整数で、方程式 `ax + by = g` を満たします
 *
 * @param a 一つ目の数値
 * @param b 二つ目の数値
 * @param[out] x 方程式 `ax + by = g` の解 `x`
 * @param[out] y 方程式 `ax + by = g` の解 `y`
 * @return `a` と `b` の最大公約数 `g`
 */
tuple<ll,ll,ll> extgcd(ll a,ll b){
    if(b==0) return {a,1,0};
    ll g,x,y;
    tie(g,x,y) = extgcd(b,a%b);
    return {g,y,x-a/b*y};
}

void solve(){
    ll X,Y;
    cin >> X >> Y;
    ll ax = abs(X), ay = abs(Y);

    if(X==0){
        if(ay==1){
            cout << "2 0" << endl;
        }else if(ay==2){
            cout << "1 0" << endl;
        }else{
            cout << -1 << endl;
        }
        return;
    }
    if(Y==0){
        if(ax==1){
            cout << "0 2" << endl;
        }else if(ax==2){
            cout << "0 1" << endl;
        }else{
            cout << -1 << endl;
        }
        return;
    }


    auto [g, b, a] = extgcd(X,-Y);

    if(g==1){
        cout << a*2 << " " << b*2 << endl;
    }else if(g==2){
        cout << a << " " << b << endl;
    }else{
        if(g&1){
            if(a%g!=0 || b%g!=0) dame;
            a/=g;
            b/=g;
            cout << a*2 << " " << b*2 << endl;
        }else{
            ll gg = g/2;
            if(a%gg!=0 || b%gg!=0) dame;
            a/=gg;
            b/=gg;
            cout << a << " " << b << endl;
        }
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
