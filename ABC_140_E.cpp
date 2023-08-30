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

ll op(ll a,ll b){return max(a,b);}
ll ee(){return -llINF;}

void solve(){
    ll N;
    cin >> N;
    ll nn = N+4;
    vec(ll) P(nn,llINF);
    rep(i,N) cin >> P[2+i];

    vec(ll) R(N+1);
    rep(i,nn) if(P[i]!=llINF) R[P[i]] = i;

    segtree<ll,op,ee> seg(P);

    auto fr = [&](ll l0,ll th)->ll{
        ll l=l0,r=nn;
        while(r-l>1){
            ll mid = (l+r)/2;
            if(seg.prod(l0,mid) < th) l=mid;
            else r=mid;
        }
        return l;
    };


    auto fl = [&](ll r0,ll th)->ll{
        ll l=0,r=r0;
        while(r-l>1){
            ll mid = (l+r)/2;
            if(seg.prod(mid,r0) < th) r=mid;
            else l=mid;
        }
        return l;
    };




    ll ans = 0;
    rep1(x,N-1){
        ll c = R[x];
        ll a0 = fl(c,x);
        ll a1 = fl(a0,x);
        ll b0 = fr(c+1,x);
        ll b1 = fr(b0+1,x);

        ll cnt = 0;
        if(b1<nn-1) cnt += (b1-b0)*(c-a0);
        if(a1>0) cnt += (a0-a1)*(b0-c);
        ans += cnt*x;

        // cout << x <<" : " << a1 << ", " << a0 << ", " << c << " , " << b0 << " , " << b1 << endl;


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
