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
    ll N;
    cin >> N;

    vec(string) S(N);
    rep(i,N) cin >> S[i];


    vvec(ll) vv(N+1,vec(ll)(N+1));
    vec(bool) touse(N,true);

    rep(i,N)rep(j,N){
        if(i==j){
            vv[i][i] = -llINF;
            continue;
        }

        if(S[i]==S[j]){
            touse[max(i,j)] = false;
            continue;
        }

        string ss = S[i] + S[j];
        vec(int) z = z_algorithm(ss);

        ll nn = ss.size();
        for(ll st = S[i].size(); st < nn; st++){
            if(z[st] >= S[i].size()){
                touse[i] = false;
                break;
            }
            if(z[st] == nn-st){
                vv[j][i] = z[st];
                break;
            }
        }
    }


    // rep(i,N){
    //     rep(j,N) cout << vv[i][j] << " "; cout << endl;
    // }
    // rep(i,N) cout << touse[i] << " "; cout << endl;

    ll M = (1<<(N+1));
    vvec(ll) dp(M, vec(ll)(N+1,-llINF));


    ll ini = (1<<N);
    rep(i,N) if(!touse[i]) ini += (1<<i);
    // rep(i,N) dp[ini][i] = 0;
    dp[ini][N] = 0;

    rep(used,M)rep(now,N+1){
        if(!bit(used,now)) continue;
        rep(nxt,N+1){
            if(bit(used,nxt)) continue;
            chmax(dp[used | (1<<nxt)][nxt], dp[used][now] + vv[now][nxt] );
        }
    }


    ll ans = 0, dpmax = 0;

    rep(i,N) chmax(dpmax, dp[M-1][i]);
    rep(i,N)if(touse[i]) ans += S[i].size();
    ans -= dpmax;

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
