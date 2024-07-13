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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


ll getCentroid(const vvec(ll)& g, ll n, ll root) {
    vec(ll) subtreeSize(n, 0);
    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        subtreeSize[u] = 1;
        for (ll v : g[u]) {
            if (v != p) {
                dfs(v, u);
                subtreeSize[u] += subtreeSize[v];
            }
        }
    };
    dfs(root, -1);
    ll centroid = root;
    ll minSubtreeSize = n;
    function<void(ll, ll)> findCentroid = [&](ll u, ll p) {
        ll maxSubtreeSize = n - subtreeSize[u];
        for (ll v : g[u]) {
            if (v != p) {
                maxSubtreeSize = max(maxSubtreeSize, subtreeSize[v]);
                findCentroid(v, u);
            }
        }
        if (maxSubtreeSize < minSubtreeSize) {
            minSubtreeSize = maxSubtreeSize;
            centroid = u;
        }
    };
    findCentroid(root, -1);
    return centroid;
}


void solve(){
    ll N;
    cin >> N;
    vvec(ll) g(N);
    rep(_,N-1){
        ll a,b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    ll rt = getCentroid(g, N, 0);
    // cerr << rt << endl;

    vec(ll) dist(N);
    vvec(Pll) vv;

    auto dfs = [&](auto dfs, ll now, ll frm, ll ii)->void{
        for(ll nxt:g[now])if(nxt!=frm){
            if(now==rt){
                ii++;
                vv.push_back({});
            }
            dist[nxt] = dist[now]+1;
            vv[ii].push_back({dist[nxt],nxt});
            dfs(dfs, nxt, now, ii);
        }
    };

    dfs(dfs, rt, -1, -1);

    ll nn = vv.size();
    rep(i,nn) sort(all(vv[i]));

    priority_queue<tri> pq; // dist, idx, ii
    rep(i,nn){
        pq.push({vv[i].back().first, vv[i].back().second, i});
        vv[i].pop_back();    
    }

    vec(Pll) ans;
    while(pq.size()>=2){
        auto [dist1, idx1, ii1] = pq.top(); pq.pop();
        auto [dist2, idx2, ii2] = pq.top(); pq.pop();
        ans.push_back({idx1,idx2});
        if(!vv[ii1].empty()){
            pq.push({vv[ii1].back().first, vv[ii1].back().second, ii1});
            vv[ii1].pop_back();
        }
        if(!vv[ii2].empty()){
            pq.push({vv[ii2].back().first, vv[ii2].back().second, ii2});
            vv[ii2].pop_back();
        }
    }

    if(pq.size()==1){
        auto [dist1, idx1, ii1] = pq.top(); pq.pop();
        ans.push_back({idx1,rt});
    }

    for(auto [a,b]:ans){
        cout << a+1 << ' ' << b+1 << endl;
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
