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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{



    //---modintで組み合わせ扱う用の構造体---
    struct mconb{
        ll nmax;
        vec(mint) fa,af;
        mconb(ll sz=2000020){
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

    mconb mc;

    mint f(ll R,ll C){
        vec(mint) dp(R+C+10);
        dp[0]=1;

        ll r1=0,c1=0;        
        ll r2=0,c2=0;

        rep(i,R+C){
            dp[i+1] = 2*dp[i];

            if(r1<R){
                r1++;
            }else{
                dp[i+1] -= mc.c(r1+c1,r1);
                c1++;
            }

            if(c2<C){
                c2++;
            }else{
                dp[i+1] -= mc.c(r2+c2,c2);
                r2++;
            }
        }


        mint res = 0;
        rep(i,R+C+1) res += dp[i];
        //rep(i,R+C+1) cout<<i << " : " << dp[i].val()  << endl;
        //cout << "tot " <<res.val() << "----" << R << " < " << C << endl;

        return res;
    }


    void solve(){
        ll r1,r2,c1,c2;
        cin >> r1 >> c1 >> r2 >> c2;

        mint ans = f(r2,c2) - f(r1-1,c2) - f(r2,c1-1) + f(r1-1,c1-1);
        cout << ans.val() << endl;


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
