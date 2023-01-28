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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

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
    ll N;
    vvec(ll) g;
    //vector<<ll,mint>> dp0,dp1;
    //map<ll,map<ll,mint>> dp0,dp1;
    vvec(mint) dp0,dp1;
    vec(ll) v;

    void dfs(ll now, ll frm){
        dp0[now][0]=1;
        dp1[now][1]=1;

        for(ll nxt:g[now]){
            if(nxt==frm) continue;

            dfs(nxt,now);



            vec(mint) memo0(N+1),memo1(N+1);
            
            rep(i,v[now]+1){
                rep(j,v[nxt]+1){
                    memo0[i+j] += dp0[now][i]*dp0[nxt][j];
                    memo0[i+j] += dp0[now][i]*dp1[nxt][j];
                    memo1[i+j] += dp1[now][i]*dp0[nxt][j];
                    memo1[i+j-1] += dp1[now][i]*dp1[nxt][j];
                }
            }
            v[now] += v[nxt];
            // rep(i,v[now]){
            //     dp0[now][i] = memo0[i];
            //     dp1[now][i] = memo1[i];
            // }
            dp0[now]=memo0;
            dp1[now]=memo1;


            // map<ll,mint> memo0 = dp0[now];
            // map<ll,mint> memo1 = dp1[now];
            // dp0[now].clear();
            // dp1[now].clear();
            
            // for(auto mi:memo0){
            //     for(auto mj:dp0[nxt]){
            //         dp0[now][mi.first+mj.first] += mi.second*mj.second;
            //     }
            //     for(auto mj:dp1[nxt]){
            //         dp0[now][mi.first+mj.first] += mi.second*mj.second;
            //     }
            // }
            // for(auto mi:memo1){
            //     for(auto mj:dp0[nxt]){
            //         dp1[now][mi.first+mj.first] += mi.second*mj.second;
            //     }
            //     for(auto mj:dp1[nxt]){
            //         dp1[now][mi.first+mj.first-1] += mi.second*mj.second;
            //     }
            // }

            // dp0[now]=memo0;
            // dp1[now]=memo1;

        }

    }


 
    void solve(){
        cin >> N;
        g.resize(N);
        v.resize(N,1);

        rep(_,N-1){
            ll a,b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }


        // dp0.resize(N);
        // dp1.resize(N);


        dp0 = vvec(mint)(N,vec(mint)(N+1));
        dp1 = vvec(mint)(N,vec(mint)(N+1));

        dfs(0,0);

        rep1(x,N){
            mint ans = dp0[0][x] + dp1[0][x];
            cout << ans.val() << endl;
        }




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
