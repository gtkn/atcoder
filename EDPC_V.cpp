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
using l3 = __int128;

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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

// modがテストケースで変わるとき
using mint = modint;


void solve(){
    ll N, M;
    cin >> N >> M;
    mint::set_mod(M);

    vvec(ll) g(N);
    rep(_,N-1){
        ll x,y;
        cin >> x >> y;
        --x;--y;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    vec(mint) dp(N);

    auto dfs1 = [&](auto dfs1, ll now, ll frm)->void{
        dp[now]=1;

        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            dfs1(dfs1, nxt, now);
            dp[now] *= (dp[nxt]+1);
        }
    };

    dfs1(dfs1, 0,0);


    vec(mint) ans(N);

    auto dfs2 = [&](auto dfs2, ll now, ll frm)->void{
        vec(mint) b;
        vec(ll) ids;
        for(ll nxt:g[now]){
            ids.push_back(nxt);
            b.push_back(dp[nxt]);
        }

        ll nn = ids.size();
        vec(mint) bl(nn+1),br(nn+1);
        bl[0] = 1;
        rep(i,nn) bl[i+1] = bl[i]*(b[i]+1);
        br[nn] = 1;
        repr(i,nn) br[i] = br[i+1]*(b[i]+1);


        dp[now] = bl[nn];
        ans[now] =dp[now];

        rep(i,nn){
            ll nxt = ids[i];
            if(nxt==frm) continue;
            dp[now] = bl[i]*br[i+1];
            dfs2(dfs2, nxt, now);
        }

    };


    dfs2(dfs2,0,0);
    rep(i,N) cout << ans[i].val() << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
