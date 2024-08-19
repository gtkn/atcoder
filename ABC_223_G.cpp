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
    twomax(Pll p1={0,-1}, Pll p2={0,-1}):p1(p1),p2(p2){};

    void add(Pll p){
        if(p2.first <= p.first) swap(p2,p);
        if(p1.first <= p2.first) swap(p2,p1);
    }
};



void solve(){
    ll N;
    cin >> N;

    vvec(ll) g(N);
    rep(_,N-1){
        ll u,v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    vec(ll) dp0(N), dp1(N);

    auto f = [&](auto f,ll now, ll frm)->void{
        for(ll nxt:g[now])if(nxt!=frm){
            f(f,nxt,now);
        }
        
        for(ll nxt:g[now])if(nxt!=frm){
            dp0[now] += dp1[nxt];
        }

        for(ll nxt:g[now])if(nxt!=frm){
            chmax(dp1[now], dp0[now]-dp1[nxt]+dp0[nxt]+1);
        }
    };

    f(f,0,0);

    // rep(i,N) cerr << i << " : " << dp0[i] << ", " << dp1[i] << endl;


    ll th = max(dp0[0],dp1[0]);
    ll ans = 0;


    auto f2 = [&](auto f2,ll now, ll frm)->void{
        if(dp0[now]==th) ans++;

        // cerr << now << "---" << endl;
        // rep(i,N) cerr << i << " : " << dp0[i] << ", " << dp1[i] << endl;


        ll tot1 = 0;
        twomax tm;
        for(ll nxt:g[now]){
            tm.add({-dp1[nxt]+dp0[nxt]+1,nxt});
            tot1 += dp1[nxt];
        }

        for(ll nxt:g[now])if(nxt!=frm){
            ll memo0_now = dp0[now];
            ll memo1_now = dp1[now];

            dp0[now] = tot1-dp1[nxt];
            Pll p = tm.p1;
            if(p.second==nxt) p = tm.p2;
            dp1[now] = dp0[now]+p.first;

            ll memo0_nxt = dp0[nxt];
            ll memo1_nxt = dp1[nxt];

            dp0[nxt] += dp1[now];
            dp1[nxt] = max(dp1[nxt]+dp1[now], dp0[nxt]+dp0[now]+1);

            f2(f2,nxt,now);

            dp0[now] = memo0_now;
            dp1[now] = memo1_now;
            dp0[nxt] = memo0_nxt;
            dp1[nxt] = memo1_nxt;
        
        }

    };


    f2(f2,0,0);

    cout << ans << nl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
