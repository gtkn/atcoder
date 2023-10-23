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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


ll f(ll N){
    ll nn = N;
    vec(ll) v;
    while(nn>0){
        v.push_back(nn%10);
        nn/=10;
    }
    ll M = v.size();
    reverse(all(v));

    vvvec(ll) dp(M+1,vvec(ll)(2,vec(ll)(2))); // 上からi桁見て、N以下が確定していて、該当するかどうか
    dp[0][0][0]=1;

    rep(i,M){
        // j=0
        rep(x,v[i]){
            if(x==4 || x==9){
                dp[i+1][1][1] += dp[i][0][0];
                dp[i+1][1][1] += dp[i][0][1];
            }else{
                dp[i+1][1][0] += dp[i][0][0];
                dp[i+1][1][1] += dp[i][0][1];
            }
        }
        if(v[i]==4 || v[i]==9){
            dp[i+1][0][1] += dp[i][0][0];
            dp[i+1][0][1] += dp[i][0][1];
        }else{
            dp[i+1][0][0] += dp[i][0][0];
            dp[i+1][0][1] += dp[i][0][1];
        }

        // j=1
        rep(x,10){
            if(x==4 || x==9){
                dp[i+1][1][1] += dp[i][1][0];
                dp[i+1][1][1] += dp[i][1][1];
            }else{
                dp[i+1][1][0] += dp[i][1][0];
                dp[i+1][1][1] += dp[i][1][1];
            }
        }
    }

    ll res = dp[M][1][1];
    return res;
}


void solve(){
    ll A,B;
    cin >> A >> B;

    cout << f(B+1)-f(A) << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
