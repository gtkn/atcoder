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
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

void solve(){
    ll N,Q;
    cin >> N >> Q;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];
    // sort(all(A),greater<ll>());
    reverse(all(A));

    vec(ll) rem(N+2);
    rem[N-1]=A[N-1]; rem[N-2]=A[N-2];
    for(ll i=N-3; i>=0; i--) rem[i] = rem[i+2] + A[i];

    vec(ll) cum(N+1);
    rep(i,N) cum[i+1] = cum[i]+1;


    auto f = [&](ll idx, ll x){
        ll jdx = (idx-1)/2;
        return abs(A[idx]-x) < abs(A[jdx]-x);
    };


    while(Q--){
        ll X; cin >> X;

        ll l = 0, r=N;
        while(r-l>1){
            ll mid = (l+r)/2;
            if(f(mid,X)) r=mid;
            else r=mid;
        }

        cout << X << "---" << l << endl;

        ll res = cum[ (l-1)/2 + 1];
        if(l%2==0){
            res += A[l/2];
            res += rem[l+2];
        }else{
            res += rem[l+1];
        }

        cout << res << endl;

    }



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
