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
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    bool g[310][310];
    ll nn;
    ll ans = 0;
    bool used[310];
    ll ss[310];

    ll dp[310][310];
    ll dfs(ll r,ll l){
        //cout << l << ";" << r << endl;
        //assert(r>=l);
        if(r<l) swap(r,l);
        if(dp[r][l]>=0) return dp[r][l];

        ll tmp = 0;
        if(r>l){
            rep(k,nn+2){
                if(!g[k][r]) continue;
                chmax(tmp, dfs(l,k)+ss[r]);
            }
        }
        if(r==l){
            rep(j,nn+2)rep(k,nn+2){
                if(!g[j][r] || !g[k][r]) continue;
                chmax(tmp, dfs(j,k)+ss[r]);
            }
        }
        dp[r][l] = tmp;

        return dp[r][l];
    }


    void solve(){
        ll N;
        cin >> N;

        
        scc_graph scc(N);
        vvec(ll) gf(N);
        rep(i,N){
            rep(j,N){
                ll gij; cin >> gij;
                if(gij==1){
                    scc.add_edge(i,j);
                    gf[i].push_back(j);
                }
            }
        }

        vvec(int) vv = scc.scc();
        nn = vv.size();

        rep(i,310) ss[i]=0;
        rep(i,310)rep(j,310) dp[i][j]=-1;
        dp[0][0]=0;

        vec(ll) idx(N);
        rep(i,nn){
            ss[i+1]=vv[i].size();
            for(ll x:vv[i]) idx[x]=i+1;
            //for(ll x:vv[i]) cout << x << " "; cout << endl;
        }

        rep(i,nn+2)rep(j,nn+2) g[i][j]=false;
        rep(i,N){
            for(ll j:gf[i]) if(idx[i]!=idx[j]) g[idx[i]][idx[j]] = true;
        }
        rep1(i,nn) g[0][i]=true;
        rep1(i,nn) g[i][nn+1]=true;

        ans = dfs(nn+1,nn+1);
        
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
