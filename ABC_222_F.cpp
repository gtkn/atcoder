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

// 大きいほうから2つの値を保持する構造体
template<class T>
struct TwoMax{
    T a,b; // a >= b
    TwoMax():a(0),b(0){}
    void update(T x){
        if(x>a) swap(x,a);
        if(x>b) swap(x,b);
    }
    T getmax(){
        return a;
    }
    T getsecond(){
        return b;
    }
};


void solve(){
    ll N;
    cin >> N;

    vvec(Pll) g(N);
    rep(_,N-1){
        ll a,b,c;
        cin >> a >> b >> c;
        --a,--b;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }

    vec(ll) D(N);
    rep(i,N) cin >> D[i];

    vec(ll) dp(N);

    auto f = [&](auto f, ll now, ll frm)->void{
        chmax(dp[now],D[now]);
        for(auto [nxt,c]:g[now]){
            if(nxt==frm) continue;
            f(f,nxt,now);
            chmax(dp[now],dp[nxt]+c);
        }
    };

    f(f,0,0);

    vec(ll) ans(N);

    auto f2 = [&](auto f2, ll now, ll frm)->void{
        ans[now] = dp[now];
        if(ans[now]==D[now]){
            ans[now] = 0;
            for(auto [nxt,c]:g[now]){
                chmax(ans[now],dp[nxt]+c);
            }
        }

        // cerr << now << " " << nl;
        // rep(i,N) cerr << dp[i] << " "; cerr << nl;
        
        vec(ll) ch;
        for(auto [nxt,c]:g[now]){
            // if(nxt==frm) continue;
            ch.push_back(dp[nxt]+c);
        }
        ch.push_back(D[now]);
        sort(all(ch), greater<ll>());

        for(auto [nxt,c]:g[now]){
            if(nxt==frm) continue;

            ll memo_now = dp[now];
            ll memo_nxt = dp[nxt];

            dp[now] = ch[0];
            if(dp[nxt]+c==ch[0]) dp[now] = ch[1];

            chmax(dp[nxt], dp[now]+c);

            f2(f2,nxt,now);

            dp[now] = memo_now;
            dp[nxt] = memo_nxt;
        }
    };

    f2(f2,0,0);

    rep(i,N) cout << ans[i] << nl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
