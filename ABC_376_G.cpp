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
    ll a,l,root;
    S(ll a=0, ll l=1, ll root=0):a(a),l(l),root(root){}

    // bool operator>(const S &s) const{
    //     return a*s.l > s.a*l;
    // }

    bool operator<(const S &s) const{
        return a*s.l < s.a*l;
    }

    S operator+(const S &s) const{
        return S(a+s.a, l+s.l, root);
    }

};


struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N;
    cin >> N;

    vec(ll) p(N+1),a(N+1);
    rep1(i,N) cin >> p[i];
    rep1(i,N) cin >> a[i];

    mint atot = 0;
    rep1(i,N) atot += a[i];

    vec(S) v(N+1);
    rep(i,N+1) v[i] = S(a[i],1,i);

    dsu uf(N+1);

    priority_queue<S> pq;
    rep1(i,N) pq.emplace(a[i],1,i);

    mint ans = 0;

    while(!pq.empty()){
        S s1 = pq.top(); pq.pop();
        ll par = p[s1.root];

        if(s1.l != v[uf.leader(s1.root)].l) continue;


        S s2 = v[uf.leader(par)];
        S s21 = s2 + s1;

        uf.merge(s1.root,s2.root);
        v[uf.leader(s1.root)] = s21;

        mint d = s2.l * s1.a;
        ans += d;
        if(s21.root != 0) pq.push(s21);

        // cerr << s1.root << " " << par << " " << d.val() << endl;

    }

    S s0 = v[uf.leader(0)];
    // ans += s0.a*s0.l;

    ans/=atot;
    cout << ans.val() << endl;


}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
