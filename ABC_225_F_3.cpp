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
//using mint = modint998244353;


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


string testf(ll N, ll K, vec(string) S){
    vec(ll) prem(N);
    rep(i,N) prem[i] = i;

    string ans = "";
    rep(_,4000) ans += "z";

    do{
        string res = "";
        rep(i,K) res += S[prem[i]];
        chmin(ans,res);

    }while(next_permutation(all(prem)));
    
    return ans;

}


string randStr(){
    ll len = rand()%50+1;
    string res = "";
    rep(_,len){
        res += 'a'+rand()%26;
    }
    return res;
}


void solve(){
    ll N,K;
    cin >> N >> K;
    vec(string) S(N);
    rep(i,N) cin >> S[i];

    // rep(i,N) S[i] = randStr();


    sort(all(S),[](const string &a, const string &b){
        return a+b < b+a;
    });

    string zz = "";
    rep(i,3000) zz += "z";
    vvec(string) dp(N+1,vec(string)(K+2,zz));
    
    reverse(all(S));
    dp[0][0] = "";
    rep(i,N)rep(j,K+1){
        chmin(dp[i+1][j],dp[i][j]);
        chmin(dp[i+1][j+1],S[i]+dp[i][j]);
    }

    cout << dp[N][K] << endl;
}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
