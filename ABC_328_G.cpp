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
//using mint = modint998244353;


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

void solve(){
    ll N,C;
    cin >> N >> C;

    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];


    ll nn = (1<<N);
    vec(ll) dp(nn,llINF);
    dp[0]=0;
    rep(now,nn){
        ll st = __builtin_popcount(now);

        for(ll l=0; l<N; l++){
            if(bit(now,l)) continue;
            ll tmp = C+dp[now], nxt = now;
            rep(d,N){
                ll m = l+d;
                if(m>=N) break;
                if(bit(now,m)) break;
                tmp += abs(B[st+d]-A[m]);
                nxt |= (1<<m);
                chmin(dp[nxt], tmp);
            }
        }
    }

    cout << dp[nn-1]-C << endl;




    // ll nn = (1<<N);
    // vvec(ll) dp(nn,vec(ll)(N,llINF));
    // rep(i,N){
    //     // if(i==0) dp[(1<<i)][i] = abs(B[0]-A[0]);
    //     // else dp[(1<<i)][i] = C + abs(B[0]-A[i]);
    //     dp[(1<<i)][i] = C + abs(B[0]-A[i]);
    // }

    // rep(now,nn){
    //     vec(ll) cand;
    //     ll sz = 0;//__builtin_popcount(now);
    //     rep(i,N){
    //         if(bit(now,i)) sz++;
    //         else cand.push_back(i);
    //     }

    //     rep(t,N){
    //         if(dp[now][t]>=llINF) continue;

    //         // rep(i,N){
    //         for(ll i:cand){
    //             if(bit(now,i)) continue;
    //             ll tmp = dp[now][t];
    //             tmp += abs(B[sz]-A[i]);
    //             if(t+1 != i) tmp+=C;
    //             chmin( dp[now|(1<<i)][i], tmp );
    //         }
    //     }
    // }

    // ll ans = llINF;
    // rep(t,N) chmin(ans, dp[nn-1][t]-C);
    // cout << ans << endl;







    // auto f = [&](ll b){
    //     ll n = __builtin_popcount(b)+1;
    //     vvec(ll) vv;
    //     vec(ll) v;
    //     rep(i,N){
    //         v.push_back(A[i]);
    //         if(b&1){
    //             vv.push_back(v);
    //             v.clear();
    //         }
    //         b>>=1;
    //     }
    //     vv.push_back(v);

    //     assert(!v.empty());
    //     assert(!vv.empty());
    //     // cout << vv.size() << ", "<< (__builtin_popcount(b)) << " : " << b << endl;
    //     assert(vv.size()==n);


    //     // ll n = vv.size();
    //     ll m = (1<<n);
    //     vec(ll) sz(n);
    //     rep(i,n) sz[i] = vv[i].size();

    //     vec(ll) dp(m,llINF);
    //     dp[0]=0;
    //     rep(now,m){
    //         ll st = 0;
    //         rep(i,n) if(bit(now,i)) st+=sz[i];

    //         rep(i,n){
    //             if(bit(now,i)) continue;
    //             ll diff = 0;
    //             rep(j,sz[i]) diff += abs(B[st+j]-vv[i][j]);
    //             chmin(dp[now|(1<<i)], dp[now]+diff);
    //         }
    //     }
    //     return dp[m-1] + (n-1)*C;
    // };


    // ll ans = llINF;
    // rep(pt,(1<<(N-1))){
    //     chmin(ans,f(pt));
    // }

    // cout << ans << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
