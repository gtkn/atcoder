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
constexpr ll llINF = 1LL << 61;
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
    ll N,K;
    cin >> N >> K;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    map<ll,ll> mp;
    for(ll ai:A) mp[ai]++;

    vec(Pll) v;
    v.emplace_back(0,0);
    for(auto p:mp) v.push_back(p);

    sort(all(v));

    ll ans = 0;

    auto f = [&](ll ai, ll aj, ll c){
        ll d = aj - ai;

        if( d <= K/c){
            ans += (ai + aj+1)*d/2*c;
            K -= d*c;
            // cerr << aj << " "<< c << " : " << d << " " << endl;
            return;
        }else{
            ll x = K/c;
            ans += (aj + aj-x+1)*x/2*c;
            K -= x*c;
            ans += (aj-x)*K;
            K = 0;
            // cerr << aj << " "<< x << " ! " << d << " " << endl;
            return;
        }
    };



    while(v.size()>=2){
        auto [a1,c1] = v.back(); v.pop_back();
        auto [a0,c0] = v.back(); v.pop_back();
        f(a0,a1,c1);
        v.emplace_back(a0,c0+c1);
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
