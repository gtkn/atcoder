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
#define watch(x) // cerr << (#x) << " is " << (x) << endl
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


void solve(){
    ll H,W;
    cin >> H >> W;

    vvec(ll) A(H,vec(ll)(W));
    rep(i,H) rep(j,W) cin >> A[i][j];
    // cerr << "ok" << endl;

    vec(Pll) v;
    rep(i,H){
        ll amin=llINF,amax=-llINF;
        rep(j,W)if(A[i][j]!=0){
            chmin(amin,A[i][j]);
            chmax(amax,A[i][j]);
        }
        if(amin!=llINF) v.push_back({amin,amax});
    }

    // cerr << "ok" << endl;
    
    sort(all(v));
    ll nn = v.size();
    rep(i,nn-1){
        if(v[i].second > v[i+1].first) sayno;
    }

    // cerr << "ok" << endl;

    vvec(ll) g(W);

    for(vec(ll) row:A){
        map<ll,vector<ll>> mp;
        rep(j,W)if(row[j]!=0) mp[row[j]].push_back(j);

        vvec(ll) vv;
        for(auto [_,ids]:mp) vv.push_back(ids);

        ll vvsz = vv.size();
        // cerr << vvsz << endl;
        
        rep(i,vvsz-1){
            // cerr << i << "!" << endl;
            if( (vv[i].size() > 1) && (vv[i+1].size() > 1) ){
                ll ww = g.size();
                g.push_back({});
                for(ll x:vv[i]){
                    g[x].push_back(ww);
                }
                for(ll y:vv[i+1]){
                    g[ww].push_back(y);
                }
            }else{
                for(ll x:vv[i])for(ll y:vv[i+1]){
                    g[x].push_back(y);
                }
            }
        }
    }
    // cerr << "ok" << endl;

    scc_graph scc_graph(g.size());
    rep(i,g.size())for(ll j:g[i]){
        scc_graph.add_edge(i,j);
    }

    auto scc = scc_graph.scc();
    
    if(scc.size() == g.size()) sayyn;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
