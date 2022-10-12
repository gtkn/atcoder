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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

ll op(ll a,ll b){return max(a,b);}
ll ee(){return 0;};

struct Solver{
 
    void solve(){
        ll N;
        cin >> N;

        vec(ll) A(N),B(N);
        rep(i,N) cin >> A[i];
        rep(i,N) cin >> B[i];

        map<ll,ll> ma,mb;
        rep(i,N) ma[A[i]] = B[i];
        rep(i,N) mb[B[i]] = A[i];

        sort(all(A));
        sort(all(B));

        vec(ll) va(N),vb(N);
        rep(i,N) va[i] = mb[B[i]];
        rep(i,N) vb[i] = ma[A[i]];

        segtree<ll,op,ee> sega(N+1),segb(N+1);

        for(ll vi:va){
            ll x = sega.prod(0,vi);
            sega.set(vi,x+1);
        }

        for(ll vi:vb){
            ll x = segb.prod(0,vi);
            segb.set(vi,x+1);
        }

        ll ans = max(sega.all_prod(), segb.all_prod()) + N;

        cout << ans << endl;
                







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
