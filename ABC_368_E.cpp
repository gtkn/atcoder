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

struct edge{
    ll to,s,t;
    edge(ll to=0, ll s=0, ll t=0):to(to),s(s),t(t){}
};


void solve(){
    ll N,M,X1; 
    cin >> N >> M >> X1;
    
    vec(ll) A(M+1),B(M+1),S(M+1),T(M+1);
    rep1(i,M) cin >> A[i] >> B[i] >> S[i] >> T[i];
    // rep(i,M) A[i]--, B[i]--;

    vec(ll) X(M+1);
    X[1] = X1;
    
    vec(Pll) e;
    rep1(i,M) e.emplace_back(S[i],i);
    rep1(i,M) e.emplace_back(T[i],-i);

    sort(all(e));
    vec(ll) v(N+1);

    for(auto [x,idx]:e){
        if(idx<0){
            idx = -idx;
            chmax(v[B[idx]], T[idx] + X[idx]);
        }else{
            chmax(X[idx], v[A[idx]] - S[idx]);
        }
    }

    for(ll i=2; i<=M; i++) cout << X[i] << " "; cout << endl;








    // vvec(Pll) vv(N);
    // rep(i,M) vv[A[i]].emplace_back(S[i],i);
    // rep(i,N) sort(all(vv[i]), greater<Pll>());


    // vec(ll) X(M);

    // priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
    // auto push = [&](ll newt, ll idx)->void{
    //     // cerr << "push " << newt << " " << idx << endl;
    //     ll d = newt - T[idx];
    //     if(chmax(X[idx], d)) pq.emplace(newt,idx);
    // };

    // push(T[0]+X1,0);

    // while(!pq.empty()){
    //     auto [tt,ii] = pq.top(); pq.pop();
    //     // cerr << tt << " " << ii << endl;
    //     if(tt<T[ii]+X[ii]) continue;

    //     ll bb = B[ii];
    //     vec(Pll) &v = vv[bb];

    //     while(!v.empty() && v.back().first < T[ii]) v.pop_back();

    //     ll n = v.size();
    //     repr(k,n){
    //         auto [ss,jj] = v[k];
    //         if(ss>=tt) break;

    //         ll dd = tt-ss;
    //         push(T[jj]+dd, jj);
    //     }
    // }


    // rep1(i,M-1) cout << X[i] << " "; cout << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
