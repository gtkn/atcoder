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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll H,W,K;
    cin >> H >> W >> K;
    ll Si,Sj;
    cin >> Si >> Sj;
    --Si,--Sj;

    vvec(ll) A(H,vec(ll)(W));
    rep(i,H) rep(j,W) cin >> A[i][j];

    ll x = min(H*W,K);

    vvvec(ll) dp(x+1,vvec(ll)(H,vec(ll)(W,-1)));
    dp[0][Si][Sj] = 0;

    rep(k,x){
        rep(i,H)rep(j,W){
            if(dp[k][i][j]==-1) continue;
            rep(d,4){
                ll ni = i+dh[d], nj = j+dw[d];
                if(ni<0||ni>=H||nj<0||nj>=W) continue;
                chmax(dp[k+1][ni][nj],dp[k][i][j]+A[ni][nj]);
            }        
        }

        // cerr << "k = " << k << endl;
        // rep(i,H){
        //     rep(j,W){
        //         cerr << dp[k][i][j] << " ";
        //     }
        //     cerr << endl;
        // }

    }

    ll ans = A[Si][Sj]*K;
    rep(i,H)rep(j,W){
        ll dist = abs(i-Si)+abs(j-Sj);
        ll tmp = 0;
        rep1(k,x){
            if(dp[k][i][j]==-1) continue;
            // if(i==1 && j==2) cerr << "k = " << k << " , " << dp[k][i][j] + (K-x)*A[i][j] << endl;
            chmax(tmp,dp[k][i][j] + (K-k)*A[i][j]);
        }
        chmax(ans,tmp);
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
