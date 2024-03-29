//title
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

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
    ll N,M;
    cin >> N >> M;

    vec(ll) A(N),B(M);
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];

    ll nn = N*(N+1)/2;

    vvec(ll) dp(N+1,vec(ll)(nn+N+10, llINF));

    dp[0][0] = 0;
    rep(i,N)rep(j,nn+1){
        chmin(dp[i+1][j], dp[i][j]);
        chmin(dp[i+1][j+i+1], dp[i][j] + A[i]);
    }


    ll jtot = M*(M+1)/2, btot = 0;

    vec(Pll) v(M);
    rep(i,M) v[i] = {B[i],i+1};
    sort(all(v), [](Pll const& a, Pll const& b){
        return(a.first*b.second > b.first*a.second);
    });


    ll ans = llINF;
    rep(k,nn+1){
        ll res = 0;
        res += dp[N][nn-k];

        while(!v.empty()){
            auto [bj,j] = v.back();
            if(k*j >= bj){
                v.pop_back();
                btot += bj;
                jtot -= j;
            }else{
                break;
            }
        }

        res += k*jtot + btot;

        // cout << k << " : " << dp[N][nn-k] <<", " << jtot <<" , " << btot << endl;

        chmin(ans,res);
    }

    cout << ans << endl;













}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
