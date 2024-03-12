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
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
// using tri = tuple<ll,ll,ll>;
using tri = array<int,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


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



void solve(){
    int N;
    cin >> N;

    vec(int) H(N);
    rep(i,N) cin >> H[i];


    vec(int) M(N),S(N),E(N);
    vec(Pii) q;

    rep(i,N){
        cin >> M[i] >> S[i] >> E[i];

        q.emplace_back(S[i],i);
        q.emplace_back(E[i],i-N);
    }


    vvec(int) dp(N),memo(N);
    rep(i,N) dp[i].push_back(-iINF);
    rep(i,N) memo[i].push_back(-iINF);
    int ans = 0;


    sort(all(q));

    for(auto [t,ii]:q){
        bool is_start = (ii>=0);
        if(ii<0) ii+=N;
        int m = M[ii]-1;

        if(is_start){
            rep(i,dp[m].size()){
                memo[ii].push_back(dp[m][i] + H[i]);
            }
            chmax(memo[ii][1], ans + H[0]);
        }else{
            rep(i,memo[ii].size()){
                if(i < dp[m].size()){
                    chmax(dp[m][i], memo[ii][i]);
                }else{
                    dp[m].push_back(memo[ii][i]);
                }
            }
            rep(i, memo[ii].size()){
                chmax(ans, memo[ii][i]);
            }
        }
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
