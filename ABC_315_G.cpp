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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

// extgcd
// {g,x,y} : ax+by=g 
tuple<ll,ll,ll> extgcd(ll a,ll b){
    if(b==0) return {a,1,0};
    ll g,x,y;
    tie(g,x,y) = extgcd(b,a%b);
    return {g,y,x-a/b*y};
}




void solve(){
    ll N,A,B,C,X;
    cin >> N >> A >> B >> C >> X;

    X -= (A+B+C);   
    auto [g,jj,kk] = extgcd(B,C);

    ll b = B/g;
    ll c = C/g;

    ll ans = 0;
    rep(i,N){
        ll xx = X - A*i;
        if(xx<0) break;
        if(xx%g!=0) continue;

        ll x = xx/g;
        
        ll j0 = ((jj+c)*(x%c))%c;
        ll k0 = (x-b*j0)/c;
        assert((x-b*j0)%c==0);

        ll nmax=llINF, nmin=0;
        chmin(nmax, (N-j0+c-1)/c);
        chmin(nmax, k0/b+1);
        if(k0<0) nmax=0;
        if(k0-N>=0) chmax(nmin, (k0-N)/b+1);
        ans += max(0LL, nmax-nmin);

    }
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
