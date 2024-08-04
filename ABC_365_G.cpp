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

    vec(ll) T(M),P(M);
    rep(i,M) cin >> T[i] >> P[i];

    vvec(Pll) vv(N+1);
    vec(ll) memo(N+1,llINF);
    rep(i,M){
        ll pi = P[i], ti = T[i];
        if(memo[pi]==llINF){
            memo[pi] = ti;
        }else{
            vv[pi].emplace_back(memo[pi],ti);
            memo[pi] = llINF;
        }
    }


    map<Pll,ll> mp;

    auto f = [&](ll a, ll b)->ll{
        // if(vv[a].size() > vv[b].size()) swap(a,b);

        ll res = 0;
        ll x = 0;
        for(auto [l,r]: vv[a]){
            while(x < vv[b].size() && vv[b][x].first < r){
                ll w = min(r,vv[b][x].second) - max(l,vv[b][x].first);
                if(w>0) res += w;
                if(r <= vv[b][x].second) break;
                x++;
            }
        }
        return res;
    };



    ll Q;
    cin >> Q;
    while(Q--){
        ll a,b;
        cin >> a >> b;

        if(mp.find({a,b})!=mp.end()){
            cout << mp[{a,b}] << nl;
            continue;
        }

        ll res = f(a,b);
        mp[{a,b}] = res;
        cout << res << nl;

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
