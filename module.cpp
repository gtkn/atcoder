#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep1(i,n) for (ll i = 1; i <= (n); ++i)
#define repr(i,n) for (ll i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (ll i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk　bit目
#define vec(T) vector<T>
#define vvec(T) vec(vec(T))
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

using mint = modint998244353;

using bs = bitset<8>;

//==================================================================================




// https://atcoder.jp/contests/abc342/submissions/50663624
// 消せる priority_queue
struct erasable_priority_queue{

    // pair<priority_queue<ll>, priority_queue<ll>> pq;
    priority_queue<ll> q0,q1;
    ll zero = 0; // pqが空のときに返す値

    erasable_priority_queue(){
        this->q0.push(0);
        this->q1.push(0);
    }

    // x を追加する関数
    void add(ll x){
        this->q0.push(x);
    }

    // x を削除する関数
    void erase(ll x){
        this->q1.push(x);
    }

    // pq に含まれる値の max (空なら 0 ) を返す関数
    ll top(){
        while (!(this->q0.empty()) && !(this->q1.empty()) && this->q0.top() == this->q1.top()) {
            this->q0.pop();
            this->q1.pop();
        }
        if(this->q0.empty()) return this->zero;
        return this->q0.top();
    }
};




class Lseg {
private:
    ll n;              // 元の配列の要素数
    vector<erasable_priority_queue> tree;   // セグメント木のノードを格納する配列
public:
    // コンストラクタ
    Lseg(ll n) {
        this->n = n;
        tree.resize(4 * n);  // ノード数は元の配列の要素数の4倍に設定（十分なサイズを確保）
    }

    ll get(ll idx){
        return get(1,0,n,idx);
    }

    ll get(ll node, ll start, ll end, ll idx) {
        // cout << node << " : " << start <<" , " << end << ", " << idx<< endl;
        if(node<0) return 0;
        ll res = 0;

        if (idx < start || end <= idx) {
            return 0;
        }

        chmax(res, tree[node].top());
        if(start+1==end) return res;


        ll mid = (start + end) / 2;
        ll leftRes = get(node * 2, start, mid, idx);
        ll rightRes = get(node * 2 + 1, mid, end, idx);

        chmax(res, leftRes);
        chmax(res, rightRes);

        return res;
    }



    void apply(ll left, ll right, ll x){
        return apply(1, 0, n, left, right, x);
    }

    void apply(ll node, ll start, ll end, ll left, ll right, ll x) {
        // cout << node << ".. " << start <<" , " << end << ": " << left << " , " << right << endl;
        if (right <= start || end <= left) {
            return;
        }
        if (left <= start && end <= right) {
            if(x>0) tree[node].add(x);
            if(x<0) tree[node].erase(-x);
            return;
        }
        ll mid = (start + end) / 2;
        apply(node * 2, start, mid, left, right, x);
        apply(node * 2 + 1, mid, end, left, right, x);
        return;
    }


};




// https://atcoder.jp/contests/abc339/submissions/50539226
struct MergeSortTree{
    ll n;
    vec(ll) v; // 元のvector
    vvec(ll) vv;
    vvec(ll) cum;
    ll m;

    MergeSortTree(vec(ll) v){
        this->n = v.size(); // サイズは2冪にしておく
        this->v = v;
        this->m = 4*this->n;

        this->vv.resize(this->m);
        this->cum.resize(this->m);
        build(1,0,this->n);
    }


    void build(ll node, ll start, ll end){
        vec(ll) &v = this->vv[node];
        vec(ll) &c = this->cum[node];
        if(start+1==end){
            v = {this->v[start]};
            c = {0, this->v[start]};
            return;
        }

        ll mid = (start+end)/2;
        build(node*2, start, mid);
        build(node*2 + 1, mid, end);

        v.insert(v.end(), all(this->vv[node*2]));
        v.insert(v.end(), all(this->vv[node*2+1]));
        sort(all(v));

        ll nn = v.size();
        c.resize(nn+1);
        rep(i,nn) c[i+1] = c[i] + v[i];
    }


    // 区間の和を取得
    ll query(ll left, ll right, ll x) {
        return query(1, 0, this->n, left, right, x);
    }

    // 再帰的に区間の和を取得
    ll query(ll node, ll start, ll end, ll left, ll right, ll x) {
        if (right <= start || end <= left) {
            // クエリ範囲とノード範囲が交差しない場合は0を返す（影響なし）
            return 0;
        }
        if (left <= start && end <= right) {
            vec(ll) &v = this->vv[node];
            ll d = upper_bound(all(v), x) - v.begin();
            return this->cum[node][d];
        }
        // それ以外の場合は左右の子ノードの値を再帰的に合算
        ll mid = (start + end) / 2;
        ll leftSum = query(node * 2, start, mid, left, right, x);
        ll rightSum = query(node * 2 + 1, mid, end, left, right, x);
        return leftSum + rightSum;
    }




};




// // https://atcoder.jp/contests/abc331/submissions/48162113
// // 複数個のModでやるローリングハッシュ
// mt19937_64 rng(time(0));
// constexpr ll BN = 5;
// ll mods[BN] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
// ll base[BN];

// struct Hash{
//     ll h1,h2,pw;
// };
// using S = array<Hash, BN>;

// S op(S lhs,S rhs){
//     S res;
//     rep(i,BN){
//         res[i].h1 = ( lhs[i].h1 * rhs[i].pw  + rhs[i].h1 )%mods[i];
//         res[i].h2 = ( rhs[i].h2 * lhs[i].pw  + lhs[i].h2 )%mods[i];
//         res[i].pw = ( lhs[i].pw * rhs[i].pw )%mods[i];
//     }
//     return res;
// }
// S ee(){
//     S res;
//     rep(i,BN) res[i] = {0,0,1};
//     return res;
// }
// S gen(char c){
//     S res;
//     rep(i,BN){
//         res[i].h1 = res[i].h2 = c; // そのままでOK
//         res[i].pw = base[i];
//     }
//     return res;
// }




// iで立っているビットの中でjを探索するやつ
// https://qiita.com/Euglenese/items/260f9ddf513f772d7e42
// for(int j = i; j > 0; j = (j - 1) & i){
//     ans += A[j];
// }
// ans += A[0];




// 2乗の和とか
    // auto sum0 = [](ll n)->mint{ // sigma(i^0)_i=1~n
    //     return n;
    // };
    // auto sum1 = [](ll n)->mint{ // sigma(i^1)_i=1~n
    //     mint res = n;
    //     res *= (n+1);
    //     res /= 2;
    //     return res;
    // };
    // auto sum2 = [](ll n)->mint{ // sigma(i^2)_i=1~n // https://math.nakaken88.com/textbook/basic-sum-of-square-numbers/
    //     mint res = n;
    //     res*=(n+1);
    //     res*=(2*n+1);
    //     res/=6;
    //     return res;
    // };
    // auto sum3 = [](ll n)->mint{ // sigma(i^3)_i=1~n // https://math.nakaken88.com/textbook/basic-sum-of-cube-numbers/
    //     mint res = n;
    //     res *= (n+1);
    //     res /= 2;
    //     return res*res;
    // };


// 拡張 Euclid の互除法
// ap + bq = gcd(a, b) となる (p, q) を求め、d = gcd(a, b) をリターン
// p,qを参照渡しする版
ll extGcd(ll a,ll b, ll &p, ll &q){
    if(b==0){
        p=1; q=0;
        return a;
    }

    ll d = extGcd(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

// 中国剰余定理, CRS
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
// https://qiita.com/drken/items/ae02240cd1f8edfc86fd#%E4%BA%8C%E5%85%83%E3%81%AE%E5%A0%B4%E5%90%88
Pll ChineseRem(ll b1, ll m1, ll b2, ll m2) {
  ll p, q;
  ll d = extGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return make_pair(0, -1);

  ll m = m1 * (m2/d); // lcm of (m1, m2)
  ll tmp = (b2 - b1) / d * p % (m2/d);
  ll r = mod(b1 + m1 * tmp, m);
  return make_pair(r, m);
}





// bitが1の数
// __builtin_popcount(10)


// 木の直径を求める
ll calcTreeDiameter(const vvec(ll)& g){
    ll n = g.size();


    ll st = 0, gl=0;
    vec(ll) dist(n,llINF);
    rep(_,2){
        swap(st,gl);

        // stから一番遠いところをglにする
        rep(i,n) dist[i]=llINF;
        dist[st]=0;
        queue<ll> q;
        q.push(st);
        dist[st]=0;
        while(!q.empty()){
            ll now = q.front();
            q.pop();
            for(ll nxt:g[now]) if(chmin(dist[nxt], dist[now]+1)) q.push(nxt);
        }
        ll dmax = 0;
        rep(i,n) if(chmax(dmax,dist[i])) gl = i;
    }

    return dist[gl];
}



// 掃き出し法?
// 一般的な型に対応するためのテンプレート
template <typename T>
struct Matrix {
    vector<vector<T>> data;

    Matrix(int rows, int cols) : data(rows, vector<T>(cols)) {}

    int rows() const { return data.size(); }
    int cols() const { return data[0].size(); }
};

template <typename T>
struct Vector {
    vector<T> data;

    Vector(int size) : data(size) {}

    int size() const { return data.size(); }
};

// 行列の表示
template <typename T>
void printMatrix(const Matrix<T>& mat) {
    int rows = mat.rows();
    int cols = mat.cols();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << mat.data[i][j] << "\t";
        }
        cout << endl;
    }
}

// 連立方程式の解を計算する関数（テンプレート化）
template <typename T>
Vector<T> solveLinearEquations(const Matrix<T>& A, const Vector<T>& b) {
    int N = A.rows();
    Matrix<T> augmentedMatrix(N, N + 1);

    // 係数行列と右辺ベクトルを合併
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            augmentedMatrix.data[i][j] = A.data[i][j];
        }
        augmentedMatrix.data[i][N] = b.data[i];
    }

    // ガウシアン消去法
    for (int i = 0; i < N; ++i) {
        // ピボット選択
        int pivotRow = i;
        for (int j = i + 1; j < N; ++j) {
            if (abs(augmentedMatrix.data[j][i]) > abs(augmentedMatrix.data[pivotRow][i])) {
                pivotRow = j;
            }
        }
        swap(augmentedMatrix.data[i], augmentedMatrix.data[pivotRow]);

        // ピボット要素を1にする
        T pivot = augmentedMatrix.data[i][i];
        for (int j = i; j <= N; ++j) {
            augmentedMatrix.data[i][j] /= pivot;
        }

        // 他の行から現在の行を引く
        for (int k = 0; k < N; ++k) {
            if (k != i) {
                T factor = augmentedMatrix.data[k][i];
                for (int j = i; j <= N; ++j) {
                    augmentedMatrix.data[k][j] -= factor * augmentedMatrix.data[i][j];
                }
            }
        }
    }

    // 解を取得
    Vector<T> solution(N);
    for (int i = 0; i < N; ++i) {
        solution.data[i] = augmentedMatrix.data[i][N];
    }

    return solution;
}






// 木の数、プリューファーコード
// https://atcoder.jp/contests/abc303/tasks/abc303_h

// 箱根DP
// https://atcoder.jp/contests/abc134/submissions/46187082


// 形式的冪級数的なやつ
// https://atcoder.jp/contests/abc321/submissions/46137975
struct FPS{
    ll K;
    vec(mint) coeffs;

    FPS(vec(mint) v):coeffs(v){
        K = v.size();
    }

    void add(const vec(mint)& v){
        rep(i,v.size()) coeffs[i] += v[i];
    }

    void add(ll idx, mint d){
        assert(idx>=0 && idx<K);
        coeffs[idx]+=d;
    }


    void mul(const vec(mint)& v){
        coeffs = convolution(coeffs, v);
        coeffs.resize(K);
    };

    void mul(ll d){ // これは内容による
        for(ll i=K; i>=d; i--){
            coeffs[i] += coeffs[i-d];
        }
    };

    void div(ll d){ // これは内容による
        for(ll i=d; i<=K; i++){
            coeffs[i] -= coeffs[i-d];
        }
    }

    void show(ll th){
        rep(i,th) cout << i<< ":" << coeffs[i].val() <<", "; cout << endl;
    }


};





// 演算子のオーバーロード
// bool operator<(const FarmState &a, const FarmState &b){
//     return a.evaluated_score < b.evaluated_score;
// }


namespace zobrist_hash
{
    mt19937 mt_init_hash(0);

    uint64_t v[H*W][T+1] = {};
    void init()
    {
        rep(n,H*W)
        {
            rep(t,T+1)
            {
                v[n][t] = mt_init_hash();
            }
        }
    }

}



    // if(--N==0) cout <<"ok" << endl; // N==1のときok




// maxflow, 最大フロー, 最大流
// https://atcoder.jp/contests/arc085/submissions/44933658
struct MaxFlow{

    struct edge{
        ll to,cap,rev;
        edge(ll to=0, ll cap=0,ll rev=0):to(to),cap(cap),rev(rev){}
    };


    struct edge_status{
        ll from,to,cap,flow;
        edge_status(ll from, ll to=0, ll cap=0,ll flow=0):from(from),to(to),cap(cap),flow(flow){}
    };


    ll n,m;
    vvec(edge) g;
    vec(bool) used;
    vec(edge_status) status;
    
    vec(ll) level, iter;

    MaxFlow(ll n=0):n(n){
        assert(n>0);
        g.resize(n);
        m=0;
        used.resize(n);
        level.resize(n);
        iter.resize(n);
    }


    void add_edge(ll u, ll v, ll cap){
        g[u].emplace_back( v, cap, g[v].size() );
        g[v].emplace_back( u, 0, g[u].size()-1 );
        status.emplace_back(u,v,cap,g[u].size()-1);
        m++;
    }

    ll dfs(ll now,ll gl, ll f){
        if(now==gl) return f;
        used[now]=true;

        for(edge &e:g[now]){
            if(used[e.to] || e.cap==0) continue;
            ll d = dfs(e.to, gl, min(f, e.cap));
            if(d>0){
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }


    ll flow(ll st,ll gl){
        ll res = 0, pre=-1;
        while(res!=pre){
            rep(i,n) used[i]=false;
            pre = res;
            res += dfs(st,gl,llINF);
        }
        return res;
    }


    void bfs(ll st){
        rep(i,n) level[i]=-1;
        queue<ll> q;
        level[st]=0;
        q.push(st);
        while(!q.empty()){
            ll now = q.front(); q.pop();
            for(edge &e:g[now]){
                if(e.cap==0 || level[e.to]>=0) continue;
                level[e.to] = level[now]+1;
                q.push(e.to);
            }
        }
    }

    ll dfs2(ll now,ll gl, ll f){
        if(now==gl) return f;

        for(ll &i = iter[now]; i<g[now].size(); i++){
            edge &e = g[now][i];
            if(e.cap==0 || level[now] >= level[e.to]) continue;
            ll d = dfs2(e.to, gl, min(f, e.cap));
            if(d>0){
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }


    ll flow_dinic(ll st,ll gl){
        ll res = 0, pre=-1;
        while(res!=pre){
            bfs(st);
            if(level[gl]<0) break;
            rep(i,n) iter[i]=0;
            pre = res;
            ll d;
            while( (d=dfs2(st,gl,llINF)) ) res += d;
        }
        return res;
    }



    vec(edge_status) edges(){
        vec(edge_status) res = status;
        for(edge_status &e:res){
            e.flow = e.cap - g[e.from][e.flow].cap;
        }
        return res;
    }


};



// https://atcoder.jp/contests/abc315/editorial/6994
long long llceil(long long a,long long b){
  if(a%b==0){return a/b;}
 
  if(a>=0){return (a/b)+1;}
  else{return -((-a)/b);}
}
long long llfloor(long long a,long long b){
  if(a%b==0){return a/b;}
 
  if(a>=0){return (a/b);}
  else{return -((-a)/b)-1;}
}



// 座標圧縮の構造体
// まだ試してない
template <typename T>
struct CoordinateCompressor {
    set<ll> values;

    CoordinateCompressor():{}

    CoordinateCompressor(set<T> v):values(v){}

    CoordinateCompressor(vector<T> v):{
        for(auto vi:v) values.insert(vi);
    }
    
    void add(T x){
        values.insert(x);
    }

    ll get(T x){
        if(!values.count(x)) return -1;
        return distance(values.begin(),values.lower_bound(x));
    }

    ll getSize(){
        return values.size();
    }

    vector<T> uncompress(){
        vector<T> res;
        for(auto vi:values) res.push_back(vi);
        return res;
    }
    
};





map<ll,ll> compressCoordinates(vec(ll) &v){
    // 値の集合vを受け取って座標圧縮する
    // res[val] = idx
    // v[idx] = val となるように入力のvも変更する

    sort(all(v));
    v.erase(unique(all(v)),v.end());

    ll nn = v.size();
    map<ll,ll> res;
    rep(i,nn) res[ v[i] ] = i;

    return res;
}


vec(Pll) rangeMerge(vec(Pll) v){
    // 半開区間[l,r)の集合vを受け取ってマージする
    vec(Pll) res;
    if(v.empty()) return res;

    sort(all(v));
    res.push_back(v[0]);
    for(Pll vi:v){
        if(res.back().first <= vi.first && vi.first < res.back().second){
            chmax(res.back().second, vi.second);
        }else{
            res.push_back(vi);
        }
    }
    return res;
}


vec(Pll) rangeMerge_cl(vec(Pll) v){
    // 閉区間[l,r]の集合vを受け取ってマージする
    vec(Pll) res;
    if(v.empty()) return res;

    sort(all(v));
    res.push_back(v[0]);
    for(Pll vi:v){
        if(res.back().first <= vi.first && vi.first <= res.back().second){
            chmax(res.back().second, vi.second);
        }else{
            res.push_back(vi);
        }
    }

    return res;
}




void doubling(vvec(ll) &db, ll xx){
    // 0列目まで埋めたダブリングの配列の残りを計算する
    // 遷移先がない場合はxx
    ll n,m;
    n = db.size();
    m = db[0].size();

    rep(j,m-1)rep(i,n){
        if(db[i][j]==xx){
            db[i][j+1] = xx;
        }else{
            db[i][j+1] = db[ db[i][j] ][j];
        }
    }
}





// // modがテストケースで変わるとき
// using mint = modint;
// mint::set_mod(P);



// ローリングハッシュ
// 文字列を数値列と見て、区間を "b進数MOD M" で表す
// あり本332


// uniqueで重複削除する時
    // sort(all(mr));
    // mr.erase(unique(all(mr)),mr.end());

    // ll nn = mr.size();
    // map<ll,ll> mf;
    // rep(i,nn) mf[ mr[i] ] = i;



// カルテシアン木
// https://atcoder.jp/contests/abc311/submissions/43899946
// https://nyaannyaan.github.io/library/tree/cartesian-tree.hpp.html
// return value : pair<graph, root>
template <typename T>
pair<vector<vector<ll>>, ll> CartesianTree(vector<T> &a) {
  ll N = (ll)a.size();
  vector<vector<ll>> g(N);
  vector<ll> p(N, -1), st;
  st.reserve(N);
  for (int i = 0; i < N; i++) {
    int prv = -1;
    while (!st.empty() && a[i] < a[st.back()]) {
      prv = st.back();
      st.pop_back();
    }
    if (prv != -1) p[prv] = i;
    if (!st.empty()) p[i] = st.back();
    st.push_back(i);
  }
  int root = -1;
  for (int i = 0; i < N; i++) {
    if (p[i] != -1)
      g[p[i]].push_back(i);
    else
      root = i;
  }
  return make_pair(g, root);
}


// 構造体のテンプレート
struct ExampleStruct {
    // 整数
    int integer_value;

    // 浮動小数点数
    double double_value;

    // 文字列
    string string_value;

    // ベクター（整数のリスト）
    vector<int> integer_list;

    // コンストラクタ
    ExampleStruct(int i, double d, const string& s, const vector<int>& vec) 
        : integer_value(i), double_value(d), string_value(s), integer_list(vec) {}

    // デフォルトコンストラクタ（初期値を指定する）
    ExampleStruct() 
        : integer_value(0), double_value(0.0), string_value(""), integer_list({}) {}

    // メソッド（関数）
    void printValues() {
        cout << "Integer: " << integer_value << endl;
        cout << "Double: " << double_value << endl;
        cout << "String: " << string_value << endl;
        cout << "Integer List: ";
        for (int num : integer_list) {
            cout << num << " ";
        }
        cout << endl;
    }
};


// 整数列をビットの行列とみなして掃き出し法
// https://atcoder.jp/contests/abc141/submissions/43295919
    void bit_hakidasi(vec(ll) &A){
        ll rnk = 0;
        ll N = A.size();
        repr(k,60){
            ll tmp = -1;
            for(ll i=rnk; i<N; i++){
                if(bit(A[i],k)){
                    tmp = A[i];
                    break;
                }
            }
            if(tmp==-1) continue;

            if(A[rnk]!=tmp) A[rnk]^=tmp;
            for(ll i=rnk+1; i<N; i++) chmin(A[i],A[i]^A[rnk]);
            rnk++;
        }

    }



// セグメント木クラス
class SegmentTree {
private:
    int n;              // 元の配列の要素数
    vector<int> tree;   // セグメント木のノードを格納する配列

public:
    // コンストラクタ
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);  // ノード数は元の配列の要素数の4倍に設定（十分なサイズを確保）
        build(nums, 1, 0, n);  // セグメント木の構築
    }

    // セグメント木の構築
    void build(const vector<int>& nums, int node, int start, int end) {
        if (start + 1 == end) {
            // 葉ノードの場合
            tree[node] = nums[start];
        } else {
            // 内部ノードの場合
            int mid = (start + end) / 2;
            build(nums, node * 2, start, mid);         // 左の子ノードを構築
            build(nums, node * 2 + 1, mid, end);       // 右の子ノードを構築
            tree[node] = tree[node * 2] + tree[node * 2 + 1];   // 子ノードの値を合算
        }
    }

    // 区間の和を取得
    int query(int left, int right) {
        return query(1, 0, n, left, right);
    }

    // 再帰的に区間の和を取得
    int query(int node, int start, int end, int left, int right) {
        if (right <= start || end <= left) {
            // クエリ範囲とノード範囲が交差しない場合は0を返す（影響なし）
            return 0;
        }
        if (left <= start && end <= right) {
            // ノード範囲がクエリ範囲に完全に含まれる場合はノードの値を返す
            return tree[node];
        }
        // それ以外の場合は左右の子ノードの値を再帰的に合算
        int mid = (start + end) / 2;
        int leftSum = query(node * 2, start, mid, left, right);
        int rightSum = query(node * 2 + 1, mid, end, left, right);
        return leftSum + rightSum;
    }
};


// Trie木
// https://atcoder.jp/contests/abc268/submissions/34763568
// https://atcoder.jp/contests/abc268/submissions/42098901
    struct TrieTree{
        vector<map<char,ll>> g;
        vector<ll> cnt;

        TrieTree(): g(1),cnt(1){}

        ll add(const string& s){
            ll now = 0;
            for(char c:s){
                if(!g[now].count(c)){
                    g[now][c] = g.size();
                    g.push_back({});
                    cnt.push_back(0);
                }
                now = g[now][c];
            }
            cnt[now]++;
            return now;
        }



        vector<ll> A,B; // 先祖の数、子孫の数、どちらも自分を含む

        ll dfs(ll now, ll num){
            num += cnt[now];
            A[now] = num;

            for(auto mi:g[now]){
                B[now] += dfs(mi.second, num);
            }

            return B[now]+cnt[now];
        }

        // addした後にこれで初期化
        void calc_AB(){
            A = vector<ll>(g.size());
            B = vector<ll>(g.size());
            dfs(0, 0);
        }

    };



// https://atcoder.jp/contests/agc047/submissions/47601347
// 機能は問題に応じて追加するべし
struct TrieTree{
    vvec(ll) g; // 子への辺
    vector<ll> cnt; // そのノードに該当する文字列が追加された数
    ll al = 26; // アルファベットの数
    ll maxsize; // ノード数の最大
    ll gcnt = 1; // すでに使ったノードの数

    TrieTree(ll maxsize):maxsize(maxsize){
        g = vvec(ll)(maxsize,vec(ll)(al));
        cnt = vec(ll)(maxsize);
    }

    vec(ll) add(const string& s){
        vec(ll) path;
        ll now = 0;
        for(char c:s){
            ll x = c-'a';
            path.push_back(now);
            if(g[now][x]==0) g[now][x] = gcnt++;
            now = g[now][x];
        }
        cnt[now]++;
        return path;
    }


};




// 重心分解
// https://atcoder.jp/contests/abc291/submissions/41669040
auto getCent = [&](auto getCent, ll sz, ll now, ll frm) ->Pll{
    ll tmax = sz-t[now];
    Pll res = {sz,-1}; // nowの部分木の中で、隣接する部分木のサイズの最大値が一番小さい時の、サイズとその頂点
    for(ll nxt:g[now]){
        if(nxt==frm) continue;
        if(used[nxt]) continue;
        chmin(res, getCent(getCent, sz, nxt, now));
        chmax(tmax, t[nxt]);
    }
    chmin(res, Pll(tmax,now));
    return res;
};


// ロールバック付きUnionFind
// https://atcoder.jp/contests/abc302/tasks/abc302_h
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



// noshi基底 xorの吐き出し https://twitter.com/noshi91/status/1200702280128856064
// vec(ll) A;
// set<ll> s;
// for(ll ai:A){
//     for(ll si:s){
//         chmin(ai, ai^si);
//     }
//     if(ai>0) s.insert(ai);
// }


// 区間をvec(Pll)で持ってその区間の幅の和を取るやつ
// sort(all(v));
// ll st=-llINF,gl=-llINF;
// v.emplace_back(llINF,llINF);
// for(Pll w:v){
//     ans += gl-st;
//     st = max(w.first,gl);
//     gl = max(st,w.second);
// }


// ll min
ll llmin = numeric_limits<ll>::min();



// 順列列挙
// vector<int> v = {1,2,3}; //全部を列挙するときは、はじめ昇順ソートしておく
// do{
//   //何かしら
// }while(next_permutation(v.begin(),v.end()));//vは次の順列になる




// 平面走査 -> ABC_296_G


// トポロジカルソート
    vec(ll) topological_sort(vvec(ll) &g, vec(ll) &incnt, ll vnum){
        vec(ll) res;

        queue<ll> q;
        rep(i,vnum) if(incnt[i]==0) q.push(i);

        while(!q.empty()){
            ll now = q.front();
            q.pop();

            for(ll nxt:g[now]){
                incnt[nxt]--;
                if(incnt[nxt]==0) q.push(nxt);
            }

            res.push_back(now);
        }

        return res;

    }


// アリストテレスのふるいで素数を列挙
    vec(ll) eratosthenes(ll n){
        vec(bool) isok(n+1,true);
        isok[0]=false; isok[1]=false;
        rep1(i,n){
            if(!isok[i]) continue;
            ll a=i*2;
            while(a<=n){
                isok[a]=false;
                a+=i;
            }
        }
        vec(ll) res;
        rep1(i,n) if(isok[i]) res.push_back(i);

        return res;
    }

// slope trickを扱う構造体
// https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
    struct slope_trick{
        ll C, fmin;
        priority_queue<ll> L;
        priority_queue<ll,vector<ll>,greater<ll>> R;

        slope_trick(){
            C=0; fmin=0;
            L.push(-llINF);
            R.push(llINF);
        }

        // LeRUの方
        void addr(ll a){
            fmin += max(L.top() - a, 0LL);

            L.push(a);
            R.push(L.top());
            L.pop();
        }

        void addl(ll a){
            fmin += max(a-R.top(), 0LL);

            R.push(a);
            L.push(R.top());
            R.pop();
        }

        void addc(ll b){
            C += b;
        }


    };




const ll MOD = 998244353; 
const ll PRIMITIVE_ROOT = 3; // 原始根


// オイラーツアー的なことをする初期化のdfs
// https://atcoder.jp/contests/abc294/submissions/40073643
struct abc{
    ll a,b,c;
    abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
};
vvec(abc) g; // resize(N), {to,idx,weight}
vec(abc) edge; // resize(N), eid>0となるように, {u,v,weight}
vec(Pll) edge_inout,node_inout; // resize(N)
vec(ll) hen,dist;

void dfs(ll now, ll eid, ll d){
    edge_inout[eid].first = hen.size();
    node_inout[now].first = hen.size();
    hen.push_back(eid);
    dist.push_back(d);

    for(abc gi:g[now]){
        if(gi.b==eid) continue;
        dfs(gi.a, gi.b, d+gi.c);
    }

    edge_inout[eid].second = hen.size();
    node_inout[now].second = hen.size();
    hen.push_back(-eid);
    dist.push_back(d - edge[eid].c);
}

    // g.resize(N);
    // edge.resize(N);
    // edge_inout.resize(N);
    // node_inout.resize(N);
    // dfs(0,0,0);





// x^n % mod を求める関数
ll pow_mod(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

// NTTを行う関数
void ntt(vector<ll>& a, bool inv) {
    const int n = a.size();
    ll g = pow_mod(PRIMITIVE_ROOT, (MOD - 1) / n, MOD);
    if (inv) {
        g = pow_mod(g, MOD - 2, MOD);
    }
    for (int i = 0, j = 1; j < n - 1; ++j) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1) {}
        if (j < i) swap(a[i], a[j]);
    }
    for (int i = 1; i < n; i <<= 1) {
        ll gn = pow_mod(g, n / i / 2, MOD);
        for (int j = 0; j < n; j += i << 1) {
            ll tmp = 1;
            for (int k = 0; k < i; ++k) {
                ll x = a[j + k];
                ll y = (a[j + k + i] * tmp) % MOD;
                a[j + k] = (x + y) % MOD;
                a[j + k + i] = (x - y + MOD) % MOD;
                tmp = (tmp * gn) % MOD;
            }
        }
    }
    if (inv) {
        ll n_inv = pow_mod(n, MOD - 2, MOD);
        for (int i = 0; i < n; ++i) {
            a[i] = (a[i] * n_inv) % MOD;
        }
    }
}

// 2つの多項式f, gの畳み込みhを計算する関数
vector<ll> convolution_ntt(const vector<ll>& f, const vector<ll>& g) {
    const int n = f.size();
    const int m = g.size();
    int sz = 1;
    while (sz < n + m - 1) {
        sz <<= 1;
    }
    vector<ll> a(sz), b(sz);
    for (int i = 0; i < n; ++i) {
        a[i] = f[i];
    }
    for (int i = 0; i < m; ++i) {
        b[i] = g[i];
    }
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < sz; ++i) {
        a[i] = (a[i] * b[i]) % MOD;
    }
    ntt(a, true);
    a.resize(n + m - 1);
    return a;
}




using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (inv ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

vector<ll> myconvolution2(vector<ll> a, vector<ll> b) {
    int n = 1;
    while (n < a.size() + b.size()) {
        n <<= 1;
    }
    vector<cd> fa(n), fb(n);
    for (int i = 0; i < a.size(); i++) {
        fa[i] = a[i];
    }
    for (int i = 0; i < b.size(); i++) {
        fb[i] = b[i];
    }
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, true);
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = round(fa[i].real());
    }
    return res;
}








const ll MOD = 998244353;
const int gen = 3;
const int gmax = 23;

struct mymint{
    ll _v;

    mymint():_v(0){}

    mymint(ll v):_v(v){
        while(_v<0) _v+=MOD;
        if(_v>=MOD) _v%=MOD;        
    }

    ll val() const { return _v; }

    mymint& operator+=(const mymint& x){
        _v += x._v;
        if(_v >= MOD) _v -= MOD;
        return *this;
    }
    mymint& operator-=(const mymint& x){
        _v -= x._v;
        if(_v < 0) _v += MOD;
        return *this;
    }
    mymint& operator*=(const mymint& x){
        _v *= x._v;
        if(_v>=MOD) _v%=MOD;        
        return *this;
    }
    mymint& operator/=(const mymint& x) { return *this = *this * x.inv(); }

    friend mymint operator+(const mymint& a, const mymint& b) {
        return mymint(a) += b;
    }
    friend mymint operator-(const mymint& a, const mymint& b) {
        return mymint(a) -= b;
    }
    friend mymint operator*(const mymint& a, const mymint& b) {
        return mymint(a) *= b;
    }

    mymint pow(long long n) const {
        mymint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    mymint inv() const {
        return pow(MOD - 2);
    }

};


int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}


void butterfly(vector<mymint>& a) {
    int n = int(a.size());
    int h = ceil_pow2(n);

    static bool first = true;
    static mymint sum_e[30];  
    if (first) {
        first = false;
        mymint es[30], ies[30];  
        int cnt2 = __builtin_ctz(MOD - 1);
        mymint e = mymint(gen).pow((MOD - 1) >> cnt2);
        mymint ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mymint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_e[i] = es[i] * now;
            now *= ies[i];
        }
    }
    for (int ph = 1; ph <= h; ph++) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mymint now = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p] * now;
                a[i + offset] = l + r;
                a[i + offset + p] = l - r;
            }
            now *= sum_e[__builtin_ctz(~(unsigned int)(s))];
        }
    }
}

void butterfly_inv(std::vector<mymint>& a) {
    int n = int(a.size());
    int h = ceil_pow2(n);

    static bool first = true;
    static mymint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
    if (first) {
        first = false;
        mymint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
        int cnt2 = __builtin_ctz(MOD - 1);
        mymint e = mymint(gen).pow((MOD - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mymint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_ie[i] = ies[i] * now;
            now *= es[i];
        }
    }

    for (int ph = h; ph >= 1; ph--) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mymint inow = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p];
                a[i + offset] = l + r;
                a[i + offset + p] =
                    (unsigned long long)(MOD + l.val() - r.val()) *
                    inow.val();
            }
            inow *= sum_ie[__builtin_ctz(~(unsigned int)(s))];
        }
    }
}


vector<mymint> myconvolution(vector<mymint> a, vector<mymint> b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) {
        if (n < m) {
            std::swap(n, m);
            std::swap(a, b);
        }
        std::vector<mymint> ans(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i + j] += a[i] * b[j];
            }
        }
        return ans;
    }
    int z = 1 << ceil_pow2(n + m - 1);
    a.resize(z);
    butterfly(a);
    b.resize(z);
    butterfly(b);
    for (int i = 0; i < z; i++) {
        a[i] *= b[i];
    }
    butterfly_inv(a);
    a.resize(n + m - 1);
    mymint iz = mymint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}






// https://trap.jp/post/1386/
vector<complex<double>> FFT(vector<complex<double>> A){
    const int N = A.size();
    if(N == 1) return A;
    vector<complex<double>> even(N / 2), odd(N / 2);
    for(int i = 0; i < N / 2; i++){
        even[i] = A[i * 2];
        odd[i] = A[i * 2 + 1];
    }
    even = FFT(even);
    odd = FFT(odd);
    for(int i = 0; i < N / 2; i++){
        odd[i] *= polar(1.0, 2 * M_PI * i / N);
        A[i] = even[i] + odd[i];
        A[N / 2 + i] = even[i] - odd[i];
    }
    return A;
}

vector<complex<double>> IFFT(vector<complex<double>> A){
    const int N = A.size();
    if(N == 1) return A;
    vector<complex<double>> even(N / 2), odd(N / 2);
    for(int i = 0; i < N / 2; i++){
        even[i] = A[i * 2];
        odd[i] = A[i * 2 + 1];
    }
    even = IFFT(even);
    odd = IFFT(odd);
    for(int i = 0; i < N / 2; i++){
        odd[i] *= polar(1.0, -2 * M_PI * i / N);
        A[i] = even[i] + odd[i];
        A[N / 2 + i] = even[i] - odd[i];
    }
    return A;
}



vec(ll) myconvolution3(vec(ll) a,vec(ll) b){
    ll n=a.size(), m=b.size();
    if(n==0 || m==0) return {};

    ll l = 1;
    while(l<(n+m-1)) l<<=1;

    vec(complex<double>) a2(l),b2(l);
    rep(i,n) a2[i] = a[i];
    rep(i,m) b2[i] = b[i];
    a2 = FFT(a2);
    b2 = FFT(b2);
    rep(i,l) a2[i]*=b2[i];
    a2 = IFFT(a2);

    vec(ll) res(n+m-1);
    rep(i,n+m-1) res[i] = a2[i].real()/double(l);

    return res;
}


// 文字列を小文字にする関数
string to_lower(const std::string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return tolower(c); });
    return result;
}


// 構造体と比較演算子のオーバーロード
struct masu{
    ll x,y,c;
    masu(ll x=0, ll y=0, ll c=0):x(x),y(y),c(c){}
};
bool operator< (const masu &a, const masu &b){ // これでpriority_queueで使える
    return a.c < b.c;
};
bool operator> (const masu &a, const masu &b){ // greaterの時はこっちも
    return a.c > b.c;
};


// Convex Hull Trick (max) // snuke
struct CHT {
  struct Linear {
    ll a, b;
    Linear(ll a=0, ll b=0): a(a), b(b) {}
    ll operator()(ll x) const { return a*x+b;}
  };
  deque<Linear> ls;
  void add(ll a, ll b) {
    Linear l(a,b);
    assert(ls.size() == 0 || ls.back().a <= l.a);
    while (ls.size() >= 2) {
      const Linear& l1 = ls[ls.size()-2];
      const Linear& l2 = ls.back();
      if ((l.a-l2.a)*(l1.b-l2.b) < (l2.a-l1.a)*(l2.b-l.b)) break;
      ls.pop_back();
    }
    ls.push_back(l);
  }
  ll operator()(ll x) { // x: asc
    ll res = ls[0](x);
    while (ls.size() >= 2) {
      ll now = ls[1](x);
      if (now < res) break;
      res = now;
      ls.pop_front();
    }
    return res;
  }
};


// グラハムスキャン、凸包
// https://atcoder.jp/contests/abc341/submissions/51470753




class Timer {
private:

public:
    clock_t startTime;
    double limitTime;


    Timer(double limit=0.) : limitTime(limit) {
        startTime = clock();
    }

    void restart(double limit){
        startTime = clock();
        limitTime = limit;
    }

    double getElapsedTime() {
        clock_t currentTime = clock();
        return static_cast<double>(currentTime - startTime) / CLOCKS_PER_SEC;
    }

    double getProgressRate() {
        return getElapsedTime()/limitTime;
    }



    bool isTimeUp() {
        return getElapsedTime() >= limitTime;
    }

};




struct Timer{
    ll start; // [clocks]
    ll limit;
    ll endt;

    void begin(double x){ // x[sec]
        start = clock();
        limit = x * CLOCKS_PER_SEC;
        endt = start + limit;
    }

    bool inTime(){
        return (clock()-start < limit);
    }

    bool inTime(double x){ // [sec]
        return (clock()-start < x*CLOCKS_PER_SEC);
    }

    ll remain(){
        return endt-clock();
    }

    ll past(){
        return clock()-start;
    }
};




// setからランダムに値を得る
ll set_random(set<ll> &s)
{
    auto it = s.cbegin();
    int random = rand() % s.size();
    advance(it, random);
 
    return *it;
}


// vectorの重複削除
/*
vec(ll) v={1,2,5,23,5};
sort(all(v));
v.erase(unique(all(v)), v.end());
*/



// ラムダ式
auto qpush = [&](ll cost, int id){
};


// 配列をシャッフル
//random_device seed_gen;
//mt19937 engine(seed_gen());
//shuffle(all(v), engine);


// ファイル出力
/*
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream outputfile("test.txt");
    outputfile<<"test";
    outputfile.close();
}
*/


// 構造体とそれ用の比較演算子
struct State{
    ll score;
    ll X[21];
    char LastMove;
    ll LastPos;
};

bool operator>(const State& a, const State& b){
    return (a.score > b.score);
}


    // 0.以上1.未満の整数をランダムに返す関数
    double Randdouble(){
        return 1. * rand() / RAND_MAX;
    }

    // vectorの途中を反転
    // reverse(ans.begin()+a, ans.begin()+b);


    // a以上b以下の整数をランダムに返す関数
    ll RandInt(ll a,ll b){
        return a + rand()%(b-a+1);
    }



        /*
        // LIS
        segtree<ll,op,ee> sega(N+1),segb(N+1);
        for(ll vi:va){
            ll x = sega.prod(0,vi);
            sega.set(vi,x+1);
        }
        */



    // インタラクティブな問題でflush必要なとき
    //cout << ans << endl; //で通るが
    //cout << ans << endl << flush; //でもOK


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






    //--- kitamasa法 ---
    // https://qiita.com/hidekikangeki/items/716ff998732f43050164
    // 以下で、数列Aの第N項(1-indexed)をAの第1~K項の線形和で表す係数を求めてくれる
    // kitamasa kita(vec(mint)(K,1),K);
    // auto res = kita.calculate(N-1);
    // TDPC_Tで使った

    struct kitamasa{
        ll n;//次数
        vector<mint> a;//漸化式の係数
        vector<vector<mint>> mem;//a_n+i = \sum a_j mem[i][n-1-j]
        //kitamasa(漸化式の係数,次数)
        kitamasa(vector<mint> c,ll N) : a(c),n(N){
            vector<mint> r(2*n,0);
            rep(i,n)r[i]=c[i];
            mem.push_back(r);
            rep(i,n+1){
                mem.push_back(oneplass(mem[i]));
            }
        }
        //畳み込み
        vector<mint> closs(vector<mint> b){
            vector<mint> res(2*n,0);  
            repr(i,2*n-2+1){//? vrep(i,2*n-2+1){
                mint a=0;
                rep(j,i+1){
                    a+=b[j]*b[i-j];
                }
                res[i]=a;
            }
            return res;
        }
        //a_l の係数-> a_l+1 の係数
        vector<mint> oneplass(vector<mint> b){
            vector<mint> res(2*n,0);
            rep(i,n-1){
                res[i]=b[i+1]+b[0]*a[i];
            }
            res[n-1]=b[0]*a[n-1];
            return res;
        }
        //a_l の係数-> a_2*l の係数
        vector<mint> twotimes(vector<mint> b){
            vector<mint> res(2*n,0);
            auto bb=closs(b);
            rep(i,n-1){
                rep(j,n){
                    bb[2*n-2-j]+=bb[n-2-i]*mem[i][n-1-j];
                }
                bb[n-2-i]=0;
            }
            rep(i,n){
                res[n-1-i]=bb[2*n-2-i];
            }
            return res;
        }
        //calculate(n)=a_nの係数
        vector<mint> calculate(int m){
            vector<mint> res(2*n,0);
            if(m<n){
                res[m]=a[m];
                return res;
            }
            if(m<=2*n){
                return mem[m-n];
            }else{
                if(m%2==0){
                    auto b=calculate(m/2);
                    res=twotimes(b);
                }else{
                    auto b=calculate((m-1)/2);
                    res=twotimes(b);
                    res=oneplass(res);
                }
            }
            return res;
        }
    };




//---自作SCC---
    struct SCC{
        ll n;
        vvec(ll) gf,gr;
        vec(bool) used;
        vec(ll) memo;

        SCC(ll _n, vvec(ll) _gf, vvec(ll) _gr){
            n = _n;
            gf = _gf;
            gr = _gr;
            assert(n==gf.size() && n==gr.size());
            used.resize(n);
        }

        void dfsf(ll now){
            used[now] = true;
            for(auto to:gf[now]) if(!used[to]) dfsf(to);
            memo.push_back(now);
            return;
        }

        vec(ll) tmp;

        void dfsr(ll now){
            tmp.push_back(now);
            used[now]=true;
            for(auto to:gr[now]) if(!used[to]) dfsr(to);
            return;
        }



        vvec(ll) get_group(){
            rep(i,n) used[i] = false;
            memo.clear();

            rep(st,n) if(!used[st]) dfsf(st);

            rep(i,n) used[i] = false;
            
            vvec(ll) res;
            reverse(all(memo));
            for(auto st:memo){
                if(used[st]) continue;
                tmp.clear();
                dfsr(st);
                res.push_back(tmp);
            }

            return res;
        }

    };




//---月ごとの日数---
    vec(ll) md = {31,28,31, 30,31,30, 31,31,30, 31,30,31};



//---ベクトルとか行列の掛け算---
    vvec(mint) vvxvv(vvec(mint) const& vv1, vvec(mint) const& vv2){
        ll h,w,d;
        h = vv1.size(); w=vv1[0].size(); d=vv2[0].size();
        assert(w==vv2.size());

        vvec(mint) res(h,vec(mint)(d));
        rep(i,h)rep(j,d)rep(k,w) res[i][j]+=vv1[i][k]*vv2[k][j];
        return res;
    }


    vec(mint) vvxv(vvec(mint) const& vv, vec(mint) const& v){
        ll h,w;
        h = vv.size(); w=vv[0].size();
        assert(w==v.size());

        vec(mint) res(h);
        rep(i,h)rep(j,w) res[i]+=vv[i][j]*v[j];
        return res;
    }

    mint vxv(vec(mint) const& v1, vec(mint) const& v2){
        ll h;
        h = v1.size();
        assert(h==v2.size());

        mint res=0;
        rep(i,h) res+=v1[i]*v2[i];
        return res;
    }

    // lxlの2次元正方行列のn乗
    vvec(mint) vvpow(vvec(mint) vv, ll n){
        ll l = vv.size();
        assert(vv[0].size()==l);

        vvec(mint) res(l,vec(mint)(l));
        rep(i,l) res[i][i]=1;

        while(n){
            if(n&1) res = vvxvv(vv, res);
            vv = vvxvv(vv,vv);
            n >>= 1;
        }
        return res;

    };




// multisetで1つだけ消す
// ms.erase(ms.find(5));

    // floor(sqrt(N))
    // https://atcoder.jp/contests/abc243/editorial/3510
    ll llsqrt(ll N){
        ll sqrtN=sqrt(N)-1;
        while(sqrtN+1<=N/(sqrtN+1))sqrtN++;
        return sqrtN;
    }



// オーバーフローとmod考慮したpow
    ll mypow(ll x, ll y, ll modnum){
        assert(y>=0);
        if(x%modnum==0) return 0;

        auto mul = [&](ll a, ll b){
            a%=modnum;
            b%=modnum;
            ll br = sqrt(b);
            ll ep = b-(br*br);
            ll res = (a*ep)%modnum;
            a = (a*br)%modnum;
            a = (a*br)%modnum;
            res = (a+res)%modnum;
            return res;
        };

        ll res = 1;
        while(y){
            if(y&1) res = mul(res,x);
            x = mul(x,x);
            y >>= 1;
        }
        return res;
    }



//---自分で構造体定義するsegtree---
struct T{mint ans,cnt,sum; };
T op(T a, T b){// A[i]はa<b
    mint var = a.ans + b.ans + b.sum*a.cnt - a.sum*b.cnt;
    return T{ var, a.cnt+b.cnt, a.sum+b.sum };
    }
T e(){return T({0,0,0});}
 

//--- opの順番を使う例 ---
// https://atcoder.jp/contests/abl/submissions/46688883
// mint ten[200020]; // 10^i
// mint one[200020]; // 1がi個


// struct S{
//     ll sz;
//     mint val;
// };
// struct F{ll k;};

// S op(S l,S r){return S{l.sz+r.sz, l.val*ten[r.sz]+r.val};} // opは左,右の順に受け取るっぽい
// S ee(){return S{0,0};}

// S mapping(F f, S x){
//     if(f.k>=0) return S{ x.sz, one[x.sz]*f.k};
//     return x;
// }
// F composition(F f,F g){
//     if(f.k>=0) return f;
//     return g;
// }
// F id(){return F{-1};}



//---prod:和, apply:一括変更 のlazy_segtreeのテンプレート---
struct S{ll sz,val;};
struct F{ll k;};

S op(S a,S b){return S{a.sz+b.sz, a.val+b.val};}
S ee(){return S{0,0};}

S mapping(F f, S x){
    if(f.k>=0) return S{ x.sz, x.sz*f.k};
    return x;
}
F composition(F f,F g){
    if(f.k>=0) return f;
    return g;
}
F id(){return F{-1};}



//---prod:区間max, apply:区間addのlazy_segtreeのテンプレート---
// ll op(ll a, ll b){ return max(a,b);}
// ll ee(){return 0;}
// ll mapping(ll f, ll x){return f+x;}
// ll composition(ll f,ll g){return f+g;}
// ll id(){return 0;}
//lazy_segtree<ll, op, ee, ll, mapping, composition, id> ls(N+1);




    //---modintで組み合わせ扱う用の構造体---
    struct mcomb{
        ll nmax;
        vec(mint) fa,af;
        mcomb(ll sz=200020){
            nmax = sz;
            fa.resize(nmax+1);
            fa[0]=1;
            rep1(i,nmax) fa[i]=fa[i-1]*i;
            af.resize(nmax+1);
            rep(i,nmax+1) af[i]=fa[i].inv();
        }
        mint c(ll n, ll k){
            if(n<k || k<0 || n>nmax) return 0;
            return fa[n]*af[k]*af[n-k];
        }
    };



// 遅延セグメント木の要素の構造体を定義して頑張るやつ
// https://atcoder.jp/contests/abc322/submissions/46138680






//---転倒数-fenwicktree--
ll inversions(vector<int> A){
  int N = A.size();
  ll ans=0;
  fenwick_tree<int> ft(N);
  for(auto ai:A){
    ans += ft.sum(ai,N);
    ft.add(ai,1);
  }
  return ans;
}




//---転倒数-分割統治法ver--
//https://kira000.hatenadiary.jp/entry/2019/02/23/053917#:~:text=%E8%BB%A2%E5%80%92%E6%95%B0%20(inversion%20number)%20%E3%81%A8,%E6%95%B0%E3%81%BE%E3%81%9F%E3%81%AF%E5%8F%8D%E8%BB%A2%E6%95%B0%E3%81%A8%E3%81%84%E3%81%86.
ll merge_cnt(vector<int> &a) {
    int n = a.size();
    if (n <= 1) { return 0; }

    ll cnt = 0;
    vector<int> b(a.begin(), a.begin()+n/2);
    vector<int> c(a.begin()+n/2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    int ai = 0, bi = 0, ci = 0;
    // merge の処理
    while (ai < n) {
        if ( bi < b.size() && (ci == c.size() || b[bi] <= c[ci]) ) {
            a[ai++] = b[bi++];
        } else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}








//---整数pow  x^y----
ll powll(ll x, ll y){
  assert(y>=0);
  ll res = 1;
  while(y){
    if(y&1) res *= x;
    x *= x;
    y >>= 1;
  }
  return res;
}






//---vector<P> を表示する----------------------
void showP(vector<P> vp){
  int n = vp.size();
  rep(i,n){
    cout << "first : " << vp[i].first << ", second : " << vp[i].second << endl;
  }
  //cout << "first : " << vp[n-1].first << ", second : " << vp[n-1].second;
  return;
}



// グループ分けを管理するデータ構造
//   parentにサイズを持たせる実装は後で(https://atcoder.jp/contests/abc177/editorial/90)
//---Union Find---
struct UnionFind{
  // グループのサイズ、要素の親idx、要素から親までのランクの配列
  vector<int> gsize,parent,rank;

  //コンストラクタ　各配列を初期化
  UnionFind(int N){
    gsize = vector<int>(N,1);
    parent = vector<int>(N,-1);
    rank = vector<int>(N);
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
    if(rank[x]==rank[y]) rank[x]++;
    return true;
  }

  // 2要素x,yが同じ集合に属するかどうか
  bool same(int x, int y){
    return findparent(x) == findparent(y);
  }
};



// //---snuke mint---
// // auto mod int
// // https://youtu.be/L8grWxBlIZ4?t=9858
// // https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// // https://youtu.be/8uowVvQ_-Mo?t=1329 : division
// const int mod = 1000000007;
// struct mint {
//   ll x; // typedef long long ll;
//   mint(ll x=0):x((x%mod+mod)%mod){} //ll = x; x = x%mod+mod)%mod; と同じらしい
//   mint operator-() const { return mint(-x);}
//   mint& operator+=(const mint a) {
//     if ((x += a.x) >= mod) x -= mod;
//     return *this;
//   }
//   mint& operator-=(const mint a) {
//     if ((x += mod-a.x) >= mod) x -= mod;
//     return *this;
//   }
//   mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
//   mint operator+(const mint a) const { return mint(*this) += a;}
//   mint operator-(const mint a) const { return mint(*this) -= a;}
//   mint operator*(const mint a) const { return mint(*this) *= a;}
//   mint pow(ll t) const {
//     if (!t) return 1;
//     mint a = pow(t>>1);
//     a *= a;
//     if (t&1) a *= *this;
//     return a;
//   }
 
//   // for prime mod
//   mint inv() const { return pow(mod-2);}
//   mint& operator/=(const mint a) { return *this *= a.inv();}
//   mint operator/(const mint a) const { return mint(*this) /= a;}
// };
// istream& operator>>(istream& is, mint& a) { return is >> a.x;}
// ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
 



//---素因数分解------
map<ll, ll > prime_factor(ll n) {
    map<ll, ll > pf;
    for(ll f=2; f*f<=n; ++f){
        while(n%f == 0){
            pf[f]++;
            n /= f;
        }
    }
    if(n!=1) pf[n] = 1;
    return pf;
}



//---n進数Aのm(>=0)桁目---
int nAm(int A,int n,int m) {
    int ans = (A % int(pow(n,m+1)+0.5))/int(pow(n,m)+0.5);
    return ans;
}



// combination
//vector<vector<ll>> comb(int N, int K){
ll comb(int N, int K){
  vector<vector<ll>> v(N+1,vector<ll>(N+1,0));
  for(int i = 0;i <=N; i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <= N;k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }

  /*
  rep(i,N+1){
    rep(j,N) cout << v[i][j] << " ";
    cout << v[i][N] << endl;
  }
  */
  return v[N][K];
}

// high speed combination? 列挙
//vector<vector<ll>> comb(int N, int K){
ll mycomb(int N, int K){
  if(N<K || N<0 || K <0) return 0;
  K = min(K,N-K);
  vector<vector<ll>> v(N+1,vector<ll>(K+1,0));
  rep(i,N+1) v[i][0]=1;
  rep(i,K+1) v[i][i]=1;

  for(int i=1; i<=N; i++){
    for(int j=1; j<=min(i,K); j++){
      v[i][j] = v[i-1][j-1] + v[i-1][j];      
    }
  }
  return v[N][K];
}

// 最大公約数
int gcd(int a, int b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
int lcm(int a, int b){
   return a * b / gcd(a, b);
}


// extgcd
// {g,x,y} : ax+by=g 
tuple<ll,ll,ll> extgcd(ll a,ll b){
    if(b==0) return {a,1,0};
    ll g,x,y;
    tie(g,x,y) = extgcd(b,a%b);
    return {g,y,x-a/b*y};
}




//---組み合わせを先に計算しておくやつ---
vvec(int) nCk(int N){
    vvec(int) res(N+1,vec(int)(N+1));
    rep(ni,N+1){
        res[ni][0]=1;
        //res[ni][ni]=1;
    }
    rep1(ni,N){
        rep1(ki,ni){
            res[ni][ki] = res[ni-1][ki-1] + res[ni-1][ki];
        }
    }
    return res;
}


//---組み合わせを先に計算しておくやつの構造体---
struct combination{
    int N;
    vvec(mint) nk;

    combination(int N=1){
        N=N;
        nk = vvec(mint)(N+1,vec(mint)(N+1));

        rep(ni,N+1) nk[ni][0]=1;
        rep1(ni,N) rep1(ki,ni) nk[ni][ki] = nk[ni-1][ki-1] + nk[ni-1][ki];
    }
};





//---階乗を先に計算しておくやつ---
vec(int) factorial(int k){
    vec(int) res(k+1);
    res[0]=1;
    rep1(i,k) res[i] = res[i-1]*i;
    return res;
}



//---stringを反転させる---
string strrev(string s){
    reverse(s.begin(),s.end());
    return s;
}


//---ファイル書き出し--
void fileout(string s){
    ofstream outputfile("tmp.dat");
    outputfile<<s;
    outputfile.close();
}


//---sort lambda---
/*
    sort(K.begin(),K.end(),[](P const& a, P const& b){
        if(a.second != b.second) return a.second>b.second;
        return a.first > b.first;
    });
*/


//---main---------------------------------------------
int main(){
  string s;
  cin >> s;
  cout << "original : " << s <<endl;
  string sr;
  sr = strrev(s);
  cout << "reverse : " << sr << endl;
  cout << "original? : " << s << endl;
  cout << s.size() << ", " << s.length() << endl;


  return 0;
}
