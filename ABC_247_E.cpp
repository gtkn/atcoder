//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

//------------------------------------------------

struct Solver{
 
    void solve(){
        ll N,X,Y;
        cin >> N >> X >> Y;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];
        vec(ll) B={0};
        rep(i,N) B.push_back( A[i]<=X && A[i]>=Y );
        B.push_back(0);
        
        ll l;
        vec(Pll) rng;
        rep1(i,N+1){
            if(B[i]-B[i-1]==1) l=i-1;
            if(B[i]-B[i-1]==-1) rng.emplace_back(l,i-1);
        }

        ll ans = 0;
        for(Pll ri:rng){
            ll L,R;
            L = ri.first; R=ri.second;
            
            queue<ll> vx,vy;
            for(ll i=L ; i<R ; i++){
                if(A[i]==X) vx.push(i);
                if(A[i]==Y) vy.push(i);
            }

            for(ll i=L ; i<R && !vx.empty() && !vy.empty() ; i++){
                ll xi,yi;
                xi = vx.front(); yi = vy.front();
                ans += R-max(xi,yi);
                if(i==xi) vx.pop();
                if(i==yi) vy.pop();
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
