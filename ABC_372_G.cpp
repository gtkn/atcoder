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


void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N),B(N),C(N);
    rep(i,N) cin >> A[i] >> B[i] >> C[i];


    vec(ll) v(N);
    rep(i,N) v[i] = i;
    sort(all(v),[&](ll i, ll j){
        if( A[i]*B[j] != A[j]*B[i] ) return A[i]*B[j] < A[j]*B[i];
        return C[i]*A[j] < C[j]*A[i];
    });




    vec(ll) L,xs;
    ll xmax = llINF;
    for(ll j:v){
        ll aj = A[j], bj = B[j], cj = C[j];
        // cerr << j << " " << aj << " " << bj << " " << cj << endl;

        if(!L.empty()){
            ll ai = A[L.back()], bi = B[L.back()], ci = C[L.back()];
            if(ai*bj == aj*bi){
                continue;
            }            
        }

        while(L.size()>=2){
            ll ai = A[L.back()], bi = B[L.back()], ci = C[L.back()];
            ll x = ( ci*bj - cj*bi ) / (ai*bj - aj*bi) + 1;
            if(x > xs.back()) break;
            L.pop_back();
            xs.pop_back();
        }

        L.push_back(j);
        if(xs.empty()){
            xs.push_back(-llINF);
        }else{
            ll ai = A[L[L.size()-2]], bi = B[L[L.size()-2]], ci = C[L[L.size()-2]];
            ll x = ( ci*bj - cj*bi ) / (ai*bj - aj*bi) + 1;
            xs.push_back(x);
        }
        chmin(xmax, (cj + aj-1) / aj);
    }
    xs.push_back(llINF);

    ll ans = 0;
    rep(i,L.size()){
        ll ai = A[L[i]], bi = B[L[i]], ci = C[L[i]];
        ll le = max(min(xs[i],xmax),1LL);
        ll ri = max(min(xs[i+1],xmax),1LL);

        ans += floor_sum(ri,bi,-ai,ci) - floor_sum(le,bi,-ai,ci);

        ll p,q,d;
        d = extGcd(ai,bi,p,q);
        if( (p*ci)%d == 0 && (q*ci)%d == 0 ){
            p = p*ci/d;            
            ll w = bi/d;
            p %= w;

            ll pl = (le-p+w-1)/w;
            ll pr = (ri-p+w-1)/w;
            // cerr << " " << pl << " , " << pr << endl;
            ans -= pr-pl;

        }

    }

    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
