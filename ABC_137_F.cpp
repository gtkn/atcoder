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
#define watch(x) cout << (#x) << " is " << (x) << endl
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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------
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
            // if (abs(augmentedMatrix.data[j][i]) > abs(augmentedMatrix.data[pivotRow][i])) {
            if (augmentedMatrix.data[j][i].val() > augmentedMatrix.data[pivotRow][i].val()) {
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



void solve(){
    ll p;
    cin >> p;
    vec(ll) a(p);
    rep(i,p) cin >> a[i];


    // modがテストケースで変わるとき
    using mint = modint;
    mint::set_mod(p);


    // 連立方程式を解く
    Matrix<mint> X(p, p);
    Vector<mint> Y(p);
    
    rep(i,p){
        mint x = 1;
        rep(j,p){
            X.data[i][j] = x;
            x *= i;
        }
    }
    rep(i,p) Y.data[i] = a[i];


    Vector<mint> ans = solveLinearEquations(X, Y);
    rep(i,p) cout << ans.data[i].val() << " "; cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
