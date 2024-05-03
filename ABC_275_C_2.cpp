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
    vec(string) S(9);
    rep(i,9) cin >> S[i];

    vec(Pll) pos;
    rep(i,9)rep(j,9)if(S[i][j]=='#') pos.emplace_back(i,j);
    ll nn = pos.size();

    auto dist2 = [](const Pll& a, const Pll& b){
        return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
    };

    auto is90deg = [&](const Pll& a, const Pll& b, const Pll& c){
        ll x1,y1,x2,y2;
        x1 = a.first-b.first, y1 = a.second-b.second;
        x2 = c.first-b.first, y2 = c.second-b.second;
        return x1*x2 + y1*y2 == 0;
    };

    

    ll ans = 0;
    rep(i1,nn)rep(i2,nn)rep(i3,nn)rep(i4,nn){
        ll w = dist2(pos[i1],pos[i2]);
        if(w == 0) continue;
        if(w != dist2(pos[i2],pos[i3])) continue;
        if(w != dist2(pos[i3],pos[i4])) continue;
        if(w != dist2(pos[i4],pos[i1])) continue;

        if(!is90deg(pos[i1],pos[i2],pos[i3])) continue;
        if(!is90deg(pos[i2],pos[i3],pos[i4])) continue;
        if(!is90deg(pos[i3],pos[i4],pos[i1])) continue;
        if(!is90deg(pos[i4],pos[i1],pos[i2])) continue;

        // cerr << "i1 i2 i3 i4" << endl;  
        // cerr << pos[i1].first << " " << pos[i1].second << endl;
        // cerr << pos[i2].first << " " << pos[i2].second << endl;
        // cerr << pos[i3].first << " " << pos[i3].second << endl;
        // cerr << pos[i4].first << " " << pos[i4].second << endl;

        ans++;
    }

    cout << ans/8 << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
