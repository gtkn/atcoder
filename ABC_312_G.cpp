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


void solve(){
    ll N;
    cin >> N;

    vvec(ll) g(N);
    rep(_,N-1){
        ll a,b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    vec(ll) sz(N);

    auto dfs1 = [&](auto dfs1, ll now, ll frm)->ll{
        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            sz[now] += dfs1(dfs1, nxt, now);
        }
        sz[now]++;
        return sz[now];
    };

    dfs1(dfs1,0,0);


    ll ans = 0;
    auto dfs2 = [&](auto dfs2, ll now, ll frm)->void{
        vec(ll) v;
        for(ll nxt:g[now]){
            if(nxt==frm) v.push_back(N-sz[now]);
            else v.push_back(sz[nxt]);
        }

        ll nn = v.size();
        if(nn>=3){
            vvec(ll) dp(nn+1, vec(ll)(5));
            dp[0][0]=1;
            rep(i,nn)rep(j,4){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j+1] += dp[i][j]*v[i];
            }
            ans += dp[nn][3];
        }

        for(ll nxt:g[now]) if(nxt!=frm) dfs2(dfs2, nxt, now);

    };


    dfs2(dfs2,0,0);

    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
