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


// struct UnionFind{
//     // グループのサイズ、要素の親idx、要素から親までのランクの配列
//     vector<int> gsize,parent,rank;
//     vector<vector<int>> member;

//     //コンストラクタ　各配列を初期化
//     UnionFind(int N){
//         gsize = vector<int>(N,1);
//         parent = vector<int>(N,-1);
//         rank = vector<int>(N);
//         member = vector<vector<int>>(N);
//         // rep(i,N) member[i].push_back(i);
//     }

//     //親を求める
//     int findparent(int x){
//         if(parent[x]<0) return x;
//         else return parent[x] = findparent(parent[x]); //rankが小さくなるよう親を再設定
//     }

//     // 2要素x,yの属するグループを合併
//     bool unite(int x, int y){
//         x = findparent(x);
//         y = findparent(y);
//         if(x==y) return false;
        
//         if(rank[x] < rank[y]) swap(x,y);
//         parent[y] = x;
//         gsize[x] += gsize[y];
//         gsize[y] = 0;


//         if(member[x].size() < member[y].size()) swap(member[x],member[y]);
//         member[x].insert(member[x].end(),member[y].begin(),member[y].end());        
//         member[y].clear();

//         if(rank[x]==rank[y]) rank[x]++;
//         return true;
//     }

//     // 2要素x,yが同じ集合に属するかどうか
//     bool same(int x, int y){
//         return findparent(x) == findparent(y);
//     }

//     // 要素xが属するグループのサイズ
//     int size(int x){
//         return gsize[findparent(x)];
//     }

//     // 要素xが属するグループのメンバーのk番目  
//     int memberindex(int x, int k){
//         auto &m = member[findparent(x)];
//         // cerr << x << ", " << k << ", " << m.size() << " : ";
//         // for(auto mi: m) cerr << mi << " "; cerr << endl;

//         if(m.size()<=k) return -2;
//         return m[k];
//     }
// };



void solve(){
    ll H,W;
    cin >> H >> W;

    vvec(ll) F(H,vec(ll)(W));
    rep(i,H) rep(j,W) cin >> F[i][j];

    ll Q;
    cin >> Q;

    vec(ll) A(Q),B(Q),Y(Q),C(Q),D(Q),Z(Q);
    rep(i,Q) cin >> A[i] >> B[i] >> Y[i] >> C[i] >> D[i] >> Z[i];
    rep(i,Q) A[i]--;
    rep(i,Q) B[i]--;    
    rep(i,Q) C[i]--;    
    rep(i,Q) D[i]--;    
    vec(ll) ab(Q),cd(Q);
    rep(i,Q) ab[i] = A[i]*W+B[i];
    rep(i,Q) cd[i] = C[i]*W+D[i];


    ll hw = H*W;
    dsu uf(hw);
    vvec(ll) ids(hw);
    rep(i,Q) ids[A[i]*W+B[i]].push_back(i);
    rep(i,Q) ids[C[i]*W+D[i]].push_back(i);


    ll M = 1000010;

    vvec(Pll) mg(M);
    rep(i,H)rep(j,W-1){
        mg[ min(F[i][j],F[i][j+1]) ].emplace_back(i*W+j,i*W+j+1);
    }
    rep(i,H-1)rep(j,W){
        mg[ min(F[i][j],F[i+1][j]) ].emplace_back(i*W+j,(i+1)*W+j);
    }



    vec(ll) L(Q),R(Q);
    rep(i,Q) L[i] = 0, R[i] = M;

    while(true){
        vec(ll) mid(Q);
        rep(i,Q) mid[i] = (L[i]+R[i])/2;
        vvec(ll) chk(M);
        rep(i,Q) chk[mid[i]].push_back(i);

        dsu uf(hw);

        repr(k,M){
            for(auto [i,j]:mg[k]){
                uf.merge(i,j);
            }
            for(auto i:chk[k]){
                // cerr << i << " " << ab[i] << " " << cd[i] << " " << uf.same(ab[i],cd[i]) << endl;
                if(uf.same(ab[i],cd[i])){
                    L[i] = mid[i];
                }else{
                    R[i] = mid[i];
                }
            }
        }

        bool isok = true;
        rep(i,Q) if(L[i]+1<R[i]) isok = false;
        if(isok) break;
    }

    // rep(i,Q) cerr << L[i] << " " << R[i] << endl;

    vec(ll) ans(Q);
    rep(i,Q) ans[i] = Y[i]+Z[i] - 2*min(L[i],min(Y[i],Z[i]));


    rep(i,Q) cout << ans[i] << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
