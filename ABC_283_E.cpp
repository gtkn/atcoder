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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll H,W;
        cin >> H >> W;

        vvec(ll) A(H,vec(ll)(W));
        rep(i,H)rep(j,W) cin >> A[i][j];

        vvec(ll) dp(H+1,vec(ll)(4,llINF));

        rep(j,4) dp[0][j] = j/2;

        // rep(c,4){
        //     vec(ll) v0(W),v1(W);
        //     ll cnt = 0;
        //     if(c&1){
        //         rep(j,W) v0[j] = 1-A[0][j];
        //         cnt++;
        //     }
        //     else rep(j,W) v0[j] = A[0][j];
            
        //     if(c&2){
        //         rep(j,W) v1[j] = 1-A[1][j];
        //         cnt++;
        //     }
        //     else rep(j,W) v1[j] = A[1][j];
            
        //     bool isok=true;
        //     rep(i,W){
        //         bool tmp = true;
        //         if(i>0) if(v0[i]==v0[i-1]) tmp=false;
        //         if(v0[i]==v1[i]) tmp = false;
        //         if(i<W-1) if(v0[i]==v0[i+1]) tmp=false;
        //         if(tmp) isok=false;
        //     }
        //     if(isok) chmin(dp[1][c], cnt);
        // }

        auto chk = [&](vvec(ll) &vv){
            bool res = true;

            rep(jj,W){
                bool tmp = true;
                if(jj>0) if(vv[1][jj]==vv[1][jj-1]) tmp=false;
                if(jj+1<W) if(vv[1][jj]==vv[1][jj+1]) tmp=false;
                if(vv[1][jj]==vv[0][jj]) tmp=false;
                if(vv[1][jj]==vv[2][jj]) tmp=false;
                if(tmp) res = false;
            }
            return res;
        };


        rep(i,H)rep(j,4)rep(k,2){
            vvec(ll) vv(3,vec(ll)(W));

            if(i==0){
                if(!(j&2)) rep(jj,W) vv[0][jj] = 1-A[i][jj];
                else rep(jj,W) vv[0][jj] = A[i][jj];                
            }else{
                if(j&1) rep(jj,W) vv[0][jj] = 1-A[i-1][jj];
                else rep(jj,W) vv[0][jj] = A[i-1][jj];
            }

            if(j&2) rep(jj,W) vv[1][jj] = 1-A[i][jj];
            else rep(jj,W) vv[1][jj] = A[i][jj];

            if(i==H-1){
                if(!(j&2)) rep(jj,W) vv[2][jj] = 1-A[i][jj];
                else rep(jj,W) vv[2][jj] = A[i][jj];
            }else{
                if(k&1) rep(jj,W) vv[2][jj] = 1-A[i+1][jj];
                else rep(jj,W) vv[2][jj] = A[i+1][jj];
            }

            if(chk(vv)) chmin(dp[i+1][ 2*k + j/2 ], dp[i][j]+k);
        }

        // rep(i,H+1){
        //     rep(j,4) cout << dp[i][j] << " "; cout << endl;
        // }



        ll ans = llINF;
        rep(j,4) chmin(ans, dp[H][j]);

        if(ans==llINF) ans = -1;
        cout << ans << endl;



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
