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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

ll op(ll a,ll b){return max(a,b);}
ll ee(){return 0;}


void solve(){
    ll N,M;
    cin >> N >> M;

    vvec(Pll) g(N);
    rep(_,M){
        ll u,v,w;
        cin >> u >> v >> w;
        --u,--v;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }

    ll K;
    cin >> K;
    vec(ll) A(K);
    rep(i,K) cin >> A[i], --A[i];

    ll D;
    cin >> D;
    vec(ll) X(D+1);
    rep1(i,D) cin >> X[i];


    segtree<ll,op,ee> seg(X);

    auto f = [&](ll l0, ll th)->ll{ // l0日目以降で初めてXがth以上になる日
        if(seg.prod(l0,D+1) < th) return llINF;
                
        ll l = l0, r = D+1;
        while(r-l>1){
            ll mid = (l+r)/2;
            if(seg.prod(l0,mid) < th) l = mid;
            else r = mid;
        }
        return l;
    };




    priority_queue<tri,vector<tri>,greater<tri>> pq; // 何日目,残り距離,部屋
    vec(Pll) dp(N,{llINF,0}); // 何日目,残り距離

    auto push = [&](ll day, ll rem, ll heya){
        if(dp[heya].first > day){
            dp[heya] = {day,rem};
            pq.emplace(day,-rem,heya);
        }else if(dp[heya].first == day && dp[heya].second < rem){
            dp[heya] = {day,rem};
            pq.emplace(day,-rem,heya);
        }
    };

    for(ll ai:A) push(0,0,ai);


    while(!pq.empty()){
        auto [d0,r0,h0] = pq.top(); pq.pop();
        r0 = -r0;
        if(dp[h0].first < d0) continue;
        if(dp[h0].first == d0 && dp[h0].second > r0) continue;

        for(auto [h1, w]:g[h0]){
            if(w > r0) continue;
            push(d0,r0-w,h1);
        }

        for(auto [h1, w]:g[h0]){
            if(dp[h1].first < dp[h0].first+1) continue;

            ll xday = f(d0+1,w);
            // cerr << d0 << ", " << h0 << " : " << h1 << ", " << w << ", " << xday << endl;
            if(xday>D) continue;
            push(xday, X[xday]-w, h1);
        }
    }

    rep(i,N){
        if(dp[i].first == llINF) cout << -1 << endl;
        else cout << dp[i].first << endl;
    
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
