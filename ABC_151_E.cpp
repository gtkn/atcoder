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
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
    //---modintで組み合わせ扱う用の構造体---
    struct mcomb{
        ll nmax;
        vec(mint) fa,af;
        mcomb(ll sz=200020){
            nmax = sz;
            fa.resize(nmax+1);
            fa[0]=1;
            rep1(i,nmax) fa[i]=fa[i-1]*i;
            af.resize(nmax+1);
            rep(i,nmax+1) af[i]=fa[i].inv();
        }
        mint c(ll n, ll k){
            if(n<k || k<0 || n>nmax) return 0;
            return fa[n]*af[k]*af[n-k];
        }
    };

 
    void solve(){
        ll N,K;
        cin >> N >> K;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];
        sort(all(A));

        mint ans = 0;

        mcomb mc(N+10);
        rep(i,N){
            if(i >= K-1) ans += A[i]*mc.c(i,K-1);
            if(N-1-i >= K-1) ans -= A[i]*mc.c(N-1-i,K-1);
        }

        cout << ans.val() << endl;





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
