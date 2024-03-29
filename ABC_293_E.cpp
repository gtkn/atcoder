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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


struct Solver{

    ll pow_mod(ll x, ll n, ll mod) {
        ll res = 1;
        while (n > 0) {
            if (n & 1) {
                res = (res * x) % mod;
            }
            x = (x * x) % mod;
            n >>= 1;
        }
        return res;
    }




    vvec(ll) vvpow(vvec(ll) vv, ll n, ll mod){
        ll m = vv.size();
        assert(m == vv[0].size());

        vvec(ll) res(m,vec(ll)(m));
        rep(i,m) res[i][i]=1;

        auto f = [&](vvec(ll) a,vvec(ll) b){
            vvec(ll) tmp(m,vec(ll)(m));
            rep(i,m)rep(j,m)rep(k,m) tmp[i][j] = (tmp[i][j] + a[i][k]*b[k][j])%mod;
            return tmp;
        };


        while(n>0){
            if(n&1) res = f(res,vv);
            vv = f(vv,vv);
            n>>=1;
        }

        return res;
    }


 
    void solve(){
        ll A,X,M;
        cin >> A >> X >> M;

        vvec(ll) vv(2,vec(ll)(2));
        vv[0][0]=A;
        vv[0][1]=1; vv[1][1]=1;

        vv = vvpow(vv, X, M);

        ll ans = vv[0][1];
        cout << ans << endl;
    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
