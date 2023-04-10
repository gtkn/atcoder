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
        ll H,W,K;
        cin >> H >> W >> K;

        mint ans = 0;

        mcomb mc(H*W+10);

        vvec(mint) dp(H+1,vec(mint)(W+1));

        rep1(hh,H)rep1(ww,W){
            dp[hh][ww] = mc.c(hh*ww,K);
        }


        rep1(hh,H)rep1(ww,W){

            mint c = dp[hh][ww];

            c -= 2*dp[hh-1][ww];
            c -= 2*dp[hh][ww-1];

            c += 4*dp[hh-1][ww-1];
            if(hh-2>0) c += dp[hh-2][ww];
            if(ww-2>0) c += dp[hh][ww-2];
            
            if(hh-2>0) c -= 2*dp[hh-2][ww-1];
            if(ww-2>0) c -= 2*dp[hh-1][ww-2];

            if(hh-2>0 && ww-2>0)  c += dp[hh-2][ww-2];

            // cout << hh << " , " << ww << " : "<<c.val() <<" , " << (H+1-hh) << "*"<< (W+1-ww) << endl;

            ans += c * (hh*ww) * (H+1-hh)*(W+1-ww);



            // mint c = mc.c(hh*ww, K);
            // c -= 2*dp[hh-1][ww];
            // c -= 2*dp[hh][ww-1];
            // c += 3*dp[hh-1][ww-1];

            // dp[hh][ww] = c;

            // cout << hh << " , " << ww << " : "<<c.val() <<" , " << (H+1-hh) << "*"<< (W+1-ww) << endl;

            // ans += c * (hh*ww) * (H+1-hh)*(W+1-ww);


            // ll x = hh*ww;
            // // cout << hh << " , " << ww << " : "<<mc.c(x, K).val() <<" , " << x <<","<< (H+1-hh) << "*"<< (W+1-ww) << endl;

            // mint c0,c1,c2,c3;
            // c0 = mc.c(hh*ww, K);
            // c1 = mc.c((hh-1)*ww, K);
            // c2 = mc.c(hh*(ww-1), K);
            // c3 = mc.c((hh-2)*(ww-2), K);

            // mint c = c0 - 2*c1 - 2*c2 + 3*c3;

            // ans += c * x * (H+1-hh)*(W+1-ww);
        }


        // rep1(hh,H){
        //     rep1(ww,W) cout << dp[hh][ww].val() << " "; cout << endl;
        // }


        ans *= mc.c(H*W,K).inv();

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
