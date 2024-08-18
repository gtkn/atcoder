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

//using mint = modint1000000007;
using mint = modint998244353;


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
    ll N,M,K;
    cin >> N >> M >> K;
    vec(ll) A(M);
    rep(i,M) cin >> A[i];
    rep(i,M) A[i]--;

    vvec(Pll) g(N);
    rep(i,N-1){
        ll u,v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }

    vec(ll) cnt(N-1);

    rep(i,M-1){
        ll st = A[i], gl = A[i+1];
        // cerr << i << " ; " << st << " " << gl << endl;

        vec(ll) dist(N,llINF);
        queue<ll> q;
        q.push(st);
        dist[st] = 0;
        while(!q.empty()){
            ll now = q.front(); q.pop();
            for(auto [nxt,_]:g[now]){
                if(chmin(dist[nxt],dist[now]+1)) q.push(nxt);
            }
        }

        {
            ll now = gl;
            while(now!=st){
                for(auto [nxt,ii]:g[now]){
                    if(dist[nxt]+1 != dist[now]) continue;
                    cnt[ii]++;
                    now = nxt;
                    break;
                }
            }
        }
    }


    ll D = 0;
    rep(i,N-1) D += cnt[i];
    ll th = (D+K)/2;

    // cerr << "D = " << D << endl;
    // rep(i,N-1) cerr << cnt[i] << " "; cerr << endl;

    if((D+K)&1 || th<0){
        cout << 0 << endl;
        return;
    }


    vvec(mint) dp(N,vec(mint)(th+1));

    dp[0][0] = 1;
    rep(i,N-1)rep(j,th+1){
        dp[i+1][j] += dp[i][j];
        ll jj = j+cnt[i];
        if(jj<=th) dp[i+1][jj] += dp[i][j];
    }

    mint ans = dp[N-1][th];
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
