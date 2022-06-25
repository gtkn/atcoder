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
using Pld = pair<ll,double>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------



struct Solver{


    ll N;
    double dp[(1<<17)];

    double f(ll now){
        if(dp[now]>=0) return dp[now];

        double res = llINF;

        rep(i,15){
            ll a = (1<<i);
            ll cnt = 0;
            double tmp = 1.;

            rep(_,3){
                if(now&a){
                    cnt++;
                    tmp+=f(now-a)/3.;
                }
                a<<=1;
            }
            if(cnt==0) continue;
            chmin(res, tmp*3./cnt);
        }

        dp[now]=res;
        return res;
    }



    void solve(){
        cin >> N;

        ll st = 0;
        rep(_,N){
            ll x; cin >> x;
            st |= (1<<x);
        }
        rep(i,(1<<17)) dp[i]=-1;
        dp[0]=0;

        double ans = f(st);

        printf("%.8f\r\n",ans);


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
