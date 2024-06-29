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


// #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
// #define v3(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
// #define v4(type, name, a, b, c, ...) vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

//------------------------------------------------

const ll B = 16;
ll dp[B+1][B+1][2][2]; // i桁目までみて、Sのj文字目まで一致していて、th以下かどうか、0かどうか

ll f(string S, ll th){
    ll n = S.size();

    vec(ll) sv(n);
    rep(i,n) sv[i] = S[i]-'0';
    vec(ll) tv(B);
    rep(i,B){
        tv[i] = th%10;
        th /= 10;
    }

    // reverse(all(sv));
    reverse(all(tv));

    // for(ll x:sv) cerr << x << " "; cerr << endl;
    // for(ll x:tv) cerr << x << " "; cerr << endl;

    rep(i,B+1)rep(j,B+1)rep(k,2) rep(l,2) dp[i][j][k][l] = 0;
    dp[0][0][0][0] = 1;


    rep(i,B)rep(j,n+1)rep(k,2)rep(l,2){        
        rep(d,10){
            if(k==0 && d>tv[i]) continue;
            ll nk = 1;
            if(k==0 && d==tv[i]) nk=0;
            ll nl = 1;
            if(l==0 && d==0) nl = 0;

            if(j==0){
                dp[i+1][j][nk][nl] += dp[i][j][k][l];
            }
            if(j<n){
                if(d==sv[j] && nl==1){
                    dp[i+1][j+1][nk][nl] += dp[i][j][k][l];
                }
            }else{
                dp[i+1][j][nk][nl] += dp[i][j][k][l];
            }
        }
    }

    // rep(i,B+1)rep(k,2)rep(l,2){
    //     if(dp[i][n][k][l]==0) continue;
    //     cerr << i << " " << k << " " << l << " : " << dp[i][n][k][l] << endl;
    // }

    

    ll res = dp[B][n][0][1] + dp[B][n][1][1];
    // cerr << dp[B][n][0][1] <<" + " <<  dp[B][n][1][1] << " = " << res << endl;
    return res;
}




void solve(){
    string S;
    cin >> S;
    ll L,R;
    cin >> L >> R;

    ll ans = f(S,R) - f(S,L-1);
    cout << ans << endl;

}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
