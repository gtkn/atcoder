//title
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (int i = (n); i > 0; --i)
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
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1e9;//1LL << 60;
const int iINF = 1e9;

//------------------------------------------------

ll op(ll a,ll b){return min(a,b);}
ll e(){return llINF;}



struct Solver{
 
    void solve(){
        ll N,K;
        cin >> N >> K;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];
        
        set<ll> s;
        rep(i,N) s.insert(A[i]);
        ll cnt = 0;
        map<ll,ll> m;
        for(ll si:s) m[si]=cnt++;

        vec(ll) v(N);
        rep(i,N) v[i] = m[A[i]];

        segtree<ll,op,e> seg(cnt);
        for(ll i = N-1; i>=K ;i--) seg.set(v[i], i);
        
        ll ans = llINF;
        rep(i,K){
            ll x = seg.prod(v[i]+1,cnt);
            if(x!=llINF) chmin(ans, x - i);
        }
        if(ans>=llINF) ans=-1;
        cout<< ans << endl;


    }
};


int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
