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

using mint = modint;

struct Solver{

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };


 
    void solve(){
        ll N,M;
        cin >> N >> M;

        mint::set_mod(M);

        vec(ll) A(N);
        rep(i,N) cin >> A[i];


        auto f = [](ll x, ll y){
            mint res = 0;
            res += mint(x).pow(y);
            res += mint(y).pow(x);
            return res;
        };

        //vvec(mint) vv(N,vec(mint)(N));
        vec(abc) S;
        rep(i,N)rep(j,i){
            S.emplace_back(i,j, f(A[i],A[j]).val());
        }

        sort(all(S), [](abc const& a, abc const& b){
            return a.c > b.c;
        });


        dsu d(N);

        ll ans = 0;
        for(abc e:S){
            if(d.same(e.a,e.b)) continue;
            d.merge(e.a, e.b);
            ans += e.c;
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
