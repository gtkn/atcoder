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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------
class Lseg {
private:
    ll n;              // 元の配列の要素数
    vec(ll) tree;   // セグメント木のノードを格納する配列
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
        if(node<0) return 0;
        ll res = 0;

        if (idx < start || end <= idx) {
            return 0;
        }

        res += tree[node];
        if(start+1==end) return res;

        ll mid = (start + end) / 2;
        ll leftRes = get(node * 2, start, mid, idx);
        ll rightRes = get(node * 2 + 1, mid, end, idx);

        res += leftRes;
        res += rightRes;

        return res;
    }



    void apply(ll left, ll right, ll x){
        return apply(1, 0, n, left, right, x);
    }

    void apply(ll node, ll start, ll end, ll left, ll right, ll x) {
        if (right <= start || end <= left) {
            return;
        }
        if (left <= start && end <= right) {
            tree[node] += x;
            return;
        }
        ll mid = (start + end) / 2;
        apply(node * 2, start, mid, left, right, x);
        apply(node * 2 + 1, mid, end, left, right, x);
        return;
    }


};


void solve(){
    ll N,M;
    cin >> N >> M;

    vec(ll) A(N),B(M);
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];

    Lseg lseg(N);
    rep(i,N) lseg.apply(i,i+1,A[i]);

    for(ll bi:B){
        ll nn = lseg.get(bi);
        lseg.apply(bi, bi+1, -nn);

        ll l = bi+1, r = bi+nn+1;

        ll d = r/N;
        lseg.apply(0,N,d);
        lseg.apply(0,r%N,1);

        d = l/N;
        lseg.apply(0,N,-d);
        lseg.apply(0,l%N,-1);
    }

    rep(i,N) cout << lseg.get(i) << " "; cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
