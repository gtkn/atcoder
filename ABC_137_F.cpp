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

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


using mint = modint;

// xの1次式に対するFPS
struct FPS1d{
    ll K; // 最大次数-1 // x^0, x^1, ..., x^(K-1)
    vec(mint) coeffs;

    FPS1d(ll K=1):K(K){
        coeffs.resize(K);
    }

    void add(mint a, mint b){ // += a*x + b
        coeffs[1] += a;
        coeffs[0] += b;
    }

    void mul(mint a, mint b){ // *= a*x + b
        for(ll i=K-1; i>0; --i){            
            coeffs[i] = coeffs[i-1]*a + coeffs[i]*b;
        }
        coeffs[0] *= b;
    }   

    void div(mint a, mint b){ // /= a*x + b
        if(a==mint(0) && b == mint(0)){
            return;
        }

        if(a==mint(0)){
            rep(i,K) coeffs[i] /= b;
            return;
        }

        // if(b==mint(0)){
        //     rep(i,K-1){
        //         coeffs[i] = coeffs[i+1]/a;
        //     }
        //     coeffs[K-1] = mint(0);
        //     return;
        // }

        vec(mint) tmp(K);
        repr(i,K-1){
            tmp[i] = (coeffs[i+1] - b*tmp[i+1])/a;
        }
        swap(coeffs,tmp);

        // rep(i,K){
        //     if(i==0){
        //         coeffs[0] /= b;
        //     }else{
        //         coeffs[i] = (coeffs[i]-coeffs[i-1]*a)/b;
        //     }
        // }
    }
};



// Lagrange interpolation
vector<mint> lagrange_interpolation(const vector<mint>& x, const vector<mint>& y) {
    ll K = x.size();

    FPS1d f(K+1);
    f.coeffs[0] = 1;

    rep(i,K) f.mul(mint(1),-x[i] );

    vec(mint) res(K);
    rep(i,K){
        FPS1d f2 = f;
        f2.div(mint(1),-x[i]);

        mint c = y[i];
        rep(j,K)if(i!=j) c /= (x[i]-x[j]);
        rep(j,K) res[j] += f2.coeffs[j]*c;
    }
    return res;
}




void solve(){
    ll p;
    cin >> p;
    vec(ll) a(p);
    rep(i,p) cin >> a[i];

    // modがテストケースで変わるとき
    mint::set_mod(p);

    
    vec(mint) x(p),y(p);
    rep(i,p) x[i] = mint(i);
    rep(i,p) y[i] = mint(a[i]);

    vec(mint) ans = lagrange_interpolation(x,y);
    rep(i,p) cout << ans[i].val() << " "; cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
