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
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

mint op(mint a, mint b){return a+b;}
mint ee(){return 0;}


struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,Q;
        cin >> N >> Q;

        vec(ll) A(N+1);
        rep1(i,N) cin >> A[i];

        vec(mint) v0(N+1),v1(N+1),v2(N+1);
        rep1(i,N) v0[i]=A[i];
        rep1(i,N) v1[i]=i*v0[i];
        rep1(i,N) v2[i]=i*i*v0[i];
        
        segtree<mint, op, ee> s0(v0),s1(v1),s2(v2);

        while(Q--){
            ll t,x,v;
            cin >> t >> x;
            if(t==1){
                cin >> v;
                s0.set(x, v);
                s1.set(x, v*x);
                s2.set(x, mint(v)*x*x);
            }else{
                mint res = 0;
                res += s0.prod(0,x+1)*(x*x+3*x+2)/2;
                res -= s1.prod(0,x+1)*(2*x+3)/2;
                res += s2.prod(0,x+1)/2;
                cout << res.val() << endl;
            }
        }


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
