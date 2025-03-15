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
// using mint = modint;
// mint::set_mod(P);


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

// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}

void solve(){
    ll N,M,K;
    cin >> N >> M >> K;

    vvec(ll) g(N);
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        --a; --b;
        g[a].emplace_back(b);
    }


    ll nn = N*N;
    ll st = nn, gl = nn+1;

    auto id = [&](ll i, ll j)->ll{
        return i*N+j;
    };

    auto f = [&](ll d)->ll{

        mf_graph<ll> mf(nn+2);
        mf.add_edge(st, id(0,0), 0);
        mf.add_edge(id(0,0), gl, llINF);
        mf.add_edge(st,id(N-1,d), llINF);
        mf.add_edge(id(N-1,d), gl, 0);
        for(ll i=1; i<N-1; i++)rep(j,N){
            mf.add_edge(st, id(i,j), 0);
            mf.add_edge(id(i,j), gl, 0);
        }

        rep(i,N)rep(j,N-1) mf.add_edge(id(i,j), id(i,j+1), llINF);
        rep(a,N)for(ll b:g[a]){
            rep(j,N) mf.add_edge(id(a,j), id(b,j), 1);
            rep(j,N-1) mf.add_edge(id(a,j), id(b,j+1), llINF);
        }

        return mf.flow(st,gl);
    };



    ll l = 0, r = N;
    while(r-l>1){
        ll mid = (l+r)/2;
        if(f(mid)<=K) r = mid;
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
