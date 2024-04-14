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

mint dp[61][11][11][11][2][2][2];


void solve(){
    ll N,A1,A2,A3;
    cin >> N >> A1 >> A2 >> A3;

    memset((void*)dp, 0, sizeof(dp));

    dp[0][0][0][0][0][0][0] = 1;
    
    ll tmpn = N;
    vec(bool) nv;
    rep(i,60){
        nv.push_back(tmpn&1);
        tmpn >>= 1;
    }

    reverse(all(nv));

    auto chk = [](const ll& now, const ll& x, const ll& n)->ll{
        if(now==0){
            if(n==0){
                if(x==0) return 0;
                else return -1;
            }else{
                if(x==0) return 1;
                else return 0;
            }
        }else{
            return 1;
        }
    };


    rep(i,60){
        rep(a1,11)rep(a2,11)rep(a3,11)rep(f1,2)rep(f2,2)rep(f3,2){
            rep(k1,2)rep(k2,2)rep(k3,2){
                if(k1^k2^k3!=0) continue;
                ll g1 = chk(f1,k1,nv[i]);
                ll g2 = chk(f2,k2,nv[i]);
                ll g3 = chk(f3,k3,nv[i]);
                if(g1<0 || g2<0 || g3<0) continue;

                ll b1 = (a1*2+k1)%A1;
                ll b2 = (a2*2+k2)%A2;
                ll b3 = (a3*2+k3)%A3;

                dp[i+1][b1][b2][b3][g1][g2][g3] += dp[i][a1][a2][a3][f1][f2][f3];
            }
        }
    }

    mint ans = 0;
    rep(f1,2)rep(f2,2)rep(f3,2){
        ans += dp[60][0][0][0][f1][f2][f3];
    }


    ans -= 1;

    ll lcm = A1*A2/__gcd(A1,A2);
    ans -= N/lcm;

    lcm = A1*A3/__gcd(A1,A3);
    ans -= N/lcm;

    lcm = A2*A3/__gcd(A2,A3);
    ans -= N/lcm;

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
