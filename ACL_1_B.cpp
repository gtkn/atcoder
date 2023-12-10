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

inline ll mod(ll a, ll m) {return (a % m + m) % m;}


const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

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



void solve(){
    ll N;
    cin >> N;

    ll nn = 2*N;
    ll ans = llINF;
    for(ll x=1; x*x<=nn; x++){
        if(nn%x!=0) continue;
        Pll tmp;
        tmp = ChineseRem(0, x, -1, nn/x);
        if(tmp.first!=0) chmin(ans, tmp.first );
        tmp = ChineseRem(0, nn/x, -1, x);
        if(tmp.first!=0) chmin(ans, tmp.first );
        
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
