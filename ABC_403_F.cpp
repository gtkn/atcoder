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
    ll n;
    string s;
    bool b;
    S(ll n=llINF, string s="INF", bool b=false):n(n),s(s),b(b){}

    bool operator<(const S &other) const {
        if(n != other.n) return n < other.n;
        return b < other.b;
    }

    bool operator>(const S &other) const {
        if(n != other.n) return n > other.n;
        return b > other.b;
    }

    S operator+(const S &other) const {
        return S(n + other.n + 1, s + "+" + other.s,  true);
    }

    S operator*(const S &other) const {
        ll n = this->n + other.n + 1;
        string ss = "";
        if(this->b){
            ss += "("+this->s+")";
            n+=2;
        }else{
            ss += this->s;
        }
        ss += "*";
        if(other.b){
            ss += "("+other.s+")";
            n+=2;
        }else{
            ss += other.s;
        }
        return S(n, ss, false);
    }
};


void solve(){
    ll N;
    cin >> N;

    ll M = 2020;
    vector<S> v(M);
    v[1] = S(1, "1", false);
    v[11] = S(2, "11", false);
    v[111] = S(3, "111", false);
    v[1111] = S(4, "1111", false);

    for(ll x=2; x<M; x++){
        for(ll a=2; a*a<=x; a++){
            if(x%a != 0) continue;
            ll b = x/a;
            chmin(v[x], v[a] * v[b]);
        }

        for(ll a=1; a<=x/2; a++){
            ll b = x-a;
            chmin(v[x], v[a] + v[b]);
        }
    }

    // rep1(i,10){
    //     cerr << i << ": " << v[i].s << ", " << v[i].n << endl;
    // }

    cout << v[N].s << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
