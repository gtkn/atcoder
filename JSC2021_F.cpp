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
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

// ll op(ll a,ll b){return a+b;}
// ll ee(){return 0LL;}


void solve(){
    ll N,M, Q;
    cin >> N >> M >> Q;


    vec(ll) T(Q),X(Q),Y(Q);
    rep(i,Q) cin >> T[i] >> X[i] >> Y[i];

    set<ll> s;
    s.insert(0);
    rep(i,Q) s.insert(Y[i]);

    ll nn = 0;
    map<ll,ll> m;
    for(ll si:s) m[si]=nn++;

    vector<fenwick_tree<ll>> fv(2,fenwick_tree<ll>(nn));
    vector<fenwick_tree<ll>> fvc(2,fenwick_tree<ll>(nn));
    ll res = 0;
    vvec(ll) ab(2);
    ab[0].resize(N);
    ab[1].resize(M);
    fvc[0].add(0,N);
    fvc[1].add(0,M);

    rep(qi,Q){
        ll ti=T[qi]-1, xi=X[qi]-1, yi=Y[qi];
        ll tj = 1-ti;

        // cout << qi << " ----- " << ti << ", " << xi <<", " << yi << ", "<<tj << endl;

        ll c0 = m[ab[ti][xi]], c1=m[yi];
        ll t0,t1,s0,s1;

        t0 = fv[tj].sum(0,c0+1);
        t1 = fv[tj].sum(0,c1+1);
        s0 = fvc[tj].sum(0,c0+1)*ab[ti][xi];
        s1 = fvc[tj].sum(0,c1+1)*yi;

        // cout << c0 << ", "<< c1 << ", " << t0 << ", " << t1 << " , " << s0 << " , " << s1 << endl;

        res += t0 -t1 - s0 + s1;
        cout <<res << endl;


        fv[ti].add(c0, -ab[ti][xi]);
        fv[ti].add(c1, yi);
        fvc[ti].add(c0, -1);
        fvc[ti].add(c1, 1);

        ab[ti][xi] = yi;

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
