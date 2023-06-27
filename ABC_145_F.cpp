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
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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
 
    void solve(){
        ll N,K;
        cin >> N >> K;

        vec(ll) H(N);
        rep(i,N) cin >> H[i];

        map<Pll,ll> dp0;
        dp0[{0,0}]=0;
        rep(i,N){
            map<Pll,ll> dp1;

            auto f = [&](ll hh,ll kk, ll xx){
                if(kk>K) return;
                if(dp1.count({hh,kk})>0) chmin(dp1[{hh,kk}], xx);
                else dp1[{hh,kk}] = xx;
            };

            for(auto m:dp0){
                ll h,k,x;
                tie(h,k) = m.first; x = m.second;

                if(h >= H[i]){
                    f(H[i], k, x );
                    f(h, k+1, x);
                }else{
                    f(H[i], k, x+H[i]-h);
                    f(h, k+1, x);
                }
            }

            swap(dp0,dp1);
        }

        ll ans = llINF;
        for(auto m:dp0) chmin(ans, m.second);
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
