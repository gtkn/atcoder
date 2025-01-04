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
    ll L,R;
    cin >> L >> R;


    auto f = [](ll x)->ll{
        ll tmp = x;
        vec(ll) v;
        while(tmp>0){
            v.push_back(tmp%10);
            tmp /= 10;
        }

        ll n = v.size();
        reverse(all(v));

        // ll res = 0;
        // rep1(x,v[0]){
        //     ll a = 1;
        //     rep(_,n-1) 
        // }


        vvvec(ll) dp(n,vvec(ll)(10,vec(ll)(2,0)));
        dp[0][v[0]][0] = 1;
        
        rep(i,n-1)rep(j,10){
            rep(jj,v[0]){
                if(jj<v[i+1]) dp[i+1][jj][1] += dp[i][j][0];
                else if(jj==v[i+1]) dp[i+1][jj][0] += dp[i][j][0];
                dp[i+1][jj][1] += dp[i][j][1];
            }
        }

        ll res = 0;
        rep(j,10){
            res += dp[n-1][j][0]+dp[n-1][j][1];
        }
        // cerr << res << " , " << v[0] << ", " << n << endl;

        rep1(x,v[0]-1){
            ll a = 1;
            rep(_,n-1) a*=x;
            // cerr << a << endl;
            res += a;   
        }

        rep1(nn,n-1){
            rep1(x,9){
                ll a = 1;
                rep(_,nn-1) a*=x;
                // cerr << a << endl;
                res += a;
            }
        }



        return res;

    };


    ll ar = f(R);
    ll al = f(L-1);
    // cerr << ar << " " << al << endl;

    ll ans = ar-al;
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
