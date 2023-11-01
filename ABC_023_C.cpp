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
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){
    ll R,C,K;
    cin >> R >> C >> K;

    vec(ll) rcnt(R+1), ccnt(C+1);

    ll N;
    cin >> N;
    vec(ll) r(N),c(N);
    rep(i,N) cin >> r[i] >> c[i];

    rep(i,N){
        rcnt[r[i]]++;
        ccnt[c[i]]++;
    }

    vec(ll) cv(N+1);
    rep1(i,C) cv[ccnt[i]]++;

    ll ans = 0;
    rep1(i,R){
        ll rem = K-rcnt[i];
        if(rem<0) continue;
        ans += cv[ rem ];
    }


    rep(i,N){
        if(rcnt[r[i]]+ccnt[c[i]]==K) ans--;
        if(rcnt[r[i]]+ccnt[c[i]]==K+1) ans++;
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
