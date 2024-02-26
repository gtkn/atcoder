//title
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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



void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    ll Q;
    cin >> Q;


    Lseg lseg(N);
    vvec(ll) qv(Q);
    rep(i,Q){
        ll t; cin >> t;
        // cout << endl<< i << "," << t << endl;
        if(t==1){
            ll l,r,x;
            cin >> l >> r >> x;
            --l;
            lseg.apply(l,r,x);
            qv[i] = {l,r,x};
        }
        if(t==2){
            ll idx; cin >> idx; --idx;
            ll l,r,x;
            l = qv[idx][0]; r = qv[idx][1]; x = qv[idx][2]; 
            lseg.apply(l,r,-x);
        }
        if(t==3){
            ll idx; cin >> idx; --idx;
            ll res = lseg.get(idx);
            // cout << res << ",,,";
            chmax(res,A[idx]);
            cout << res << endl;            
        }
    }



    // vvec(ll) qv(Q,vec(ll)(4));
    // rep(i,Q){
    //     cin >> qv[i][0];
    //     if(qv[i][0]==1){
    //         rep1(j,3) cin >> qv[i][j];
    //     }else{
    //         cin >> qv[i][1];
    //     }
    // }

    // vec(erasable_priority_queue) v(N);
    // rep(i,N) v[i].add(A[i]);
    // lazy_segtree<erasable_priority_queue, op, ee, vec(ll), mapping, composition, id> lseg(v);

    // for(vec(ll) &q: qv){
    //     // cout << "q : "; rep(i,4) cout << q[i] <<" "; cout << endl;
    //     if(q[0]==1){
    //         lseg.apply(q[1]-1, q[2], {q[3]});
    //     }
    //     if(q[0]==2){
    //         ll i = q[1]-1;
    //         vec(ll) p = qv[i];
    //         lseg.apply(p[1]-1, p[2], {-p[3]});
    //     }
    //     if(q[0]==3){
    //         ll res = lseg.get(q[1]-1).top();
    //         cout << res << endl;
    //     }
    // }


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
