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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

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

void solve(){
    ll N,L,R;
    cin >> N >> L >> R;
    R++;

    


    vec(Pll) v01,v02,v03,v12,v13,v23;

    ll now = L;
    while(now<R){
        ll d = R-now;        
        ll ii = 0;
        ll tmp = now;
        ll two = 1;
        while( !(tmp&1) && now+two*2<=R ){
            tmp >>= 1;
            ii++;
            two *= 2;
        }
        v12.emplace_back(ii,tmp);
    }




    ll now = L;
    while(now<R){
        ll d = R-now;        
        ll ii = 0;
        ll tmp = now;
        ll two = 1;
        while( !(tmp&1) && now+two*2<=R ){
            tmp >>= 1;
            ii++;
            two *= 2;
        }
        v12.emplace_back(ii,tmp);
    }







    // ll now = L;
    // ll ans = 0;
    // while(now<R){
    //     ll d = R-now;
        
    //     ll ii = 0;
    //     ll tmp = now;
    //     ll two = 1;
    //     while( !(tmp&1) && now+two*2<=R ){
    //         tmp >>= 1;
    //         ii++;
    //         two *= 2;
    //     }

    //     cout << "? " << ii << " " << tmp << endl << flush;
    //     ll T;
    //     cin >> T;
    //     ans = (ans+T)%100;

    //     now += two;
    // }

    // cout << "! " << ans << endl << flush;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
