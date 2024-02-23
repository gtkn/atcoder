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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------




void solve(){
    ll N;
    cin >> N;

    vvec(ll) g(N);
    rep(_,N-1){
        ll u,v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fenwick_tree<ll> fw(N);
    vec(ll) cum(N);

    auto f = [&](auto f, ll now,ll frm)->void{
        ll c_now_bef = fw.sum(0,now);
        ll c_frm_bef = fw.sum(0,frm);

        fw.add(now,1);

        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            f(f,nxt,now);
        }

        if(now!=frm){
            ll c_now_aft = fw.sum(0,now);
            ll c_frm_aft = fw.sum(0,frm);

            ll c1 = now - (c_now_aft - c_now_bef);
            ll c2 = c_frm_aft - c_frm_bef;
            cum[now] += c1;
            cum[now] -= c2;
            cum[0] += c2;
        }
    };

    f(f,0,0);

    vec(ll) ans(N);
    ll tot = 0;

    auto f2 = [&](auto f2, ll now, ll frm)->void{
        tot += cum[now];
        ans[now] = tot;

        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            f2(f2, nxt, now);
        }

        tot -= cum[now];
    };
    f2(f2,0,0);

    rep(i,N) cout << ans[i] << " "; cout << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
