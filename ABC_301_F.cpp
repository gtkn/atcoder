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
 

    //---modintで組み合わせ扱う用の構造体---
    struct mcomb{
        ll nmax;
        vec(mint) fa,af;
        mcomb(ll sz=200020){
            nmax = sz;
            fa.resize(nmax+1);
            fa[0]=1;
            rep1(i,nmax) fa[i]=fa[i-1]*i;
            af.resize(nmax+1);
            rep(i,nmax+1) af[i]=fa[i].inv();
        }
        mint c(ll n, ll k){
            if(n<k || k<0 || n>nmax) return 0;
            return fa[n]*af[k]*af[n-k];
        }
    };


    void solve(){
        string S;
        cin >> S;
        ll N = S.size();

        ll a = 26, aa=52;


        vec(ll) vs(N);
        rep(i,N){
            if(S[i]=='?') vs[i] = -1;
            else if(S[i]>='a') vs[i] = a + (S[i]-'a');
            else vs[i] = (S[i]-'A');
        }

        // rep(i,N) cout << vs[i] << " "; cout << endl;
        // return;




        vvec(mint) dp(N+1,vec(mint)(a+3));
        dp[0][0]=1;
        
        vec(ll) cand;
        rep(i,aa) cand.push_back(i);


        vec(bool) used(a);
        ll x = 0;

        rep(i,N){
            ll ii = i+1;
            if(vs[i]>=0 && vs[i]<a){
                // 大文字
                dp[ii][1] += dp[i][0];
                if(used[vs[i]]){
                    rep1(j,a) dp[ii][a+1] += dp[i][j];
                }else{
                    if(x<a){
                        rep1(j,a){
                            dp[ii][a+1] += dp[i][j]*(j-x)/(a-x);
                            if(j<a) dp[ii][j+1] += dp[i][j]*(a-j)/(a-x);
                        }
                    }else{
                        dp[ii][a+1] += dp[i][a];
                    }
                }
                dp[ii][a+1] += dp[i][a+1];
                if(!used[vs[i]]) x++;
                used[vs[i]] = true;
            }
            if(vs[i]>=a){
                // 小文字
                dp[ii][0] += dp[i][0];
                rep1(j,a) dp[ii][j] += dp[i][j];
                dp[ii][a+2] += dp[i][a+1];
                dp[ii][a+2] += dp[i][a+2];                
            }
            if(vs[i]==-1){
                // ?
                dp[ii][0] += dp[i][0]*a;
                dp[ii][1] += dp[i][0]*a;
                rep1(j,a){
                    dp[ii][j] += dp[i][j]*26;
                    if(j<a) dp[ii][j+1] += dp[i][j]*(a-j);
                    dp[ii][a+1] += dp[i][j]*j;
                }
                dp[ii][a+1] += dp[i][a+1]*a;
                dp[ii][a+2] += dp[i][a+1]*a;
                dp[ii][a+2] += dp[i][a+2]*a;
            }

        }

        mint ans = 0;
        rep(j,a+3) ans += dp[N][j];
        cout << ans.val() << endl;

        

        



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
