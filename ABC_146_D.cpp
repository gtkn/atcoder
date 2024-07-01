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
    ll N;
    cin >> N;
    vvec(Pll) g(N);
    rep(i,N-1){
        ll a,b;
        cin >> a >> b;
        --a,--b;
        g[a].emplace_back(b,i);
        g[b].emplace_back(a,i);    
    }

    vec(ll) ans(N-1,-1);

    auto f = [&](auto f, ll now, ll frm, ll c0)->void{
        ll c = 0;
        for(auto [nxt,idx]:g[now]){
            if(nxt==frm) continue;
            if(c==c0) ++c;
            ans[idx] = c;
            f(f,nxt,now,c);
            ++c;
        }
    };

    f(f,0,0,-1);
    ll K = 0;
    rep(i,N-1) chmax(K,ans[i]);
    cout << K+1 << endl;
    rep(i,N-1) cout << ans[i]+1 << endl;

    // rep(i,N){
    //     set<ll> st;
    //     for(auto [_,idx]:g[i]){
    //         if(st.find(ans[idx])!=st.end()){
    //             cerr << "error" << endl;
    //             cerr << i << " , " << idx <<", "<< ans[idx] << endl;
    //             return;
    //         }
    //         st.insert(ans[idx]);
    //     }
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
