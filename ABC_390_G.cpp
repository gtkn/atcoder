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

    void mul(ll d){ // これは内容による // *(x^d+1) ?
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


//---modintで組み合わせ扱う用の構造体---
struct mcomb{
    ll nmax;
    vec(mint) fa,af;
    mcomb(ll sz=200020){
        nmax = sz;
        fa.resize(nmax+1);
        fa[0]=1;
        rep1(i,nmax) fa[i]=fa[i-1]*i;
        af.resize(nmax+1);
        rep(i,nmax+1) af[i]=fa[i].inv();
    }
    mint c(ll n, ll k){
        if(n<k || k<0 || n>nmax) return 0;
        return fa[n]*af[k]*af[n-k];
    }
};




void solve(){
    ll N;
    cin >> N;

    mint ans = 0;
    auto keta = [](ll x)->ll{
        ll res = 0;
        while(x>0){
            x/=10;
            ++res;
        }
        return res;
    };

    vec(ll) ks(N+1);
    vec(ll) kcnt(7);
    rep1(i,N) ks[i] = keta(i);
    rep1(i,N) ++kcnt[ks[i]];


    ll M = 2000000;
    vec(mint) v0(M);

    FPS fps(v0);
    rep1(k,6){
        vec(mint) v(M);
        rep(j,kcnt[k]) v[j*k] = ;
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
