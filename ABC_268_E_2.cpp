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


// //---prod:和, apply:一括変更 のlazy_segtreeのテンプレート---
// struct S{ll sz,val;};
// struct F{ll k;};

// S op(S a,S b){return S{a.sz+b.sz, a.val+b.val};}
// S ee(){return S{0,0};}

// S mapping(F f, S x){
//     if(f.k>=0) return S{ x.sz, x.sz*f.k};
//     return x;
// }
// F composition(F f,F g){
//     if(f.k>=0) return f;
//     return g;
// }
// F id(){return F{-1};}


// struct S{
//     ll sz;
//     mint sum;
//     S(ll sz=0, mint sum=0):sz(sz),sum(sum){}
// };

// struct F{
//     ll k;
//     F(ll k=0):k(k){}
// };

// S op(S a, S b){
// }







void solve(){
    ll N;
    cin >> N;

    vec(ll) p(N);
    rep(i,N) cin >> p[i];

    vec(ll) d(N);
    rep(i,N) d[i] = mod(p[i]-i,N);

    // rep(i,N) cerr << d[i] << " "; cerr << endl;

    ll nn = 2*N;
    vec(ll) val(nn), cnt(nn);
    rep(i,N) val[d[i]]+=d[i], cnt[d[i]]++;
    rep(i,N) val[i+N] = val[i]+N*cnt[i], cnt[i+N] = cnt[i];

    vec(ll) cval(nn+1), ccnt(nn+1);
    rep(i,nn) cval[i+1] = cval[i] + val[i];
    rep(i,nn) ccnt[i+1] = ccnt[i] + cnt[i];

    ll ans = llINF;
    rep(l,N){
        ll m = l+N/2, r = l+N;
        ll a = (cval[m]-cval[l]) - l*(ccnt[m]-ccnt[l]);
        ll b = r*(ccnt[r]-ccnt[m]) - (cval[r]-cval[m]);
        ll tmp = a+b;
        chmin(ans,tmp);

        // ll chk = 0;
        // rep(i,N){
        //     ll c = mod(p[i]-l-i,N);
        //     chk += min(c,N-c);
        // }
        // cerr << l << " ; " << a << " " << b << " " << tmp << " " << chk <<  endl;
    }
    rep(l,N){
        ll m = l+(N+1)/2, r = l+N;
        ll a = (cval[m]-cval[l]) - l*(ccnt[m]-ccnt[l]);
        ll b = r*(ccnt[r]-ccnt[m]) - (cval[r]-cval[m]);
        ll tmp = a+b;
        chmin(ans,tmp);
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
