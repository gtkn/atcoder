//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
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
        ll N,M;
        cin >> N >> M;
        vec(ll) A(M+1);
        rep1(i,M) cin >> A[i];


        vec(ll) C(N+1);
        rep1(i,N) C[i]=i;
        rep1(i,M) swap(C[A[i]], C[A[i]+1]);
        vec(ll) Cinv(N+1);
        rep1(i,N) Cinv[C[i]] = i;

        vec(ll) B(N+1);
        rep1(i,N) B[i]=i;
        vec(ll) Binv(N+1);
        rep1(i,N) Binv[B[i]] = i;


        rep1(i,M){
            swap(Cinv[A[i]],Cinv[A[i]+1]);

            if(i>1){
                swap(B[A[i-1]],B[A[i-1]+1]);
                Binv[B[A[i-1]]] = A[i-1];
                Binv[B[A[i-1]+1]] = A[i-1]+1;
            }

            /*
            cout << "---" << i << " ---" << endl;
            rep1(i,N) cout << B[i] <<" " ; cout << endl;
            rep1(i,N) cout << Binv[i] <<" " ; cout << endl;
            rep1(i,N) cout << Cinv[i] <<" " ; cout << endl;
            */

            cout << Cinv[Binv[1]] << endl;

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
