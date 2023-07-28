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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

using a10 = array<ll,10>;

void solve(){
    ll N,M;
    cin >> N >> M;

    vec(ll) v = {0,2,5,5,4,5,6,3,7,6};
    vec(bool) A(10);
    rep(_,M){
        ll ai; cin>>ai;
        A[ai]=true;
    }


    auto f = [](a10 const &a, a10 const &b)->bool{
        if(a[0] != b[0]) return a[0] > b[0];
        rep1r(i,9){
            if(a[i] != b[i]) return a[i] > b[i];
        }
        return true;
    };

    vec(a10) dp(N+1);
    rep1(i,N) dp[i][0] = -1;

    rep(i,N)rep1(x,9){
        // if(x==1){
        //     cout << i <<" ; ";
        //     rep1r(j,9) rep(_,dp[i][j]) cout << j;
        //     cout << endl;
        // }

        if(!A[x] || dp[i][0]<0) continue;

        ll ii = i + v[x];
        if(ii>N) continue;


        a10 nxt = dp[i];
        nxt[0]++;
        nxt[x]++;

        if(f(nxt, dp[ii])) dp[ii] = nxt;
    }

    // rep(i,10) cout << i << " :" << dp[N][i] <<" " << endl;

    rep1r(x,9){
        rep(_, dp[N][x]) cout << x;
    }
    cout << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
