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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,M;
    cin >> N >> M;
    string S;
    cin >> S;

    vec(ll) ss(N+1);
    rep(i,N) ss[i+1] = S[i] - 'a';

    vec(ll) rem(N+1);
    vec(bool) used(26);
    rem[N] = 26;
    repr(i,N){
        if(used[ss[i+1]]) rem[i] = rem[i+1];
        else rem[i] = rem[i+1]-1;
        used[ss[i+1]] = true;
    }



    ll nn = (1<<N);
    vec(mint) memo(nn);
    rep(b,nn){
        vec(ll) pos;
        rep(i,N) if(bit(b,i)) pos.push_back(i+1);
        ll sz = pos.size();

        vvec(mint) dp(M+1,vec(mint)(sz+1));
        dp[0][0] = 1;
        rep(i,M+1)rep(j,sz){
            mint x = 1;            
            for(ll ii=i+1; ii<=M; ++ii){
                dp[ii][j+1] += dp[i][j] * x;
                x *= rem[pos[j]];
            }
        }

        rep(i,M+1) memo[b] += dp[i][sz] * mint(rem[i]).pow(M-i);
    }

    






    // vvvec(mint) dp(N+1,vvec(mint)(M+1, vec(mint)(N+2)));
    // dp[0][0][0] = 1;
    // vec(mint) ans(N+1);

    // rep(i,N+1)rep(j,M+1)rep(k,N+1){
    //     vec(bool) memo(26);
    //     for(ll ii = i+1; ii <= N; ++ii) memo[ss[ii]] = true;
    //     ll rem = 0;
    //     rep(c,26) if(!memo[c]) rem++;

    //     vec(bool) used(26);
    //     for(ll ii = i+1; ii <= N; ++ii){
    //         if(used[ss[ii]]) continue;
    //         used[ss[ii]] = true;
    //         rep(dj,M){
    //             ll jj = j+dj+1;
    //             if(jj > M) break;
    //             dp[ii][jj][k+1] += dp[i][j][k] * mint(rem).pow(dj);
    //         }
    //     }
    //     ans[k] += dp[i][j][k] * mint(rem).pow(M-j);
    //     // if(k==1) cerr << i << " " << j << " " << k << " : " << dp[i][j][k].val() << " " << ans[k].val() << endl;

    // }

    // rep(i,N+1) cout << ans[i].val() << " "; cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
