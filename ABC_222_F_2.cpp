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

struct twomax{
    Pll p1,p2; // {value, index}, p1.first >= p2.first
    twomax(Pll p1={-llINF,-1}, Pll p2={-llINF,-1}):p1(p1),p2(p2){};

    void add(Pll p){
        if(p2.first <= p.first) swap(p2,p);
        if(p1.first <= p2.first) swap(p2,p1);
    }
};




void solve(){
    ll N;
    cin >> N;
    vvec(Pll) g(N);
    rep(_,N-1){
        ll a,b,c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }

    vec(ll) D(N);
    rep(i,N) cin >> D[i];

    vec(ll) dp(N);

    auto f1 = [&](auto f1, ll now, ll frm)->void{
        for(auto [nxt,c]:g[now])if(nxt!=frm){
            f1(f1,nxt,now);
            chmax(dp[now], c+dp[nxt]);
            chmax(dp[now], c+D[nxt]);
        }
    };
    f1(f1,0,0);

    // rep(i,N) cerr << dp[i] << " "; cerr << endl;


    vec(ll) ans(N);

    auto f2 = [&](auto f2, ll now, ll frm)->void{
        // cerr << now << " : ";
        // rep(i,N) cerr << dp[i] << " "; cerr << endl;

        ans[now] = dp[now];
        twomax tm;
        for(auto [nxt,c]:g[now]){
            tm.add({ max(dp[nxt],D[nxt])+c,nxt});
        }

        for(auto [nxt,c]:g[now])if(nxt!=frm){
            Pll p = tm.p1;
            if(nxt==p.second) p = tm.p2;

            ll memo0 = dp[now];
            dp[now] = p.first;
            ll memo1 = dp[nxt];
            chmax(dp[nxt], dp[now]+c);
            chmax(dp[nxt], D[now]+c);
            f2(f2,nxt,now);
            dp[now] = memo0;
            dp[nxt] = memo1;
        }
    };
    f2(f2,0,0);


    rep(i,N) cout << ans[i] << endl;







}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
