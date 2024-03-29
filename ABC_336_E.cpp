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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


ll dp[16][150][150][2]; // [桁][総和%M][桁和][未満]


void solve(){
    ll N;
    cin >> N;

    
    ll N_ = N;
    vec(ll) v;
    while(N_){
        v.push_back(N_%10);
        N_/=10;
    }
    ll l = v.size();
    reverse(all(v));
    // for(ll vi:v) cerr << vi << " "; cerr << nl;


    auto f = [&](ll M)->ll{
        rep(i,16)rep(j,150)rep(k,150)rep(a,2) dp[i][j][k][a] = 0;
        dp[0][0][0][0] = 1;


        rep(i,l)rep(j,M)rep(k,M+1){
            // cerr << i << " ," << j << " , " << k << nl;
            // N未満未確定
            rep(x,v[i]){
                if( k+x > M) break;
                dp[i+1][ (10*j + x)%M ][ k+x ][1] += dp[i][j][k][0];
            }
            if( k+v[i] <= M){
                dp[i+1][ (10*j + v[i])%M ][ k+v[i] ][0] += dp[i][j][k][0];
            }
            

            // 確定
            rep(x,10){
                if( k+x > M) break;
                dp[i+1][ (10*j + x)%M ][ k+x ][1] += dp[i][j][k][1];
            }
        }
        

        // cerr << dp[l][0][M][0] << " , " << dp[l][0][M][1] << nl;
        ll res = dp[l][0][M][0] + dp[l][0][M][1];
        return res;
    };


    ll ans = 0;
    rep1(m, 9*l){
        // cerr << "---- " << m << " ----" << nl;
        ll tmp = f(m);
        // cerr <<  tmp << nl;
        ans += tmp;
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
