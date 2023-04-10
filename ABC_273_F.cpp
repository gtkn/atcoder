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
        ll N,X;
        cin >> N >> X;
        vec(ll) Y(N+1),Z(N+1);
        rep1(i,N) cin >> Y[i];
        rep1(i,N) cin >> Z[i];

        vec(ll) vp,vn;
        vp.push_back(0); vn.push_back(0);
        if(X>0) vp.push_back(X);
        else vn.push_back(X);

        rep1(i,N){
            if(Y[i]>0) vp.push_back(Y[i]);
            else vn.push_back(Y[i]);
        }

        rep1(i,N){
            if(Z[i]>0) vp.push_back(Z[i]);
            else vn.push_back(Z[i]);
        }

        sort(all(vp));
        sort(all(vn), greater<ll>());


        ll np=vp.size(),nn=vn.size();

        map<ll,ll> item;
        rep1(i,N) item[Y[i]] =  i;
        rep1(i,N) item[Z[i]] = -i;
        item[X] = 0;


        // set<ll> sp,sn;
        // sp.insert(0); sn.insert(0);
        // if(X>0) sp.insert(X);
        // else sn.insert(X);

        // for(ll a:Y){
        //     if(a>0) sp.insert(a);
        //     else sn.insert(a);
        // }

        // for(ll a:Z){
        //     if(a>0) sp.insert(a);
        //     else sn.insert(a);
        // }

        // map<ll,ll> mp,mn;
        // ll np=0,nn=0;
        // for(ll si:sp) mp[si] = np++;
        // for(ll si:sn) mn[si] = nn++;

        vvvec(ll) dp(np,vvec(ll)(nn,vec(ll)(2, llINF)));

        rep(k,2) dp[0][0][k] = 0;


        rep(i,np)rep(j,nn)rep(k,2){
            ll now = (k==0? vp[i] : vn[j]);

            if(i+1<np){
                if(item[vp[i+1]] > 0){
                    ll idx = item[vp[i+1]];
                    if(Z[idx] >= vn[j] && Z[idx] <= vp[i]){
                        chmin(dp[i+1][j][0], dp[i][j][k] + abs(vp[i+1]-now));
                    }
                }else{
                    chmin(dp[i+1][j][0], dp[i][j][k] + abs(vp[i+1]-now));
                }
            }
            if(j+1<nn){
                if(item[vn[j+1]] > 0){
                    ll idx = item[vn[j+1]];
                    if(Z[idx] >= vn[j] && Z[idx] <= vp[i]){
                        chmin(dp[i][j+1][1], dp[i][j][k] + abs(vn[j+1]-now));
                    }
                }else{
                    chmin(dp[i][j+1][1], dp[i][j][k] + abs(vn[j+1]-now));
                }
            }
        }

        ll ans = llINF;
        rep(i,np)rep(j,nn)rep(k,2){
            // cout << vp[i] << ", " << vn[j] << " , " << k << " : " << dp[i][j][k] << endl;
            if(vp[i] >= X && X >= vn[j]) chmin(ans, dp[i][j][k]);
        }

        if(ans>=llINF) ans=-1;

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
