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
// using mint = modint;
// mint::set_mod(P);


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


void solve(){
    ll N,X,K;
    cin >> N >> X >> K;

    vec(ll) P(N),U(N),C(N);
    rep(i,N) cin >> P[i] >> U[i] >> C[i];

    set<ll> st;
    rep(i,N) st.insert(C[i]);
    map<ll,ll> mp;
    ll nn = 0;
    for(ll ci:st) mp[ci] = nn++;


    vvec(Pll) vv(nn);
    rep(i,N) vv[mp[C[i]]].emplace_back(P[i],U[i]);


    vec(ll) memo(X+1,-llINF);
    memo[0] = 0;

    for(auto v:vv){
        ll m = v.size();
        vvec(ll) dp(m+1,vec(ll)(X+1,-llINF));

        rep(i,m){
            auto [pi,ui] = v[i];
            rep(j,X+1){
                chmax(dp[i+1][j],dp[i][j]);
                if(j+pi>X) continue;
                chmax(dp[i+1][j+pi], dp[i][j]+ui);
            }
            rep(j,X+1){
                if(j+pi>X) continue;
                chmax(dp[i+1][j+pi], memo[j] + ui + K);
            }
        }

        // cerr << "-----" << endl;
        // rep(j,X+1) cerr << memo[j] << " "; cerr << endl;
        // cerr << endl;
        // rep1(i,m){
        //     rep(j,X+1) cerr << dp[i][j] << " "; cerr << endl;
        // }

        rep(j,X+1) chmax(memo[j],dp[m][j]);

    }

    ll ans = -llINF;
    rep(i,X+1) chmax(ans,memo[i]);
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
