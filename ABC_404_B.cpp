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



template<typename T>
struct RotatableMatrix {
    vector<vector<T>> mat;
    int h, w; // 回転前の行数と列数
    int rot; // (0,1,2,3) * 90deg

    RotatableMatrix(int h, int w) : h(h), w(w), rot(0) {
        mat.resize(h, vector<T>(w));
    }
    RotatableMatrix(const vector<vector<T>>& m) : h(m.size()), w(m[0].size()), rot(0) {
        mat = m;
    }


    // 回転
    void rotate(int r) {
        rot = (rot + r) % 4;
        if (rot < 0) rot += 4;
    }

    // 回転後の(i, j)成分を取得
    T get(int i, int j) const {
        int ni, nj;
        if (rot == 0) {
            ni = i; nj = j;
        } else if (rot == 1) {
            ni = w - 1 - j; nj = i;
        } else if (rot == 2) {
            ni = h - 1 - i; nj = w - 1 - j;
        } else { // rot == 3
            ni = j; nj = h - 1 - i;
        }
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
            throw out_of_range("Index out of range");
        }
        return mat[ni][nj];
    }

    // 回転後の(i, j)成分を設定
    T set(int i, int j, T value) {
        int ni, nj;
        if (rot == 0) {
            ni = i; nj = j;
        } else if (rot == 1) {
            ni = w - 1 - j; nj = i;
        } else if (rot == 2) {
            ni = h - 1 - i; nj = w - 1 - j;
        } else { // rot == 3
            ni = j; nj = h - 1 - i;
        }
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) {
            throw out_of_range("Index out of range");
        }
        mat[ni][nj] = value;
    }

    void show() const {
        cout << "rot = " << rot << endl;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};



void solve(){
    ll N;
    cin >> N;

    vvec(char) S(N,vec(char)(N)), T(N,vec(char)(N));
    
    rep(i,N){
        string ss;
        cin >> ss;
        rep(j,N) S[i][j] = ss[j];
    }
    rep(i,N){
        string ss;
        cin >> ss;
        rep(j,N) T[i][j] = ss[j];
    }

    RotatableMatrix<char> rs(S),rt(T);

    ll ans = llINF;
    rep(r,4){
        ll cnt = r;
        rep(i,N)rep(j,N){
            if(rs.get(i,j) != rt.get(i,j)) cnt++;
        }

        // cerr << "cnt = " << cnt << endl;
        // rs.show();
        // cerr << endl;
        


        chmin(ans,cnt);
        rs.rotate(1);
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
