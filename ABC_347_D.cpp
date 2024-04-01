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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll a,b,C;
    cin >> a >> b >> C;
    ll nn = 60;

    vvvec(bool) dp(nn+1,vvec(bool)(nn+2,vec(bool)(nn+2,false)));

    dp[0][0][0] = true;
    rep(i,nn)rep(x,nn+1)rep(y,nn+1){
        if(!dp[i][x][y]) continue;

        if(bit(C,i)){
            dp[i+1][x+1][y] = true;
            dp[i+1][x][y+1] = true;
        }else{
            dp[i+1][x][y] = true;
            dp[i+1][x+1][y+1] = true;
        }
    }

    if(!dp[nn][a][b]) dame;

    ll X = 0, Y = 0;
    repr(i,nn){
        X <<= 1; Y <<= 1;
        if(bit(C,i)){
            if(a>0 && dp[i][a-1][b]){
                X += 1;
                a--;
            }else if(b>0 && dp[i][a][b-1]){
                Y += 1;
                b--;
            }else{
                cerr << "error" << a << b << endl;
            }
        }else{
            if(a>0 && b>0 && dp[i][a-1][b-1]){
                X += 1;
                Y += 1;
                a--; b--;
            }
        }
    }
    cout << X <<  " " << Y << endl;

    // cerr << __builtin_popcountll(X) << endl;
    // cerr << __builtin_popcountll(Y) << endl;
    // cerr << (X^Y) << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
