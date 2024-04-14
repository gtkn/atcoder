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


void solve(){
    vvec(ll) A(3,vec(ll)(3));
    rep(i,3) rep(j,3) cin >> A[i][j];

    ll nn = 1;
    rep(_,9) nn *= 3;

    vec(ll) dp(nn); // 0 未定, 1 tak win, -1, aoki win

    vec(ll) san(10);
    san[0]=1;
    rep(i,9) san[i+1] = san[i]*3;


    auto chk = [&A](vvec(ll) vv)->ll{
        rep(i,3){
            if (vv[i][0]==vv[i][1] && vv[i][1]==vv[i][2]) return vv[i][0];
            if (vv[0][i]==vv[1][i] && vv[1][i]==vv[2][i]) return vv[0][i];
        }
        if (vv[0][0]==vv[1][1] && vv[1][1]==vv[2][2]) return vv[0][0];
        if (vv[0][2]==vv[1][1] && vv[1][1]==vv[2][0]) return vv[0][2];

        ll t=0, a=0, w=0;
        rep(i,3)rep(j,3){
            if(vv[i][j]==0) w++;
            if(vv[i][j]==1) t+=A[i][j];
            if(vv[i][j]==-1) a+=A[i][j];
        }
        if(w==0){
            if(t>a) return 1;
            else return -1;
        }

        return 0;
    };


    auto f = [&](auto f, vvec(ll) now, ll player)->ll{
        ll idx = 0;
        rep(i,3)rep(j,3){
            idx *= 3;
            idx += (now[i][j]+1);
        }
        // cerr << idx << " now " << endl;
        if(dp[idx]!=0) return dp[idx];

        ll c = chk(now);
        if(c!=0){
            dp[idx] = c;
            return c;
        }

        rep(i,3)rep(j,3)if(now[i][j]==0){
            now[i][j] = player;
            assert(f(f,now,-player)!=0);
            if(f(f,now,-player)==player){
                dp[idx] = player;
                return player;
            }
            now[i][j] = 0;
        }
        dp[idx] = -player;
        return -player;
    };

    vvec(ll) init(3,vec(ll)(3,0));
    ll res = f(f,init,1);

    if(res==1) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
