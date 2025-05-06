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


struct S{
    ll n,sum0,sum1;
    S():n(0),sum0(0),sum1(0){}
    S(ll x):n(1),sum0(x),sum1(0){}
    
    S& operator+=(const S& s){
        if(this->n&1){
            this->sum0 += s.sum1;
            this->sum1 += s.sum0;
        }else{
            this->sum0 += s.sum0;
            this->sum1 += s.sum1;
        }
        this->n += s.n;    
        return *this;
    } 

    S operator+(const S& s) const{
        S res = *this;
        res += s;
        return res;
    }
};


struct dynamic_segtree{
    ll n;
    unordered_map<ll,S> mp;
    dynamic_segtree(ll max_size=0){
        n = 1;
        while(n < max_size) n <<= 1;
    }

    void add(ll idx, S s){
        ll now = idx + n;
        mp[now] += s;
        while(now > 1){
            now >>= 1;
            ll l = (now<<1);
            ll r = l|1;
            mp[now] = mp[l] + mp[r];
        }
    }

    S get() {
        return mp[1];
    }

};





void solve(){
    ll Q;
    cin >> Q;

    ll M = 1e9;
    dynamic_segtree seg(M);
    ll z = 0;
    while(Q--){
        ll y;
        cin >> y;
        ll x = (y+z)%M + 1;
        seg.add(x, S(x));
        S s = seg.get();
        z = s.sum0;
        cout << z << nl;

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
