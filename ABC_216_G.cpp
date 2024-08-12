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


struct S{
    ll sz, tot;
    S(ll sz=0, ll tot=0):sz(sz),tot(tot){}
};
struct F{ll k;};

S op(S a, S b){
    return S(a.sz+b.sz,a.tot+b.tot);
}
S ee(){
    return S(0,0); // 初期化時はsz=1にする
}

S mapping(F f, S x){
    if(f.k<0) return x;
    return S(x.sz, f.k*x.sz);
}
F composition(F f, F g){
    if(f.k<0) return g;
    return f;
}
F id(){
    return F{-1};
}



void solve(){
    ll N,M;
    cin >> N >> M;
    vec(ll) L(M),R(M),X(M);
    rep(i,M){
        cin >> L[i] >> R[i] >> X[i];
        --L[i], --R[i];
    }

    // vvec(Pll) vv(N+1);
    // rep(i,M){
    //     vv[R[i]+1].emplace_back(L[i],X[i]);
    // }

    // vec(S) segini(N, S{1,0});
    // lazy_segtree<S,op,ee,F,mapping,composition,id> lseg(segini);

    // rep1(i,N){
    //     sort(all(vv[i]));
    //     for(auto [j,x]:vv[i]){
    //         ll l = j, r = i+1;
    //         while(r-l>1){
    //             ll mid = (l+r)/2;
    //             ll tot = lseg.prod(j,mid).tot + i-mid;
    //             if(tot>=x) l=mid;
    //             else r=mid;
    //         }
    //         // cerr << j << " " << i << " " << x << " " << l << endl;
    //         // rep(i,N) cout << lseg.get(i).tot << " "; cout << endl;
    //         // rep(i,N) cout << lseg.prod(0,i+1).tot << " "; cout << endl;
    //         // cerr << lseg.prod(j,6).tot <<","<< i-6 << endl;
    //         // cerr << lseg.prod(j,7).tot <<","<< i-7 << endl;
            
    //         lseg.apply(l,i,F{1});
    //     }
    // }

    // rep(i,N) cout << lseg.get(i).tot << " "; cout << endl;


    vvec(Pll) g(N+1);
    rep(i,M){
        g[L[i]].emplace_back(R[i]+1, R[i]+1-L[i]-X[i]);
    }
    rep(i,N){
        g[i+1].emplace_back(i,0);
        g[i].emplace_back(i+1,1);
    }

    vec(ll) dist(N+1, llINF);
    priority_queue<Pll, vec(Pll), greater<Pll>> pq;
    auto push = [&](ll v, ll d){
        if(chmin(dist[v],d)) pq.push({d,v});
    };
    push(0,0);

    while(!pq.empty()){
        auto [d,v] = pq.top(); pq.pop();
        if(dist[v]<d) continue;
        for(auto [nv,nd]:g[v]){
            push(nv,d+nd);
        }
    }

    // rep(i,N+1)cerr << dist[i] << " "; cerr << endl;

    vec(ll) ans(N);
    rep(i,N) if(dist[i+1]==dist[i]) ans[i] = 1;
    rep(i,N) cout << ans[i] << " "; cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
