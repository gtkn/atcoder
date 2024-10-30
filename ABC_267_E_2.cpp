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

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vvec(ll) g(N);
    rep(_,M){
        ll x,y;
        cin >> x >> y;
        --x,--y;
        g[x].push_back(y);
        g[y].push_back(x);
    }



    auto f = [&](ll th)->bool{
        vec(ll) tot(N);
        rep(i,N)for(ll j:g[i]){
            tot[i] += A[j];
        }

        queue<ll> q;
        vec(bool) used(N);
        rep(i,N) if(tot[i] < th){
            q.push(i);
        }

        while(!q.empty()){
            ll now = q.front(); q.pop();
            if(used[now]) continue;
            used[now] = true;
            for(ll nxt:g[now]){
                if(used[nxt]) continue;
                tot[nxt] -= A[now];
                if(tot[nxt] < th){
                    q.push(nxt);
                }
            }
        }

        rep(i,N) if(!used[i]) return false;
        return true;
    };


    ll l = 0, r = llINF;
    while(r-l>1){
        ll mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << l << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
