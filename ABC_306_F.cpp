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
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


ll op(ll a,ll b){return a+b;}
ll ee(){return 0;}


struct Solver{
 
    void solve(){
        ll N,M;
        cin >> N >> M;

        vvec(ll) A(N,vec(ll)(M));
        rep(i,N)rep(j,M) cin >> A[i][j];
        rep(i,N) sort(all(A[i]));


        vec(ll) v;
        rep(i,N)rep(j,M) v.push_back(A[i][j]);
        sort(all(v));

        map<ll,ll> m;
        rep(i,N*M) m[v[i]] = i;

        vvec(ll) B(N,vec(ll)(M));
        rep(i,N)rep(j,M) B[i][j] = m[A[i][j]];

        ll ans = 0;
        vec(ll) tmp(N*M,1);
        segtree<ll,op,ee> seg(tmp);


        rep(i,N){
            ll nn = N-i-1;
            rep(j,M){
                ll x = seg.prod(0,B[i][j]);
                ans += nn*(j+1)+x;
                seg.set(B[i][j],0);
            }
        }

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
