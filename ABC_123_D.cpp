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
        ll X,Y,Z,K;
        cin >> X >> Y >> Z >> K;

        vec(ll) A(X),B(Y),C(Z);
        rep(i,X) cin >> A[i];
        rep(i,Y) cin >> B[i];
        rep(i,Z) cin >> C[i];


        vec(ll) BC;
        rep(i,Y)rep(j,Z) BC.push_back(B[i]+C[j]);

        sort(all(A), greater<ll>());
        sort(all(BC), greater<ll>());

        vec(ll) v;
        rep(i, min(K,X))rep(j,min(K,Y*Z)) v.push_back(A[i] + BC[j]);
        sort(all(v), greater<ll>());

        rep(i,K) cout << v[i] << endl;


        // set<ll> BC;
        // rep(i,Y)rep(j,Z) BC.insert(B[i]+C[j]);

        // sort(all(A));
        // ll xyz = X*Y*Z;

        // rep1(th,K){
        //     ll l=0,r=3e10+10;

        //     while(r-l>1){
        //         ll mid = (l+r)/2;
        //         ll cnt = xyz;
        //         for(ll ai:A){
        //             auto itr = BC.lower_bound( mid-ai );
        //             cnt -= distance(BC.begin(), itr);
        //         }
        //         if(cnt>=th) l=mid;
        //         else r=mid;
        //     }
        //     cout << l << endl;
        // }



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
