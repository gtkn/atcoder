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
    ll N;
    cin >> N;

    vvec(ll) g(N);
    rep(i,N-1){
        ll a,b; cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    auto f = [&](ll st)->vec(ll){
        vec(ll) dist(N,-1);
        queue<ll> q;
        q.push(st);
        dist[st] = 0;
        while(!q.empty()){
            ll v = q.front(); q.pop();
            for(auto nv:g[v]){
                if(dist[nv]!=-1) continue;
                dist[nv] = dist[v]+1;
                q.push(nv);
            }
        }

        ll maxdist = 0;
        ll maxv = 0;
        rep(i,N){
            if(chmax(maxdist,dist[i])) maxv = i;
        }

        vec(ll) path;
        ll now = maxv;
        while(now!=st){
            path.push_back(now);
            for(auto nv:g[now]){
                if(dist[nv]==dist[now]-1){
                    now = nv;
                    break;
                }
            }
        }
        path.push_back(st);
        return path;
    };

    vec(ll) path0 = f(0);
    vec(ll) path1 = f(path0[0]);

    ll X = path1[0], Y = path1.back();
    ll D = path1.size()-1;


    vec(ll) dp(N,-1);

    auto f2 = [&](ll st, ll ng, ll d)->ll{
        ll res = 0;
        queue<ll> q;
        q.push(st);
        dp[st] = 0;
        while(!q.empty()){
            ll v = q.front(); q.pop();
            if(dp[v]==d) res++;
            for(auto nv:g[v]){
                if(nv==ng) continue;
                if(dp[nv]!=-1) continue;
                dp[nv] = dp[v]+1;
                q.push(nv);
            }
        }
        return res;
    };


    if(D&1){
        ll A = path1[D/2], B = path1[D/2+1];
        ll M1 = f2(A,B,D/2);
        ll M2 = f2(B,A,D/2);
        mint ans = M1*M2;
        cout << ans.val() << endl;
    }else{
        ll C = path1[D/2];
        vec(ll) M;
        for(ll x:g[C]) M.push_back(f2(x,C,D/2-1));
        mint ans = 1;
        for(auto m:M) ans *= m+1;
        for(auto m:M) ans -= m;
        ans--;

        cout << ans.val() << endl;
    }











}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
