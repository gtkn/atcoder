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


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


//---素因数分解------
map<ll, ll > prime_factor(ll n) {
    map<ll, ll > pf;
    for(ll f=2; f*f<=n; ++f){
        while(n%f == 0){
            pf[f]++;
            n /= f;
        }
    }
    if(n!=1) pf[n] = 1;
    return pf;
}




void solve(){
    ll N,M;
    cin >> N >> M;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    if(M==1){
        ll cnt = 0;
        rep(i,N) if(A[i]==1) cnt++;
        mint ans = mint(2).pow(cnt)-1;
        cout << ans.val() << endl;
        return;
    }


    vec(ll) B;
    rep(i,N) if(M%A[i]==0) B.push_back(A[i]);

    map<ll,ll> pf = prime_factor(M);
    ll nn = pf.size();

    vec(ll) v;
    for(auto [p,f]:pf){
        ll t = 1;
        rep(i,f) t *= p;
        v.push_back(t);
    }

    ll nnn = (1<<nn);
    vec(ll) bcnt(nnn);
    for(ll bi:B){
        ll now = 0;
        rep(i,nn){
            if(bi%v[i]==0) now += (1<<i);
        }
        bcnt[now]++;
    }
    

    vvec(mint) dp(nnn+1, vec(mint)(nnn));
    dp[0][0] = 1;

    vec(mint) two(N+1);
    two[0] = 1;
    rep1(i,N) two[i] = two[i-1] * 2;

    rep(i,nnn)rep(j,nnn){
        dp[i+1][j] += dp[i][j];
        ll jj = j | i;
        dp[i+1][jj] += dp[i][j] * (two[bcnt[i]]-1);
    }

    cout << dp[nnn][nnn-1].val() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
