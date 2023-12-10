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
    ll N;
    cin >> N;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    vector<queue<mint>> memo(N+1);
    vec(mint) dp(N+1);
    mint tot = 1;
    dp[0]=1;
    memo[0].push(1);

    for(ll ai:A){        
        tot = 0;
        rep(i,N+1) tot += dp[i];


        if(ai>0){
            mint d = tot-dp[ai];
            memo[ai].push(d);
            dp[ai] += d;


            rep(i,N+1){
                ll x = 0;
                if(i==ai) x=ai;
                while(memo[i].size() > x){
                    dp[i] -= memo[i].front();
                    memo[i].pop();
                }
            }

        }else{
            rep(i,N+1){
                mint d = tot-dp[i];
                memo[i].push(d);
                dp[i] += d;
            }
            rep(i,N+1){
                while(memo[i].size() > i){
                    dp[i] -= memo[i].front();
                    memo[i].pop();
                }
            }
        }

        // for(mint x:dp) cerr << x.val() << " "; cerr << endl;

    }


    mint ans = 0;
    rep(i,N+1) ans += dp[i];

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
