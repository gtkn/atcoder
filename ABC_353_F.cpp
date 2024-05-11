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
    ll K;
    cin >> K;
    ll Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    if(K==1){
        cout << abs(Sx-Tx) + abs(Sy-Ty) << endl;
        return;
    }
    auto is_big = [&](ll _x, ll _y){
        return (_x/K + _y/K)&1;
    };

    ll sxx,syy,txx,tyy;
    sxx = Sx/K, syy = Sy/K;
    txx = Tx/K, tyy = Ty/K;

    ll ans = llINF;

    if(!is_big(Sx,Sy) && !is_big(Tx,Ty) && sxx==txx && syy==tyy){
        chmin(ans, abs(Sx-Tx) + abs(Sy-Ty) );
    }


    map<Pll,ll> mps, mpt;

    if(is_big(Sx,Sy)){
        mps[{sxx,syy}] = 0;
    }else{
        ll x = sxx, y = syy;
        mps[{x + 1, y}] = K - Sx%K;
        mps[{x - 1, y}] = Sx%K + 1;
        mps[{x, y + 1}] = K - Sy%K;
        mps[{x, y - 1}] = Sy%K + 1;
    }


    if(is_big(Tx,Ty)){
        mpt[{txx,tyy}] = 0;
    }else{
        ll x = txx, y = tyy;
        mpt[{x + 1, y}] = K - Tx%K;
        mpt[{x - 1, y}] = Tx%K + 1;
        mpt[{x, y + 1}] = K - Ty%K;
        mpt[{x, y - 1}] = Ty%K + 1;
    }

    for(auto [s,cs]: mps)for(auto [t,ct]: mpt){
        ll tmp = cs+ct;
        ll dx = abs(s.first-t.first), dy = abs(s.second-t.second);
        if(K==2){
            tmp += min(dx,dy)*2;
            tmp += abs(dx-dy)/2 * 3;
        }else{
            tmp += max(dx,dy)*2;
        }
        chmin(ans,tmp);
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
