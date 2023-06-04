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

struct Solver{
 
    void solve(){
        ll H,W;
        cin >> W >> H;

        ll N;
        cin >> N;

        vec(ll) p(N),q(N);
        rep(i,N) cin >> p[i] >> q[i];

        ll A; cin >> A;
        vec(ll) a(A+2);
        rep1(i,A) cin >> a[i];
        a[A+1] = W;

        ll B; cin >> B;
        vec(ll) b(B+2);
        rep1(i,B) cin >> b[i];
        b[B+1] = H;


        map<Pll,ll> m;
        rep(i,N){
            ll x = distance(a.begin(), upper_bound(all(a), p[i]));
            ll y = distance(b.begin(), upper_bound(all(b), q[i]));


            // printf("(%lld,%lld) in (%lld,%lld) \r\n",p[i],q[i],x,y);

            m[{x,y}]++;
        }

        ll amax=0, amin=llINF;
        for(auto mi:m){
            chmax(amax, mi.second);
            chmin(amin, mi.second);
        }

        if((A+1)*(B+1) > m.size()) amin=0;

        cout << amin << " " << amax << endl;
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
