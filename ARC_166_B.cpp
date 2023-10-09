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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){
    ll N,a,b,c;
    cin >> N >> a >> b >> c;

    ll ab,bc,ca,abc;
    ab = a*b/__gcd(a,b);
    bc = b*c/__gcd(b,c);
    ca = c*a/__gcd(c,a);
    abc = ab*c/__gcd(ab,c);

    vec(ll) v= {a,b,c,ab,bc,ca,abc};

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    // vec(ll) x(7,llINF);
    vvec(ll) vv(N,vec(ll)(7));
    rep(i,N)rep(j,7){
        vv[i][j]= ((A[i]+v[j]-1)/v[j])*v[j] - A[i];
        // chmin(x[j], ((A[i]+v[j]-1)/v[j])*v[j] - A[i]);
    }


    ll ans = llINF;
    // chmin(ans, x[0]+x[1]+x[2] );
    // chmin(ans, x[3]+x[2] );
    // chmin(ans, x[4]+x[0] );
    // chmin(ans, x[5]+x[1] );
    // chmin(ans, x[6] );

    vvec(Pll) xx(7);
    rep(i,7)rep(j,N) xx[i].emplace_back(vv[j][i],j);
    rep(i,7) sort(all(xx[i]));

    ll san = min((ll)3,N);

    rep(i,san)rep(j,san)rep(k,san){
        Pll x0,x1,x2;
        x0 = xx[0][i]; x1 = xx[1][j]; x2 = xx[2][k];

        if(x0.second==x1.second || x0.second==x2.second || x1.second==x2.second) continue;
        chmin(ans,x0.first+x1.first+x2.first);
    }

    rep(i,san)rep(j,san){
        Pll x0,x1;
        x0 = xx[3][i]; x1 = xx[2][j];

        if(x0.second==x1.second) continue;
        chmin(ans,x0.first+x1.first);
    }

    rep(i,san)rep(j,san){
        Pll x0,x1;
        x0 = xx[4][i]; x1 = xx[0][j];

        if(x0.second==x1.second) continue;
        chmin(ans,x0.first+x1.first);
    }

    rep(i,san)rep(j,san){
        Pll x0,x1;
        x0 = xx[5][i]; x1 = xx[1][j];

        if(x0.second==x1.second) continue;
        chmin(ans,x0.first+x1.first);
    }

    chmin(ans, xx[6][0].first);
    


    cout << ans << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
