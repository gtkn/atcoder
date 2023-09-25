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
    ll N,M;
    cin >> N >> M;

    vec(ll) R(N),B(N);
    rep(_,M){
        ll x; cin >> x;
        R[x-1]++;
    }
    rep(_,M){
        ll x; cin >> x;
        B[x-1]++;
    }


    vec(mint) fa(M+1);
    fa[0]=1;
    rep1(i,M) fa[i] = fa[i-1]*i;



    ll nn = (1<<N);
    vec(mint) d(nn);
    rep(s,nn){
        ll r=0, b=0;
        rep(i,N){
            if(bit(s,i)){
                r += R[i];
                b += B[i];
            }
        }
        if(r==b) d[s] = fa[r];
    }

    vec(mint) dp(nn);
    mint ans = 0;

    rep(s,nn){
        if(s==0) continue;
        dp[s] = d[s];

        ll v = s&-s;
        ll rem = s^v;
        for(ll t = rem; t; t=(t-1)&rem){
            dp[s] -= dp[s^t]*d[t];
        }
        ans += dp[s]*d[(nn-1)^s];
    }

    ans/=fa[M];

    cout << ans.val() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
