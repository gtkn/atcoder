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

// LCA tekina
struct LCA{
    ll N,ln;
    vvec(ll) g;
    vvec(ll) par;
    vec(ll) dep;

    void _dfs(ll now,ll frm){
        par[now][0] = frm;
        dep[now] = dep[frm]+1;

        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            _dfs(nxt,now);
        }
    }


    LCA(vvec(ll) _g, ll rt = 0){
        g = _g;
        N = g.size();
        ln = log2(N) + 1;
        dep.resize(N);
        par = vvec(ll)(N,vec(ll)(ln));

        dep[rt] = -1;
        _dfs(rt,rt);

        rep(j,ln){
            if(j==0) continue;
            rep(i,N) par[i][j] = par[ par[i][j-1] ][j-1];
        }
    }


    ll get_dist(ll a,ll b){
        return dep[a] + dep[b] - 2*dep[get_lca(a,b)];
    }

    ll get_lca(ll a,ll b){
        if(dep[a]<dep[b]) swap(a,b);
        ll dd=dep[a]-dep[b];
        ll ex=0;
        while(dd){
            if(dd&1) a = par[a][ex];
            dd >>= 1;
            ex++;
        }

        if(a==b) return(a);
        repr(i,ln){
            if(par[a][i]==par[b][i]) continue;
            a = par[a][i];
            b = par[b][i];
        }
        return par[a][0];
    }

};




struct SparseTable {
    int N;
    vector<vector<ll>> table;
    
    SparseTable(const vector<ll>& arr) {
        N = arr.size();
        ll K = log2(N) + 1;
        table.resize(N, vector<ll>(K));
        
        for (ll i = 0; i < N; i++) {
            table[i][0] = arr[i];
        }
        
        for (ll j = 1; (1 << j) <= N; j++) {
            for (ll i = 0; i + (1 << j) <= N; i++) {
                table[i][j] = min(table[i][j-1], table[i + (1 << (j-1))][j-1]);
            }
        }
    }
    
    SparseTable() = default; // Add default constructor
    
    ll query(ll l, ll r) {
        ll j = log2(r - l + 1);
        return min(table[l][j], table[r - (1 << j) + 1][j]);
    }
};



struct LCA2{
    ll N;
    vvec(ll) g;
    vec(Pll) inout;
    vec(ll) dep;
    vec(ll) tour_dep, tour_index;
    SparseTable st;

    LCA2(vvec(ll) _g, ll rt = 0):g(_g){
        N = g.size();
        
        dep.resize(N);
        inout.resize(N);
        dfs(rt,rt,0);
        // cerr << "tour_index.size() = " << tour_index.size() << endl;

        st = SparseTable(tour_dep);    
    }

    void dfs(ll now, ll frm, ll d){
        dep[now] = d;
        inout[now].first = tour_index.size();
        tour_index.push_back(now);
        tour_dep.push_back(d);
        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            dfs(nxt,now,d+1);
            tour_index.push_back(now);
            tour_dep.push_back(d);
        }
        inout[now].second = tour_index.size();
        tour_index.push_back(now);
        tour_dep.push_back(d);
    }


    ll get_dist(ll a,ll b){
        ll l = min(inout[a].first,inout[b].first);
        ll r = max(inout[a].second,inout[b].second);
        // cerr << a << " " << b << " / " << l << " " << r << " : " << tour_dep.size() << endl;;
        ll lca_dep = st.query(l,r);
        return dep[a]+dep[b]-2*lca_dep;
    }


};




void solve(){
    ll N;
    cin >> N;


    vvec(ll) g(N);
    rep(_,N-1){
        ll u,v;
        cin >> u >> v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    // vec(ll) cnt(N+1);
    // rep(i,N) cnt[A[i]]++;

    vvec(ll) vv(N+1);
    rep(i,N) vv[A[i]].push_back(i);


    LCA2 lca(g);


    ll ans = 0;

    ll nn = sqrt(N);


    auto f = [&](ll cc){
        vec(ll) dp0(N),dp1(N),dp2(N); // 部分木での解、部分木根までの距離和、部分木内の数

        auto f2 = [&](auto f2, ll now, ll frm)->void{
            if(A[now]==cc) dp2[now] = 1;
            for(ll nxt:g[now])if(nxt!=frm){
                f2(f2,nxt,now);
                dp0[now] += dp0[nxt];
                dp0[now] += (dp1[nxt]+dp2[nxt])*dp2[now] + dp1[now]*dp2[nxt];
                dp1[now] += dp1[nxt] + dp2[nxt];
                dp2[now] += dp2[nxt];
            }
        };
        f2(f2,0,0);
        return dp0[0];
    };



    rep1(c,N){
        if(vv[c].size() < nn ){
            for(ll i:vv[c]){
                for(ll j:vv[c]){
                    if(i>=j) continue;
                    ans += lca.get_dist(i,j);
                }
            }
        }else{
            ans += f(c);
        }
    }

    cout << ans << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
