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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


struct Path {
    mint a, b;
    Path(mint a=1, mint b=0):a(a),b(b) {}
};
using Point = mint;
Path op_comp(Path p, Path c) { return {p.a * c.a, p.a * c.b + p.b}; };
Path op_addV(Point d, Point a) { return {d, a}; };
Point op_rake(Point l, Point r) { return l * r; };
Point op_addE(Path d) { return d.b; };



// g : 親から子への有向グラフ
struct StaticTopTree {
    ll n;
    vector<vector<ll>> g;
    vector<ll> vertexToNode;
    vector<Point> points;
    vector<Path> paths;

    enum Type : char{Comp, AddV, Rake, AddE, None};
    string typeToString(const Type& type) {
        switch(type) {
            case Type::Comp:
                return "Comp";
            case Type::AddV:
                return "AddV";
            case Type::Rake:
                return "Rake";
            case Type::AddE:
                return "AddE";
            default:
                return "None";
        }
    }

    struct Node {
        Type type;
        ll idx,l,r,par=-1;
        mint val=0;
        Node(){}
        Node(Type type, ll idx=-1, ll l=-1, ll r=-1):type(type),idx(idx),l(l),r(r){}
    };
    vector<Node> nodes;

    StaticTopTree(ll _n, vector<vector<ll>> _g, ll _root=0):n(_n),g(_g){
        vertexToNode.resize(n);
        dfs(_root);
        compress(_root);
        paths.resize(nodes.size());
        points.resize(nodes.size());
    }


    ll dfs(ll now){
        ll sz = 1, largest = 0;
        for(ll &nxt:g[now]){
            ll d = dfs(nxt);
            sz += d;
            if(chmax(largest,d)) swap(nxt,g[now][0]);
        }
        return sz;
    }

    Pll compress(ll now) {
        vector<Pll> cs { addVertex(now) };
        while(!g[now].empty()){
            now = g[now][0];
            cs.emplace_back( addVertex(now));
        }
        return merge(Type::Comp, cs);
    }

    Pll addVertex(ll now) {
        auto [i,s] = rake(now);
        vertexToNode[now] = addNode(Type::AddV,i); // addNode(Type::AddV,i,now);
        return {vertexToNode[now] , s+1};
    }

    Pll rake(ll now) {
        vector<Pll> cs;
        for(ll i=1; i<g[now].size(); i++){
            cs.emplace_back( addEdge(g[now][i]) );
        }
        if(cs.empty()) return {-1,0};
        return merge(Type::Rake, cs);
    }

    Pll addEdge(ll now) {
        auto [i,s] = compress(now);
        return {addNode(Type::AddE,i),s};
    }

    ll addNode(Type type, ll l, ll r=-1){
        ll idx = nodes.size();
        nodes.emplace_back(type,idx,l,r);
        if(l!=-1) nodes[l].par = idx;
        if(r!=-1) nodes[r].par = idx;
        return idx;
    }

    Pll merge(Type type, const vector<Pll>& cs){
        if(cs.size()==1) return cs[0];
        ll sz = 0;
        for(Pll ci:cs) sz += ci.second;
        
        // 真ん中付近を探して分割
        rep(i,cs.size()){
            if(sz < cs[i].second){
                auto [l,sz_l] = merge(type, vector<Pll>(cs.begin(), cs.begin()+i));
                auto [r,sz_r] = merge(type, vector<Pll>(cs.begin()+i, cs.end()));
                return {addNode(type,l,r), sz_l+sz_r};
            }
            sz -= cs[i].second*2;
        }
        assert(false);
    }

    void varInit(const vector<ll>& A){
        assert(A.size()==n);
        rep(i,n){
            nodes[vertexToNode[i]].val = A[i];
        }
        rep(i,nodes.size()) update(i);
    }

    ll update(ll idx){
        const Node& node = nodes[idx];
        if(node.type == Type::Comp){
            paths[idx] = op_comp(paths[node.l], paths[node.r]);
        }
        if(node.type == Type::AddV){
            if(node.l==-1) paths[idx] = Path(mint(1), node.val);
            else paths[idx] = op_addV(points[node.l], node.val);
        }
        if(node.type == Type::Rake){
            points[idx] = op_rake(points[node.l], points[node.r]);
        }
        if(node.type == Type::AddE){
            points[idx] = op_addE(paths[node.l]);
        }
        return node.par;
    }

    Point change(ll v,mint val){
        ll now = vertexToNode[v];
        nodes[now].val = val;
        assert(nodes[now].type == Type::AddV);
        while(now!=-1){
            now = update(now);
        }
        return paths.back().b;
    }

};





void solve(){
    ll N,Q;
    cin >> N >> Q;
    vvec(ll) g(N);
    rep1(i,N-1){
        ll p;
        cin >> p;
        g[p-1].push_back(i);
    }

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    StaticTopTree stt(N,g);
    stt.varInit(A);
    
    while(Q--){
        ll v,x;
        cin >> v >> x;
        v--;
        mint res = stt.change(v,x);
        cout << res.val() << endl;
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
