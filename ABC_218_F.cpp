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
//using mint = modint998244353;


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
    ll N,M;
    cin >> N >> M;
    
    vvec(Pll) gf(N),gr(N);
    rep(i,M){
        ll s,t;
        cin >> s >> t;
        --s; --t;
        gf[s].emplace_back(t,i);
        gr[t].emplace_back(s,i);
    }


    vec(ll) dp(N,llINF);
    queue<ll> q;
    q.push(0); dp[0]=0;
    while(!q.empty()){
        ll now = q.front(); q.pop();
        for(auto [nxt,ii]:gf[now]){
            if(chmin(dp[nxt],dp[now]+1)){
                q.push(nxt);
            }
        }
    }

    if(dp[N-1]>=llINF){
        rep(i,M){
            cout << -1 << nl;
        }
        return;
    }



    vec(ll) path0;
    ll now = N-1;
    while(now!=0){
        for(auto [nxt,ii]:gr[now]){
            if(dp[nxt]==dp[now]-1){
                path0.push_back(ii);
                now = nxt;
                break;
            }
        }
    }


    auto f1 = [&](ll idx){
        vec(ll) dp(N,llINF);
        queue<ll> q;
        q.push(0); dp[0]=0;
        while(!q.empty()){
            ll now = q.front(); q.pop();
            for(auto [nxt,ii]:gf[now]){
                if(ii==idx) continue;
                if(chmin(dp[nxt],dp[now]+1)){
                    q.push(nxt);
                }
            }
        }
        ll res = dp[N-1];
        if(res>=llINF) res=-1;
        return res;
    };




    ll d0 = path0.size();
    cerr << d0 << "!" << endl;
    for(ll idx:path0){
        cerr << idx << " ";
    }  cerr << endl;

    vec(ll) ans(M,d0);
    for(ll idx:path0){
        ans[idx] = f1(idx);
    }

    rep(i,M){
        cout << ans[i] << nl;
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
