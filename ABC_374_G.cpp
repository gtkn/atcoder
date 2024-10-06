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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N;
    cin >> N;
    vec(string) S(N);
    rep(i,N) cin >> S[i];

    ll M = 26;
    vvec(bool) g(M,vec(bool)(M));
    rep(i,N) g[ S[i][0]-'A' ][ S[i][1]-'A' ] = true;

    vvec(ll) idx(M,vec(ll)(M,-1));
    ll n2 = 0;
    rep(i,M)rep(j,M){
        if(g[i][j]) idx[i][j] = n2++;
    }

    vvec(ll) g2(n2);
    rep(i,M)rep(j,M)if(g[i][j]){
        rep(k,M)if(g[j][k]){
            g2[ idx[i][j] ].push_back( idx[j][k] );
        }
    }

    scc_graph sg(n2);
    rep(i,n2)for(ll to : g2[i]) sg.add_edge(i,to);
    auto scc = sg.scc();

    vec(ll) sid(n2);
    ll n3 = scc.size();
    rep(i,n3)for(ll v : scc[i]) sid[v] = i;

    vector<set<ll>> g3(n3);
    rep(i,n2)for(ll to : g2[i]){
        if(sid[i]!=sid[to]) g3[sid[i]].insert(sid[to]);
    }

    vec(ll) incnt(n3),outcnt(n3);
    rep(i,n3)for(ll to : g3[i]){
        incnt[to]++;
        outcnt[i]++;
    }

    vector<set<ll>> g4(n3);
    rep(st,n3){
        queue<ll> q;
        q.push(st);
        while(!q.empty()){
            ll v = q.front(); q.pop();
            if(g4[st].count(v)) continue;
            if(st!=v) g4[st].insert(v);
            for(ll to : g3[v]) q.push(to);
        }
    }


    ll nn = n3*2;
    ll st = nn, gl = nn+1;

    mf_graph<ll> mf(nn+2);
    rep(i,n3) mf.add_edge(st,i,1);
    rep(i,n3)for(ll to : g4[i]) mf.add_edge(i,n3+to,1);
    rep(i,n3) mf.add_edge(n3+i,gl,1);

    ll res = mf.flow(st,gl);
    ll ans = n3 - res;
    cout << ans << endl;






    // dsu uf(n3);
    // rep(i,n3)for(ll to : g3[i]) uf.merge(i,to);


    // ll ans = 0;
    // for(auto grp : uf.groups()){
    //     ll intot=0,outtot=0;
    //     for(ll v : grp){
    //         if(incnt[v]==0) intot++;
    //         if(outcnt[v]==0) outtot++;
    //     }
    //     ans += max(intot,outtot);
    // }

    // cout << ans << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
