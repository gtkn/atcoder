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

// bit xor の掃き出し法
// 参照渡しのcを操作して、ランクを返す
// https://atcoder.jp/contests/abc249/submissions/30994270
template <class T, int W> int sweep(vector<T>& c) {
    int n = (int)c.size(), rank = 0;
    for (int d = W - 1; d >= 0; --d) {
        int k = rank;
        while (k < n and !(c[k] >> d & 1)) {
            k += 1;
        }
        if (k < n) {
            swap(c[k], c[rank]);
            for (int i = rank + 1; i < n; ++i) {
                if (c[i] >> d & 1) {
                    c[i] ^= c[rank];
                }
            }
            rank += 1;
        }
    }
    return rank;
}


constexpr ll W = 30;

void solve(){
    ll N,K;
    cin >> N >> K;
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];

    vec(ll) c(N);
    rep(i,N) c[i] = (A[i]<<W) | B[i];

    ll n = sweep<ll,2*W>(c);

    ll amin = (c.back()>>W);
    if(amin > K) dame;

    vec(ll) a(n),b(n);
    rep(i,n){
        a[i] = c[i]>>W;
        b[i] = c[i] & ((1<<W)-1);
    }

    ll m = 0;
    while(m<n && a[m]>0){
        m++;
    }


    auto f = [](vector<ll> c, ll x)->ll{
        ll n = sweep<ll,W>(c);
        rep(i,n) chmax(x, x^c[i]);
        return x;
    };

    // vec(ll) bb = b;
    // reverse(all(bb));

    ll ans = 0, fixed_a = 0, fixed_b = 0;
    rep(i,m){
        // cerr << "i: " << i << endl;
        // bb.pop_back();
        ll msb = 1;
        while( (msb << 1) <= a[i] ){
            msb <<= 1;
        }

        if( (fixed_a|(msb-1)) <= K){
            // chmax(ans, f( bb, fixed_b ));
            chmax(ans, f( vector<ll>(b.begin() + i + 1, b.end()), fixed_b ));
            fixed_a ^= a[i];
            fixed_b ^= b[i];
        }else if( (fixed_a^a[i] | (msb-1)) <= K ){
            // chmax(ans, f( bb, fixed_b^b[i] ));
            chmax(ans, f( vector<ll>(b.begin() + i + 1, b.end()), fixed_b^b[i] ));
        }else{
            if(fixed_a & msb){
                fixed_a ^= a[i];
                fixed_b ^= b[i];
            }
        }
    }

    if(fixed_a <= K){
        // chmax(ans, f( bb, fixed_b ));
        chmax(ans, f( vector<ll>(b.begin() + m, b.end()) , fixed_b ));

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
