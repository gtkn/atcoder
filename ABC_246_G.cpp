//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (int i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目
#define vec(T) vector<T>
#define vvec(T) vector<vector<T>>
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
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

//------------------------------------------------

struct Solver{

    void solve(){
        ll N;
        cin >> N;
        vec(ll) A(N);
        rep1(i,N-1) cin >> A[i];
        A[0]=-1;

        vvec(ll) g(N);
        rep(_,N-1){
            ll u,v;
            cin >> u >> v;
            u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }



        ll ok=0, ng=1e9+7;
        while(ng-ok>1){
            ll mid = (ok+ng)/2;

            auto dfs = [&](auto dfs,ll now,ll frm)->ll{
                ll res = 0;
                for(ll nxt:g[now]){
                    if(nxt==frm) continue;
                    res += dfs(dfs, nxt, now);
                }
                res = max(res-1,0LL) + (A[now]>=mid);
                return res;
            };

            if(dfs(dfs,0,0)==0) ng=mid;
            else ok=mid;
        }

        cout << ok << endl;


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
