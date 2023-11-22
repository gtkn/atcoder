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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};


ll cum[11][11][11][11][11][11];

void solve(){
    ll N;
    cin >> N;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    rep(i0,11)rep(i1,11)rep(i2,11)rep(i3,11)rep(i4,11)rep(i5,11) cum[i0][i1][i2][i3][i4][i5] = 0;

    for(ll ai:A){
        cout << ai << endl;
        ll tmp = ai;
        vec(ll) v(6);
        rep(i,6){
            v[i] = tmp%10;
            tmp/=10;
        }
        cum[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]]++;
    }

    rep1(i0,10)rep1(i1,10)rep1(i2,10)rep1(i3,10)rep1(i4,10)rep1(i5,10){
        rep(b,(1<<6)){
            vec(ll) v = {i0,i1,i2,i3,i4,i5};
            rep(i,6) if(bit(b,i)) v[i]--;
            ll pm = -1;
            if(__builtin_popcount(b)&1) pm = 1;
            cum[i0][i1][i2][i3][i4][i5] += pm*cum[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]];
        }
    }

    ll ans = 0;
    for(ll ai:A){
        ll tmp = ai;
        vec(ll) v(6);
        rep(i,6){
            v[i] = 10-tmp%10;
            tmp/=10;
        }
        ans += cum[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]];

        bool chk = true;
        for(ll vi:v) if(vi<6) chk=false;
        if(chk) ans--;        
    }

    ans/=2;
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
