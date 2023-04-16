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
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;
using fiv = array<ll,5>;


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

    ll dp[7][7][7][7][37];

    ll vv[7][7];
    ll cum[7][7];

    ll f(ll i0,ll j0,ll k0,ll l0){
        return cum[j0][l0] - cum[i0][l0] - cum[j0][k0] + cum[i0][k0];
    }


    ll dfs(ll i0,ll j0,ll k0,ll l0, ll m0){
        if(dp[i0][j0][k0][l0][m0] >= 0) return dp[i0][j0][k0][l0][m0];
        if((j0-i0)*(l0-k0) < m0){
            dp[i0][j0][k0][l0][m0] = llINF;
            // cout << "?"<< endl;
            return llINF;
        }

        ll res = llINF;

        for(ll a=1; a<m0; a++){
            ll b=m0-a;
            for(ll x=i0+1; x<j0; x++){
                chmin( res, max( dfs(i0,x,k0,l0,a) ,  dfs(x,j0,k0,l0,b) ) );
            }

           for(ll y=k0+1; y<l0; y++){
                chmin( res, max( dfs(i0,j0,y,l0,a) ,  dfs(i0,j0,k0,y,b) ) );
                // chmin(res, dfs(i0,j0,k0,y,a,th) );
                // chmin(res, dfs(i0,j0,y,l0,b,th) );
            }
        }

        // cout << i0 <<" , " << j0 << ", " << k0 <<" , " << l0 << " , " << m0 <<"  : " << res << endl;

        dp[i0][j0][k0][l0][m0] = res;
        return res;
    }


 
    void solve(){
        ll H,W,T;
        cin >> H >> W >> T;

        rep(i,H)rep(j,W) cin >> vv[i][j];

        rep(i,H+1) cum[i][0] = 0;
        rep(j,W+1) cum[0][j] = 0;

        rep1(i,H){
            rep1(j,W) cum[i][j] = cum[i][j-1] + vv[i-1][j-1];
        }
        rep1(j,W){
            rep1(i,H) cum[i][j] += cum[i-1][j];
        }

        // rep(i,H+1){
        //     rep(j,W+1) cout << cum[i][j] << " "; cout << endl;
        // }

        set<ll> ths;
        for(ll i=0;i<H; i++)for(ll j=i+1; j<=H; j++){
            for(ll k=0; k<W; k++)for(ll l=k+1; l<=W; l++){
                ths.insert(f(i,j,k,l));
                // cout << i << "," << j << " / " << k << " ," << l << " :: " << f(i,j,k,l) << endl;
            }
        }



        ll ans = llINF; 
        for(ll th:ths){

            // if(th!=2) continue;

            // dp init
            rep(i,H+1)rep(j,H+1)rep(k,W+1)rep(l,W+1){
                ll tmp = f(i,j,k,l);
                if(tmp<th) tmp=-1;
                dp[i][j][k][l][1] = tmp;
                for(ll m=2; m<=T+1; m++) dp[i][j][k][l][m] = -1;
            }

            ll res = dfs(0,H,0,W,T+1);

            // rep(i,H+1)rep(j,H+1)rep(k,W+1)rep(l,W+1){
            //     rep1(m,T+1) cout << i<<"," <<j << ", " << k <<"," << l << " : " << dp[i][j][k][l][m] << endl;
            // }

            // cout << th << " ; " << res << endl;
            if(res<llINF) chmin(ans, res - th);
        }

        // if(ans==llINF) ans=-1;
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
