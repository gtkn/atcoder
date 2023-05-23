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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------









//---Rollback Union Find---
struct RollbackUnionFind{

    // 更新履歴を記録するための構造体
    struct Update{
        ll& a; ll x;
        Update(ll& a):a(a),x(a){}        
    };

    // [x]がリーダーのグループサイズ、要素の親idx、要素から親までのランクの配列、グループが持つ辺の数
    vector<ll> gsize,parent,rank,edges;
    // 操作履歴
    using Hist = vector<Update>;
    vector<Hist> history;


    //コンストラクタ　各配列を初期化
    RollbackUnionFind(ll N){
        gsize = vector<ll>(N,1);
        parent = vector<ll>(N,-1);
        rank = vector<ll>(N);
        edges = vector<ll>(N);
    }

    //親を求める
    ll findparent(ll x){
        if(parent[x]<0) return x;
        else return findparent(parent[x]);//縮約無し
    }

    //その要素の属するグループのサイズを得る
    ll getgsize(ll x){
        return gsize[findparent(x)];
    }

    //その要素の属するグループの辺の数を得る
    ll getedgesize(ll x){
        return edges[findparent(x)];
    }


    // 2要素x,yの属するグループを合併
    void unite(ll x, ll y){
        x = findparent(x);
        y = findparent(y);
        history.push_back(Hist());
        Hist& h = history.back();

        if(x==y){
            h.push_back(edges[x]); // 更新前に記録
            edges[x]++;
        }else{
            if(rank[x] < rank[y]) swap(x,y);

            h.push_back(gsize[x]);
            h.push_back(parent[y]);
            h.push_back(gsize[y]);
            h.push_back(edges[x]);
            gsize[x] += gsize[y];
            parent[y] = x;
            gsize[y] = 0;
            edges[x] += edges[y]+1;

            if(rank[x]==rank[y]){
                h.push_back(rank[x]);
                rank[x]++;
            }
        }        
        return;
    }

    // 2要素x,yが同じ集合に属するかどうか
    bool same(ll x, ll y){
        return findparent(x) == findparent(y);
    }


    // unite操作を1回戻す
    void rollback(){
        for(auto [a,x] : history.back()) a=x;
        history.pop_back();
    }


};




struct Solver{



    void solve(){
        ll N;
        cin >> N;

        vec(Pll) ab;
        rep(i,N){
            ll a,b;
            cin >> a >> b;
            --a; --b;
            ab.emplace_back(a,b);
        }

        vvec(ll) g(N);
        rep(_,N-1){
            ll u,v;
            cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vec(ll) ans(N);

        RollbackUnionFind ruf(N);

        auto dfs =  [&](auto f, ll now, ll frm, ll memo) -> void{
            auto [a,b] = ab[now];

            memo -= min(ruf.getgsize(a), ruf.getedgesize(a) );
            if(!ruf.same(a,b)) memo -= min(ruf.getgsize(b), ruf.getedgesize(b) );

            ruf.unite(a,b);

            memo += min(ruf.getgsize(a), ruf.getedgesize(a) );

            ans[now]=memo;
            for(ll nxt:g[now]){
                if(nxt==frm) continue;
                f(f, nxt, now, memo);
            }
            ruf.rollback();
        };
        dfs(dfs,0,0,0);

        rep1(i,N-1) cout << ans[i] << " "; cout << endl;


    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
