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


Pll op(Pll a, Pll b){
    if(a.first < b.first) return a;
    if(a.first > b.first) return b;
    if(a.second > b.second) return a;
    return b;
}

Pll e(){
    return {llINF,0};
}

void solve(){
    ll N;
    cin >> N;
    vec(ll) P(N);
    rep(i,N) cin >> P[i];

    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll ans = 0;
    for(ll pi:P){
        if(!pq.empty() && pq.top() < pi){
            ans += pi;
            pq.pop();
    
            pq.push(pi);
            ans -= pi;
        }
        pq.push(pi);
        ans -= pi;
    }
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;



    // vec(Pll) v;
    // rep(i,N) v.push_back({P[i],i});
    // segtree<Pll,op,e> seg(v);
    
    // priority_queue<Pll> pq;
    // rep(i,N) pq.emplace(P[i],i);


    // ll ans = 0;
    // while(!pq.empty()){
    //     auto [p1,i1] = pq.top(); pq.pop();
    //     if(seg.get(i1).first != p1) continue;
    //     auto [p0,i0] = seg.prod(0,i1);
    //     if(p0 >= p1) continue;
    //     ans += p1-p0;
    //     cerr << i0 << " " << p0 << " -> " << i1  <<" " << p1 << endl;
    //     seg.set(i0,{llINF,i0});
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
