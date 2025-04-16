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


// アリストテレスのふるいで素数を列挙
vec(ll) eratosthenes(ll n){
    vec(bool) isok(n+1,true);
    isok[0]=false; isok[1]=false;
    rep1(i,n){
        if(!isok[i]) continue;
        ll a=i*2;
        while(a<=n){
            isok[a]=false;
            a+=i;
        }
    }
    vec(ll) res;
    rep1(i,n) if(isok[i]) res.push_back(i);

    return res;
}




//---素因数分解------
map<ll, ll > prime_factor(ll n) {
    map<ll, ll > pf;
    for(ll f=2; f*f<=n; ++f){
        while(n%f == 0){
            pf[f]++;
            n /= f;
        }
    }
    if(n!=1) pf[n] = 1;
    return pf;
}




void solve(){
    ll Q;
    cin >> Q;


    ll th = 1e6;
    vec(ll) cnt(th+1,0);
    rep1(i,th){
        if(i==1) continue;
        if(cnt[i]>0) continue;
        ll a = i;
        while(a<=th){
            cnt[a]++;
            a+=i;
        }
    }

    set<ll> st;
    rep1(i,th) if(cnt[i]==2) st.insert(i*i);

    // rep1(i,20) cerr << i << " " << cnt[i] << endl;

    while(Q--){
        ll A;
        cin >> A;
        auto it = st.upper_bound(A);
        // if(it==st.begin()) cerr << "error" << endl;
        it--;
        cout << *it << nl;
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
