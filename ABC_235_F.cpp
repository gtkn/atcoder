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
    string N;
    cin >> N;
    ll M;
    cin >> M;
    vec(ll) C(M);
    rep(i,M) cin >> C[i];
    // vec(bool) cv(10);
    // rep(i,M) cv[C[i]] = true;

    ll nn = N.size();
    vec(ll) nv(nn);
    rep(i,nn) nv[i] = N[i]-'0';

    ll t = (1<<10);

    vvec(mint) dp_sum(nn+1,vec(mint)(t));
    vvec(mint) dp_cnt(nn+1,vec(mint)(t));
    mint a = 0;
    ll b = 0;

    rep(i,nn){
        rep(x,nv[i]){
            if(x==0&&i==0) continue;
            ll bb = b|(1<<x);
            dp_sum[i+1][bb] += a*10 + x;
            dp_cnt[i+1][bb] += 1;
        }
        a = a*10 + nv[i];
        b |= (1<<nv[i]);

        rep(j,t)rep(x,10){
            ll jj = j|(1<<x);
            dp_sum[i+1][jj] += dp_sum[i][j]*10 + dp_cnt[i][j]*x;
            dp_cnt[i+1][jj] += dp_cnt[i][j];
        }

        if(i>0){
            rep1(x,9){
                dp_sum[i+1][(1<<x)] += x;
                dp_cnt[i+1][(1<<x)] += 1;
            }
        }
    }
    
    ll cc = 0;
    for(ll ci:C) cc |= (1<<ci);

    mint ans = 0;
    rep(j,t)if((j&cc)==cc){
        ans += dp_sum[nn][j];
    }
    if((b&cc)==cc) ans += a;

    // cerr << nn << endl;
    // for(ll j:{3,7,15,31}){
    //     cerr <<j<<":"<< dp_sum[nn][j].val() << " " << dp_cnt[nn][j].val() << endl;
    // }


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
