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


vec(Pll) rangeMerge_cl(vec(Pll) v){
    // 閉区間[l,r]の集合vを受け取ってマージする
    vec(Pll) res;
    if(v.empty()) return res;

    sort(all(v));
    res.push_back(v[0]);
    for(Pll vi:v){
        if(res.back().first <= vi.first && vi.first <= res.back().second){
            chmax(res.back().second, vi.second);
        }else{
            res.push_back(vi);
        }
    }
    return res;
}


struct edge{
    ll l,r,q,c;
    edge(ll l=0, ll r=0, ll q=0, ll c=0):l(l),r(r),q(q),c(c){}

    bool operator<(const edge& e) const{
        return c < e.c;
    }
    bool operator>(const edge& e) const{
        return c > e.c;
    }

};




void solve(){
    ll N,Q;
    cin >> N >> Q;

    vec(ll) L(Q),R(Q),C(Q);
    rep(i,Q) cin >> L[i] >> R[i] >> C[i];
    rep(i,Q) L[i]--, R[i]--;


    // dsu uf(N+Q);
    vec(Pll) v(Q);
    rep(i,Q) v[i] = {C[i],i};
    sort(all(v));

    set<ll> st;
    rep(i,N-1) st.insert(i);
    ll ans = 0;

    for(auto [ci,idx]:v){
        ll l = L[idx], r = R[idx];
        ll cnt = 1;
        while(!st.empty()){
            auto it = st.lower_bound(l);
            if(it == st.end() || *it >= r) break;
            st.erase(it);
            cnt++;
        }
        ans += ci * cnt;
    }

    if(!st.empty()) ans = -1;
    cout << ans << endl;








    // vec(Pll) rv(Q);
    // rep(i,Q) rv[i] = {L[i],R[i]};

    // rv = rangeMerge_cl(rv);
    // if(rv.size()!=1) dame;
    // if(rv[0] != Pll(0,N-1)) dame;



    // vvec(ll) lvv(N);
    // vvec(ll) rvv(N+1);
    // rep(i,N) lvv[L[i]].push_back(i);
    // rep(i,N) rvv[R[i]+1].push_back(i);

    // set<Pll> st; // C,i

    // ll ans = 0;
    // vec(bool) used(N);
    // rep(now,N){
    //     for(ll vi:lvv[now]){
    //         st.insert({C[vi],vi});
    //     }
    //     for(ll vi:rvv[now]){
    //         if(!used[vi]) ans += C[vi];
    //         st.erase({C[vi],vi});
    //     }
    //     ans += st.begin()->first;
    //     used[st.begin()->second] = true;
    // }

    // cout << ans << endl;



    // dsu uf(N+Q);


    // vvec(ll) vv(N);
    // rep(i,N) vv[L[i]].push_back(i);


    


    // priority_queue<Pll,vector<Pll>,greater<Pll>> pq; // R,C
    // set<Pll> st; // C,i

    // ll ans = 0;
    // ll now = 0;
    // vec(bool) used(Q);
    // rep(now,N){
    //     while(!pq.empty() && R[pq.top().second] < now){
    //         if(!used[pq.top().second]){
    //             ans += pq.top().first;
    //         }
    //         pq.pop();
    //     }

    //     for(ll vi:vv[now]){
    //         pq.push({R[vi], C[vi]});
    //         st.insert({C[vi],vi});
    //     }

    // }

    // cout << ans << endl;








    // priority_queue<edge,vector<edge>,greater<edge>> pq;
    // // rep(i,Q) pq.push(edge(L[i],R[i],i+N,C[i]));
    // pq.push(edge(L[0],R[0],N,C[0]));

    // while(!pq.empty()){
    //     edge e = pq.top(); pq.pop();
    //     if

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
