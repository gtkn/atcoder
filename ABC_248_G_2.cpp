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



void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vvec(ll) g(N);
    rep(_,N-1){
        ll u,v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    vector<map<ll,mint>> cnt(N),sum(N);
    rep(i,N) cnt[i][A[i]] = sum[i][A[i]] = 1;


    auto f = [&](auto f, ll now, ll frm)->mint{
        mint res = 0;

        // cerr << "--- " << now << endl;
        for(ll nxt:g[now])if(nxt!=frm){
            res += f(f,nxt,now);

            for(auto [x,cx]:cnt[now])for(auto [y,cy]:cnt[nxt]){
                // cerr << x <<" " << cx.val() << " " << sum[now][x].val() << ", ";
                // cerr << y <<" " << cy.val() << " " << sum[nxt][y].val() <<  endl;
                mint tmp = __gcd(x,y);
                tmp *= (cx*sum[nxt][y] + cy*sum[now][x]);
                res += tmp;
            }

            for(auto [y,cy]:cnt[nxt]){
                cnt[now][ __gcd(A[now],y) ] += cy;
            }

            for(auto [y,sy]:sum[nxt]){
                sum[now][ __gcd(A[now],y) ] += sy + cnt[nxt][y];
            }
        }

        // cerr << "res " << res.val() << endl;

        return res;
    };


    mint ans = f(f,0,0);
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
