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


struct S{
    ll a,b,r;
    S(ll a=0,ll b=0, ll r=0):a(a),b(b),r(r){}

    bool operator<(const S& s) const{
        return b*s.a < s.b*a;
    }    
    bool operator>(const S& s) const{
        return b*s.a > s.b*a;
    }

    S operator+(const S& s){
        return S(a+s.a, b+s.b, r);
    }
};


void solve(){
    ll N;
    cin >> N;
    vec(ll) P(N),V(N);
    rep1(i,N-1) cin >> P[i];
    rep(i,N) cin >> V[i];

    rep1(i,N-1) P[i]--;


    dsu uf(N);
    vec(S) ss(N);
    rep(i,N){
        if(V[i]==0) ss[i] = S(1,0,i);
        else ss[i] = S(0,1,i);
    }

    priority_queue<S,vector<S>,greater<S>> pq;
    rep1(i,N-1) pq.push(ss[i]);

    ll ans = 0;
    while(!pq.empty()){
        S snow = pq.top(); pq.pop();

        S schk = ss[ uf.leader(snow.r) ];
        if(snow.a!=schk.a || snow.b!=schk.b) continue;

        S spar = ss[ uf.leader(P[snow.r]) ];
        S snew = spar + snow;

        uf.merge(snow.r, spar.r);
        ss[uf.leader(snew.r)] = snew;


        ll d = spar.b * snow.a;
        ans += d;

        // cerr << snow.r << " " << P[snow.r] << " : " << d << endl;

        if(spar.r!=0) pq.push(snew);
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
