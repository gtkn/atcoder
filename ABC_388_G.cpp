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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

// 数列の区間最大値を求める
struct SparseTable {
    int N;
    vector<vector<ll>> table;
    
    SparseTable(const vector<ll>& arr) {
        N = arr.size();
        ll K = log2(N) + 1;
        table.resize(N, vector<ll>(K));
        
        for (ll i = 0; i < N; i++) {
            table[i][0] = arr[i];
        }
        
        for (ll j = 1; (1 << j) <= N; j++) {
            for (ll i = 0; i + (1 << j) <= N; i++) {
                table[i][j] = max(table[i][j-1], table[i + (1 << (j-1))][j-1]);
            }
        }
    }
    
    SparseTable() = default; // Add default constructor
    
    ll query(ll l, ll r) {
        ll j = log2(r - l + 1);
        return max(table[l][j], table[r - (1 << j) + 1][j]);
    }
};



void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vec(ll) c(N);
    rep(i,N){
        ll x = A[i]*2;
        auto itr = lower_bound(all(A),x);
        c[i] = distance(A.begin(),itr) - i;
    }

    SparseTable st(c);

    // rep(i,N) cerr << c[i] << " "; cerr << endl;


    ll Q;
    cin >> Q;
    while(Q--){
        ll l,r; cin >> l >> r;
        --l;
        ll n = r-l;

        auto f = [&](ll k)->bool{
            if(k==0) return true;
            if(k*2>n) return false;
            if(st.query(l,l+k-1) > n-k) return false;
            return true;
        };


        ll a = 0, b = N;
        while(b-a>1){
            ll m = (a+b)/2;
            // cerr << a << " " << b << " " << m << " : " << f(m) << ", " << st.query(l,l+m-1) << endl;
            if(f(m)) a = m;
            else b = m;
        }

        cout << a << endl;

    }







    // ll Q;
    // cin >> Q;

    // vec(ll) L(Q),R(Q);
    // rep(i,Q) cin >> L[i] >> R[i];
    // rep(i,Q) L[i]--;

    // ll M = sqrt(N);

    // vec(ll) ids(Q);
    // rep(i,Q) ids[i] = i;

    // sort(all(ids),[&](ll i, ll j){
    //     if(L[i]/M != L[j]/M) return L[i] < L[j];
    //     return R[i] < R[j];
    // });

    
    // vec(ll) ans(Q);
    // ll l = 0, r = 0;
    // ll cnt = 0;

    // for(auto id:ids){
    //     ll nl = L[id], nr = R[id];

    //     cerr << id << "===" << endl;
    //     cerr << l << " " << r << " " << cnt << endl;
        

    //     while(l > nl){
    //         l--;
    //         if(A[l]*2 <= A[r-cnt-1] &&  r-l >=  2*(cnt+1) ) cnt++;
    //         cerr << l << " " << r << " " << cnt << endl;
    //     }
    //     while(r < nr){
    //         r++;
    //         if(A[l+cnt]*2 <= A[r-1] &&  r-l >=  2*(cnt+1) ) cnt++;
    //         cerr << l << " " << r << " " << cnt << endl;
    //     }
    //     while(l < nl){
    //         l++;
    //         if(cnt>0){
    //             bool isok = true;
    //             if(r-l >= 2*cnt) isok = false;
    //             rep(i,cnt){
    //                 if(A[l+i]*2 > A[r-cnt+i]) isok = false;
    //             }
    //             if(!isok) cnt--;
    //         }
            
    //         cerr << l << " " << r << " " << cnt << endl;
    //     }
    //     while(r > nr){
    //         r--;
    //         if(cnt>0){
    //             bool isok = true;
    //             if(r-l >= 2*cnt) isok = false;
    //             rep(i,cnt){
    //                 if(A[l+i]*2 > A[r-cnt+i]) isok = false;
    //             }
    //             if(!isok) cnt--;
    //         }
    //         cerr << l << " " << r << " " << cnt << endl;
    //     }

    //     // cerr << l << " " << r << " " << cnt << endl;

    //     ans[id] = cnt;
    // }

    // for(auto a:ans){
    //     cout << a << endl;
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
