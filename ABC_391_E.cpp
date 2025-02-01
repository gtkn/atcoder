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
using mint = modint998244353;
// using mint = modint;
// mint::set_mod(P);


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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N;
    cin >> N;
    string A;
    cin >> A;

    vvec(bool) vv(N+1);
    for(char ai:A) vv[0].push_back(ai=='1');

    rep(i,N){
        ll n = vv[i].size();
        rep(j,n/3){
            vec(ll) cnt(2);
            rep(k,3) cnt[vv[i][j*3+k]]++;
            if(cnt[0]>cnt[1]) vv[i+1].push_back(0);
            else vv[i+1].push_back(1);
        }
    }

    if(vv[N][0]){
        rep(i,N+1)rep(j,vv[i].size()) vv[i][j] = !vv[i][j];
    }

    

    auto f = [&](auto f, ll ii, ll jj)->ll{
        if(vv[ii][jj]) return 0;

        if(ii==0){
            if(vv[ii][jj]) return 0;
            else return 1;
        }

        vec(ll) cnt(2),v;
        rep(k,3){
            ll pj = jj*3+k;
            bool val = vv[ii-1][pj];
            cnt[val]++;
            if(!val) v.push_back(f(f, ii-1,pj));
        }

        sort(all(v));
        ll res = v[0];
        if(cnt[1]==0) res += v[1];
        return res;
    };

    ll ans = f(f,N,0);
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
