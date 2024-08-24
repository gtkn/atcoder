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

void solve(){
    ll H,W,N;
    cin >> H >> W >> N;

    vvec(ll) c(H,vec(ll)(W));
    rep(i,H){
        string s;
        cin >> s;
        rep(j,W) c[i][j] = s[j]-'0';
    }

    ll nn = 1<<10;
    vvec(mint) dp(2*N+1,vec(mint)(nn));

    // rep(i,H) dp[0][ (1<<i) ] = 1;
    dp[0][nn-1] = 1;


    vvec(ll) c2(W,vec(ll)(H));
    rep(i,H)rep(j,W) c2[j][i] = c[i][j];

    vvvec(mint) g(2,vvec(mint)(nn,vec(mint)(nn)));
    rep(k,2){
        rep(now,nn){
            vec(ll) nxtv(10);
            rep(i,H)if(bit(now,i)){
                rep(j,W){
                    nxtv[ c[i][j] ] |= (1<<j);
                }
            }
            // rep1(x,9) g[k][now].push_back(nxtv[x]);
            rep1(x,9) g[k][now][nxtv[x]]++;
        }
        swap(H,W);
        swap(c,c2);
    }



    rep(i,2*N){
        rep(now,nn)rep(nxt,nn){
            dp[i+1][nxt] += dp[i][now]*g[i&1][now][nxt];
        }
    }

    // nn = (1<<2);
    // rep(i,2*N+1){
    //     cerr << i << endl;
    //     rep(now,nn) cerr << now << " ; " << dp[i][now].val() << endl;
    // }

    // rep(now,nn){
    //     cerr << now << " : ";
    //     rep(nxt,nn) cerr << g[1][now][nxt].val() << " ";
    //     cerr << endl;
    // }




    mint ans = 0;
    rep(now,nn) ans += dp[2*N][now];
    ans -= dp[2*N][0];
    cout << ans.val() << endl;




    // ll ii = 0;
    // rep(_,N){

    //     rep(now,nn){
    //         vec(ll) nxtv(10);
    //         rep(i,H)if(bit(now,i)){
    //             rep(j,W) nxtv[ c[i][j] ] |= (1<<j);
    //         }
    //         rep1(x,9) dp[ii+1][now|nxtv[x]] += dp[ii][now];
    //     }
    //     ii++;

    //     rep(now,nn){
    //         vec(ll) nxtv(10);
    //         rep(j,W)if(bit(now,j)){
    //             rep(i,H) nxtv[ c[i][j] ] |= (1<<i);
    //         }
    //         rep1(x,9) dp[ii+1][now|nxtv[x]] += dp[ii][now];
    //     }
    //     ii++;
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
