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
    ll N,M,K;
    cin >> N >> M >> K;

    vvec(ll) g(N);
    rep(_,M){
        ll a,b;
        cin >> a >> b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vec(ll) h(K),p(K);
    rep(i,K) cin >> p[i] >> h[i];
    rep(i,K) --p[i];


    vec(ll) dp(N,-llINF);

    priority_queue<Pll> pq; // HP, pos
    auto push = [&](ll hp, ll pos)->void{
        if(chmax(dp[pos],hp)) pq.push({hp,pos});
    };

    rep(i,K) push(h[i],p[i]);

    while(!pq.empty()){
        auto [hp,now] = pq.top(); pq.pop();
        if(dp[now]>hp) continue;
        for(ll nxt:g[now]) push(hp-1,nxt);
    }

    vec(ll) ans;

    rep(i,N) if(dp[i]>=0) ans.push_back(i+1);
    // rep(i,N) cerr << dp[i] << " "; cerr << endl; 

    cout << ans.size() << endl;
    for(ll a:ans) cout << a << " "; cout << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
