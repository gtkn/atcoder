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
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){
    ll Q, K;
    cin >> Q >> K;

    vec(mint) dp(K+1);
    dp[0]=1;

    while(Q--){
        char c;
        ll x;
        cin >> c >> x;

        if(c=='+'){
            for(ll i=K; i>=x; i--){
                dp[i] += dp[i-x];
            }
        }else{
            for(ll i=x; i<=K; i++){
                dp[i] -= dp[i-x];
            }
        }
        cout << dp[K].val() << endl;
    }


}


struct FPS{
    ll K;
    vec(mint) coeffs;

    FPS(vec(mint) v):coeffs(v){
        K = v.size();
    }

    void add(const vec(mint)& v){
        rep(i,v.size()) coeffs[i] += v[i];
    }

    void add(ll idx, mint d){
        assert(idx>=0 && idx<K);
        coeffs[idx]+=d;
    }


    void mul(const vec(mint)& v){
        coeffs = convolution(coeffs, v);
        coeffs.resize(K);
    };

    void mul(ll d){ // これは内容による
        for(ll i=K; i>=d; i--){
            coeffs[i] += coeffs[i-d];
        }
    };

    void div(ll d){ // これは内容による
        for(ll i=d; i<=K; i++){
            coeffs[i] -= coeffs[i-d];
        }
    }

    void show(ll th){
        rep(i,th) cout << i<< ":" << coeffs[i].val() <<", "; cout << endl;
    }


};


void solve_FPS(){
    ll Q, K;
    cin >> Q >> K;

    vec(mint) v(5001);
    v[0] = 1;
    FPS fps(v);

    while(Q--){
        char c;
        ll x;
        cin >> c >> x;

        if(c=='+'){
            fps.mul(x);
        }else{
            fps.div(x);
        }

        cout << fps.coeffs[K].val() << endl;
        // fps.show(12);

    }



}




int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        // solve();
        solve_FPS();
    }
    return 0;
}
