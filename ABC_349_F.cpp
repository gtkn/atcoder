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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N, M;
    cin >> N >> M;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    if(M==1){
        mint ans = 1;
        rep(i,N) if(A[i]==1) ans*=2;
        ans-=1;
        cout << ans.val() << endl;
        return;
    }


    map<ll,ll> fac;
    ll mm = M;
    for(ll i=2; i*i<=mm; ++i) {
        while(mm%i == 0) {
            fac[i]++;
            mm /= i;
        }
    }
    if(mm > 1) {
        fac[mm]++;
    }

    ll nn = fac.size();
    vec(ll) pk;
    for(auto [pf,cnt]:fac){
        ll x = 1;
        rep(_,cnt) x*=pf;
        pk.push_back(x);
    }

    ll bmax = (1<<nn);
    vec(ll) bcnt(bmax);

    for(ll ai:A){
        if(M%ai!=0) continue;
        ll b = 0;
        rep(i,nn){
            if(ai%pk[i]==0) b |= (1<<i);
        }
        bcnt[b]++;
    }

    vec(mint) two(N+1);
    two[0] = 1;
    rep1(i,N) two[i] = two[i-1] * 2;

    vvec(mint) dp(bmax+1,vec(mint)(bmax));
    dp[0][0] = 1;
    rep(i,bmax)rep(j,bmax){
        dp[i+1][j] += dp[i][j];
        dp[i+1][j|i] += dp[i][j] * (two[bcnt[i]]-1);
    }

    mint ans = dp[bmax][bmax-1];
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
