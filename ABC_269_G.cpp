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


vec(ll) binary_partition(ll n){
    vec(ll) res;
    ll x = 1;
    while(n){
        ll s = min(x,n);
        res.push_back(s);
        n -= s;
        x *= 2;
    }
    return res;
}


void solve(){
    ll N,M;
    cin >> N >> M;
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];

    ll atot = 0;
    rep(i,N) atot += A[i];

    vec(ll) C(N);
    rep(i,N) C[i] = -A[i]+B[i];
    map<ll,ll> mp;
    rep(i,N) mp[C[i]]++;



    vec(ll) dp(M+1,llINF);
    dp[atot] = 0;

    for(auto [c,n]:mp){
        // cerr << c << " " << n << endl;
        vec(ll) p = binary_partition(n);
        for(ll pi:p){
            vec(ll) dp2 = dp;
            rep(j,M+1){
                ll jj = j+c*pi;
                if(jj<0 || jj>M) continue;
                chmin(dp2[jj],dp[j]+pi);
            }
            swap(dp,dp2);
        }
    }

    rep(i,M+1) cout << (dp[i]==llINF?-1:dp[i]) << endl;






    // vvec(ll) dp(N+1,vec(ll)(M+1,llINF));
    // dp[0][0] = 0;
    // rep(i,N)rep(j,M+1){
    //     chmin(dp[i+1][j+A[i]], dp[i][j]);
    //     chmin(dp[i+1][j+B[i]], dp[i][j]+1);
    // }


    // vec(ll) dp(M+1,llINF);
    // priority_queue<Pll,vector<Pll>,greater<Pll>> pq;
    // auto push = [&](ll cnt, ll tot){
    //     if(chmin(dp[tot],cnt)) pq.push({cnt,tot});
    // };
    // push(0,0);

    // rep(i,N){
    //     priority_queue<Pll,vector<Pll>,greater<Pll>> npq;
    //     swap(npq,pq);
    //     while(!npq.empty()){
    //         auto [cnt,tot] = npq.top(); npq.pop();
    //         push(cnt,tot+A[i]);
    //         push(cnt+1,tot+B[i]);
    //     }
    // }






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
