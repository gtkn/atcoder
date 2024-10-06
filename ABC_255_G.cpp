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


void solve(){
    ll N,M;
    cin >> N >> M;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];
    vec(ll) X(M),Y(M);
    rep(i,M) cin >> X[i] >> Y[i];

    map<ll,vector<ll>> ngs;
    rep(i,M){
        ngs[X[i]].push_back(X[i]-Y[i]);
    }

    vec(ll) xs,gs;
    map<ll,ll> cnt;
    auto f = [&](ll x){
        ll i = lower_bound(all(xs),x) - xs.begin();
        if(i < xs.size() && xs[i] == x) return gs[i];
        return x-i;
    };
    for(auto [x,ys]:ngs){
        map<ll,ll> mp;
        for(ll y:ys) mp[f(y)]++;
        for(auto [g,num]:mp){
            if(cnt[g]+1 == num){
                xs.push_back(x);
                gs.push_back(g);
                cnt[g]++;
                break;
            }            
        }
    }

    ll tot = 0;
    rep(i,N) tot ^= f(A[i]);
    if(tot==0) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
