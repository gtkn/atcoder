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
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    ll ans = 0;

    vec(ll) b = A;
    sort(all(b));
    rep(_,2){
        ans += b.back();
        b.pop_back();
    }


    ll nn = N-2;
    vec(ll) d(nn,1);

    auto f = [&](ll ii)->ll{
        ll di = d[ii];
        ll res = 0;
        res -= di*di*b[ii];
        di++;
        res += di*di*b[ii];
        return res;
    };


    priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
    rep(i,nn) pq.emplace(f(i),i);

    rep(_,N-2){
        auto [ci,ii] = pq.top(); pq.pop();
        d[ii]++;
        pq.emplace(f(ii),ii);
    }

    rep(i,nn) ans += d[i]*d[i]*b[i];
    cout << ans << endl;




    // vec(ll) d(N);
    // dsu uf(N);


    // auto f = [&](ll ii)->ll{
    //     ll res = 0;
    //     ll di = d[ii];
    //     res -= di*di*A[ii];
    //     di++;
    //     res += di*di*A[ii];
    //     return res;
    // };

    // vvec(Pll) vv(N);
    // // rep(i,N) vv[i].push_back(f(i),i);


    // priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
    // rep(i,N) pq.emplace(f(i),i);

    


    // ll ans = 0;
    // rep(_,N-1){
    //     auto [ci,ii] = pq.top(); pq.pop();
    //     auto [cj,jj] = pq.top(); pq.pop();

    //     uf.merge(ii,jj);
    //     ans += ci+cj;
    //     d[ii]++;
    //     d[jj]++;

        

    // }
    



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
