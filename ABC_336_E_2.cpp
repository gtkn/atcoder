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


bool f(ll n){
    ll tmp = n, tot = 0;
    while(tmp){
        tot += tmp%10;
        tmp /= 10;
    }
    return n%tot==0;
}

ll dp[20][200][200][2];


void solve(){
    ll N;
    cin >> N;

    ll tmp = N, K=0;
    vec(ll) v;
    while(tmp>0){
        v.push_back(tmp%10);
        tmp /= 10;
        ++K;
    }
    reverse(all(v));

    ll xmax = 9*K;
    ll ans = 0;

    rep1(x,xmax){
        rep(i,20)rep(j,200)rep(k,200)rep(l,2) dp[i][j][k][l] = 0;

        dp[0][0][0][0] = 1;
        rep(i,K)rep(j,x+1)rep(k,x){
            rep(d,10){
                ll jj = j+d, kk = (k*10+d)%x;
                if(jj>x) continue;
                if(d<v[i]){
                    dp[i+1][jj][kk][1] += dp[i][j][k][0];
                }
                if(d==v[i]){
                    dp[i+1][jj][kk][0] += dp[i][j][k][0];
                }
                dp[i+1][jj][kk][1] += dp[i][j][k][1];
            }
        }
        ans += dp[K][x][0][0] + dp[K][x][0][1];
        // cerr << x << " " << dp[K][x][0][0] << ", "<< dp[K][x][0][1] << endl;
    }

    cout << ans << endl;

    // ll chk = 0;
    // rep1(i,N) if(f(i)){
    //     cerr << i << ", ";
    //     ++chk;
    // }
    // cerr << endl;
    // cerr << chk << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
