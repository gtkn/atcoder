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
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 60;
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


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll H,W;
    cin >> H >> W;

    vvec(char) A(H+2,vec(char)(W+2,'#'));
    rep1(i,H)rep1(j,W) cin >> A[i][j];

    Pll st,gl;
    rep1(i,H)rep1(j,W){
        if(A[i][j]=='S') st = {i,j};
        if(A[i][j]=='T') gl = {i,j};
    }

    ll N;
    cin >> N;
    vec(ll) R(N),C(N),E(N);
    rep(i,N) cin >> R[i] >> C[i] >> E[i];


    auto dist = [&](ll sh, ll sw)->vvec(ll){
        vvec(ll) res(H+2,vec(ll)(W+2,llINF));
        res[sh][sw] = 0;
        queue<Pll> q;
        q.push({sh,sw});
        while(!q.empty()){
            auto [h,w] = q.front(); q.pop();
            rep(i,4){
                ll nh = h+dh[i], nw = w+dw[i];
                // if(nh<0||nh>=H+2||nw<0||nw>=W+2) continue;
                if(A[nh][nw]=='#') continue;
                if(chmin(res[nh][nw],res[h][w]+1)) q.push({nh,nw});
            }
        }
        return res;
    };


    R.push_back(st.first); C.push_back(st.second); E.push_back(0);
    R.push_back(gl.first); C.push_back(gl.second); E.push_back(0);

    vvec(ll) g(N+2);
    rep(i,N+2){
        vvec(ll) d = dist(R[i],C[i]);
        rep(j,N+2){
            if(i==j) continue;
            if(d[R[j]][C[j]]<=E[i]) g[i].push_back(j);
        }
    }

    vec(bool) dp(N+2);
    dp[N] = true;
    queue<ll> q;
    q.push(N);
    while(!q.empty()){
        ll now = q.front(); q.pop();
        for(ll nxt:g[now]){
            if(dp[nxt]) continue;
            dp[nxt] = true;
            q.push(nxt);
        }
    }

    if(dp[N+1]) sayyn;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
