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

ll op(ll a, ll b){
    return a+b;
}
ll ee(){
    return 0;
}
ll mapping(ll f, ll x){
    return f+x;
}
ll composition(ll f, ll g){
    return f+g;
}
ll id(){
    return 0;
}



void solve(){
    ll N,M,Q;
    cin >> N >> M >> Q;

    vvec(ll) q(Q,vec(ll)(4,-1));
    rep(i,Q){
        ll t;
        cin >> t;
        q[i][0] = t;

        if(t==1){
            rep1(j,3) cin >> q[i][j];
            q[i][1]--;
        }
        if(t==2){
            rep1(j,2) cin >> q[i][j];
            q[i][1]--;
        }
        if(t==3){
            rep1(j,2) cin >> q[i][j];
            q[i][1]--;
            q[i][2]--;
        }
    }

    vec(ll) ans(Q,-1);
    vec(Pll) r(N,{-1,0});
    vvec(Pll) memo(Q);

    rep(i,Q){
        if(q[i][0]==2){
            r[q[i][1]] = {i,q[i][2]};
        }
        if(q[i][0]==3){
            ll idx = r[q[i][1]].first;
            if(idx>=0) memo[idx].emplace_back( i, q[i][2] );
            ans[i] = r[q[i][1]].second;            
        }
    }

    lazy_segtree<ll,op,ee,ll,mapping,composition,id> lseg(M);

    rep(i,Q){
        if(q[i][0]==1){
            lseg.apply(q[i][1],q[i][2],q[i][3]);
        }
        if(q[i][0]==2){
            for(auto [idx,j]: memo[i]){
                ans[idx] -= lseg.get(j);
            }
        }
        if(q[i][0]==3){
            ans[i] += lseg.get(q[i][2]);
        }
    }

    for(ll a:ans) if(a>=0) cout << a << endl; 




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
