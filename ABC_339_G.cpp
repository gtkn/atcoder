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


struct MergeSortTree{
    ll n;
    vec(ll) v; // 元のvector
    vvec(ll) vv;
    vvec(ll) cum;
    ll m;

    MergeSortTree(vec(ll) v){
        this->n = v.size(); // サイズは2冪にしておく
        this->v = v;
        this->m = 3*this->n;

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



void solve(){
    ll N;
    cin >> N;

    ll NN = 2<<18;

    vec(ll) A(NN,llINF);
    rep(i,N) cin >> A[i];



    MergeSortTree mst(A);




    ll Q;
    cin >> Q;
    
    ll prev = 0;
    while(Q--){
        ll a,b,c;
        cin >> a >> b >> c;
        ll L,R,X;
        L = (a^prev)-1;
        R = (b^prev)-1;
        X = (c^prev);

        // cout << L << ", " << R << ", " << X << endl;

        ll res = mst.query(L,R+1,X);
        cout << res << endl;
        prev = res;




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
