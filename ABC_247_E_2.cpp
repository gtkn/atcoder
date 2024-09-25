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
#define watch(x) cerr << (#x) << " is " << (x) << endl
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
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


ll op_max(ll a,ll b){
    return max(a,b);
}
ll ee_max(){
    return -llINF;
}

ll op_min(ll a,ll b){
    return min(a,b);
}
ll ee_min(){
    return llINF;
}


void solve(){
    ll N,X,Y;
    cin >> N >> X >> Y;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    segtree<ll,op_max,ee_max> seg_max(A);
    segtree<ll,op_min,ee_min> seg_min(A);


    auto f = [&](ll l, ll r, ll x, ll y)->bool{
        ll maxv = seg_max.prod(l,r);
        ll minv = seg_min.prod(l,r);
        return maxv <= x && minv >= y;
    };


    ll ans = 0;
    rep(i,N){
        rep(d,4){
            ll dx = d&1, dy = d/2;
            ll l=i-1,r=N+1;
            while(r-l>1){
                ll m = (l+r)/2;
                if(f(i,m,X-dx,Y+dy)) l = m;
                else r = m;
            }
            // cerr << i << " " << l << " " << dx << " " << dy << endl;
            if(dx==dy) ans += l-i;
            else ans -= l-i;
        }
    }

    cout << ans << endl;


}


void solve2(){
    ll N,X,Y;
    cin >> N >> X >> Y;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    ll lx0=-1, lx1=-1, ly0=-1, ly1=-1;
    ll ans = 0;
    rep(i,N){
        if(A[i]>X){
            lx1 = i;
        }else if(A[i]==X){
            lx0 = i;
        }
        if(A[i]<Y){
            ly1 = i;
        }else if(A[i]==Y){
            ly0 = i;
        }

        ll tmp = min(lx0,ly0) - max(lx1,ly1);
        ans += max(tmp,0LL);


    }
    cout << ans << endl;

}

int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        // solve();
        solve2();
    }
    return 0;
}
