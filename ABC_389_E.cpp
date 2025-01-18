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
    ll N,M;
    cin >> N >> M;
    vec(ll) P(N);
    rep(i,N) cin >> P[i];


    auto f = [&](ll th)->Pll{
        ll x = 0;
        ll cnt = 0;
        ll memo = 0;
        rep(i,N){
            ll k = (th+P[i])/(2*P[i]);

            if( (2*k-1)*P[i] == th ){
                k--;
                memo++;
            }
            if(k==0) continue;

            cnt += k;
            if(k>M/k) return {llINF,llINF};
            ll k2 = k*k;
            if(P[i]>M/k2) return {llINF,llINF};
            ll a = P[i]*k2;
            if(x>M-a) return {llINF,llINF};
            x += a;
        }

        while(memo && x+th<=M){
            memo--;
            x += th;
            cnt++;            
        }

        return {x,cnt};
    };




    ll l = 0, r = 1e18;
    while(r-l>1){
        ll mid = (l+r)/2;
        auto [x,_cnt] = f(mid);
        // cerr << "mid : " << mid << " x : " << x <<  " cnt : " << _cnt << endl;
        if(x<=M) l = mid;
        else r = mid;
    }

    auto [x,cnt] = f(l);
    cout << cnt << endl;

    // cerr << cnt*cnt*P[0] << endl;
    // cnt++;
    // cerr << cnt*cnt*P[0] << endl;



    // // auto f = [](ll x){
    // //     return x * (x + 1) * (2 * x + 1) / 6;
    // // };

    // vec(ll) cnt(N);

    // auto f = [&](ll idx)->ll{
    //     ll n = cnt[idx]+1;
    //     return P[idx]*n*n;
    // };

    // priority_queue<Pll, vector<Pll>, greater<Pll>> pq; // cost, index
    // rep(i,N) pq.emplace(f(i),i);

    // ll ans = 0;
    // while(M){
    //     auto [c,ii] = pq.top(); pq.pop();
    //     if(c>M) break;
    //     M -= c;
    //     cnt[ii]++;
    //     ans++;
    //     pq.emplace(f(ii),ii);
    // }

    // cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
