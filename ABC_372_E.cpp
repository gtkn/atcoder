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

struct UnionFind{
    // グループのサイズ、要素の親idx、要素から親までのランクの配列
    vector<int> gsize,parent,rank;
    vector<vector<int>> member;

    //コンストラクタ　各配列を初期化
    UnionFind(int N){
        gsize = vector<int>(N,1);
        parent = vector<int>(N,-1);
        rank = vector<int>(N);
        member = vector<vector<int>>(N);
        rep(i,N) member[i].push_back(i);
    }

    //親を求める
    int findparent(int x){
        if(parent[x]<0) return x;
        else return parent[x] = findparent(parent[x]); //rankが小さくなるよう親を再設定
    }

    // 2要素x,yの属するグループを合併
    bool unite(int x, int y){
        x = findparent(x);
        y = findparent(y);
        if(x==y) return false;
        
        if(rank[x] < rank[y]) swap(x,y);
        parent[y] = x;
        gsize[x] += gsize[y];
        gsize[y] = 0;

        member[x].insert(member[x].end(),member[y].begin(),member[y].end());
        sort(member[x].begin(),member[x].end(), greater<int>());
        if (member[x].size() > 20) {
            member[x].resize(20);
        }
        
        member[y].clear();


        // vector<int> tmp;
        // ll i=0,j=0;
        // ll nx = member[x].size(), ny = member[y].size();
        // while(i<nx && j<ny){
        //     if(member[x][i]>member[y][j]){
        //         tmp.push_back(member[x][i]);
        //         i++;
        //     }else{
        //         tmp.push_back(member[y][j]);
        //         j++;
        //     }
        // }
        // while(i<nx){
        //     tmp.push_back(member[x][i]);
        //     i++;
        // }
        // while(j<ny){
        //     tmp.push_back(member[y][j]);
        //     j++;
        // }
        // member[x] = tmp;


        if(rank[x]==rank[y]) rank[x]++;
        return true;
    }

    // 2要素x,yが同じ集合に属するかどうか
    bool same(int x, int y){
        return findparent(x) == findparent(y);
    }

    // 要素xが属するグループのサイズ
    int size(int x){
        return gsize[findparent(x)];
    }

    // 要素xが属するグループのメンバーのk番目  
    int memberindex(int x, int k){
        auto &m = member[findparent(x)];
        // cerr << x << ", " << k << ", " << m.size() << " : ";
        // for(auto mi: m) cerr << mi << " "; cerr << endl;

        if(m.size()<=k) return -2;
        return m[k];
    }




};


void solve(){
    ll N, Q;
    cin >> N >> Q;
    UnionFind uf(N);

    while(Q--){
        ll t;
        cin >> t;
        if(t==1){
            ll u,v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u,v);
        }else{
            ll v,k;
            cin >> v >> k;
            v--; k--;
            cout << uf.memberindex(v,k)+1 << endl;
        }
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
