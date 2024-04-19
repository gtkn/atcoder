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
    string S;
    cin >> S;


    ll n = S.size();
    
    vec(ll) v(n+1);
    rep(i,n) v[i+1] = S[i]-'a';


    vvec(ll) nxt(n+1,vec(ll)(26,llINF));
    rep(i,n+1){
        for(ll j=i+1; j<n+1; j++){
            chmin(nxt[i][v[j]],j);
        }
    }

    mint ans = 0;
    rep1(q1,n){
        ll t0 = v[q1];
        ll p1 = nxt[0][t0];
        if(p1 >= q1) continue;

        vvec(mint) dp(n+1,vec(mint)(n+1));
        dp[p1][q1] = 1;
        rep1(p,n)rep1(q,n)rep(c,26){
            ll pp = nxt[p][c], qq = nxt[q][c];
            if(pp>=q1 || qq>n) continue;
            dp[pp][qq] += dp[p][q];
        }

        rep1(p,n)rep1(q,n){
            if(nxt[p][t0] != q1) continue;
            ans += dp[p][q];
        }
    }

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
