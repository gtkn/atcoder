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


    vvec(ll) g;

    vec(ll) dfs(ll now,ll frm){
        vec(ll) res = {now};
        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            for(ll vi:dfs(nxt,now)) res.push_back(vi);
        }
        return res;
    }




    void solve(){
        ll N;
        cin >> N;

        g.resize(N);
        vec(Pll) es;

        rep1(i,N-1){
            ll a,b;
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
            es.emplace_back(a,b);
        }

        ll M;
        cin >> M;
        vec(Pll) C(M);
        rep(i,M){
            ll u,v;
            cin >> u >> v;
            u--;v--;
            C[i] = {u,v};
        }

        vec(ll) x(N);
        rep(i,N-1){
            vec(ll) va = dfs(es[i].first, es[i].second);
            vec(ll) vb = dfs(es[i].second, es[i].first);

            vvec(bool) vv(N,vec(bool)(N));
            for(ll ai:va)for(ll bi:vb){
                vv[ai][bi] = true;
                vv[bi][ai] = true;
            }

            rep(j,M) if(vv[C[j].first][C[j].second]) x[i] |= (1<<j);
        }



        ll two = (1<<M);
        vvec(ll) dp(N,vec(ll)(two));
        dp[0][0]=1;

        rep(i,N-1)rep(j,two){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j|x[i]] += dp[i][j];
        }        

        cout << dp[N-1][two-1] << endl;

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
