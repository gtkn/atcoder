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
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

using mint = modint1000000007;
// using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N;
    cin >> N;
    vec(ll) p(N),q(N);
    rep(i,N) cin >> p[i];
    rep(i,N) cin >> q[i];
    rep(i,N) p[i]--;
    rep(i,N) q[i]--;

    vec(ll) g(N);
    rep(i,N) g[p[i]] = q[i];


    auto f_cycle = [](ll n)->vec(mint){
        if(n==1) return {1,1};

        vec(mint) res(n+1);
        vvvec(mint) dp(n+1,vvec(mint)(n+2,vec(mint)(2)));

        dp[0][0][0] = 1;
        rep(i,n)rep(j,n+1){
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j+1][0] += dp[i][j][0];
            dp[i+1][j+1][1] += dp[i][j][0];

            dp[i+1][j][0] += dp[i][j][1];
            dp[i+1][j+1][1] += dp[i][j][1];
        }
        rep(j,n+1) res[j] += dp[n][j][0];

        rep(i,n+1)rep(j,n+2)rep(k,2) dp[i][j][k] = 0;
        dp[0][0][1] = 1;
        rep(i,n)rep(j,n+1){
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j+1][0] += dp[i][j][0];
            dp[i+1][j+1][1] += dp[i][j][0];

            dp[i+1][j][0] += dp[i][j][1];
            dp[i+1][j+1][1] += dp[i][j][1];
        }
        rep(j,n+1) res[j] += dp[n][j][1];


        return res;
    };




    vec(bool) used(N);
    vec(ll) memo;

    rep(st,N){
        if(used[st]) continue;
        ll now = st, cnt = 0;
        while(!used[now]){
            used[now]=true;
            cnt++;
            now = g[now];
        }
        memo.push_back(cnt);
    }


    vec(mint) v_now = {1};
    for(ll c:memo){
        vec(mint) v_tmp = f_cycle(c);
        // cerr << c << " : ";
        // for(mint x:v_tmp) cerr << x.val() << " ";
        // cerr << endl;

        ll n = v_now.size(), m = v_tmp.size();
        vec(mint) v_nxt(n+m-1);
        rep(i,n)rep(j,m) v_nxt[i+j] += v_now[i]*v_tmp[j];
        swap(v_now,v_nxt);

        // cerr << "   ";
        // for(mint x:v_now) cerr << x.val() << " ";
        // cerr << endl;
    }


    vec(mint) fa(N+1);
    fa[0]=1;
    rep1(i,N) fa[i] = fa[i-1]*i;
    mint ans = 0;
    rep(i,v_now.size()){
        if(i&1) ans -= v_now[i] * fa[N-i];
        else ans += v_now[i] * fa[N-i];
    }

    cout << ans.val() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
