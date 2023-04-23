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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    mint memo[44][44][44];
    bool done[44][44][44];

    void solve(){
        ll N,M;
        cin >> N >> M;

        vec(string) S(N);
        rep(i,N) cin >> S[i];

        auto f = [&](auto f, ll l,ll r, ll k) -> mint{
            if(l==r) return 1;
            if(k==M){
                if(r-l == 1) return 1;
                return 0;
            }
            if(done[l][r][k]) return memo[l][r][k];

            vec(mint) dp(N+1);
            dp[l] = 1;
            rep(d,10){
                vec(mint) p(N+1); swap(dp,p);
                for(ll i=l; i<=r; i++){
                    for(ll j=i; j<=r; j++){
                        dp[j] += p[i]*f(f,i,j,k+1);
                        if(j==r) break;
                        if(S[j][k] != '?' && S[j][k] != '0'+d) break;
                    }
                }
            }

            done [l][r][k] = true;
            return memo[l][r][k] = dp[r];
        };

        cout << f(f,0,N,0).val() << endl;


    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
