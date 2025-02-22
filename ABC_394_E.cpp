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

    vec(string) C(N);
    rep(i,N) cin >> C[i];

    vvec(ll) vv(N,vec(ll)(N,-1));
    rep(i,N)rep(j,N){
        if(C[i][j]=='-') continue;
        vv[i][j] = C[i][j]-'a';
    }

    // rep(i,N){
    //     rep(j,N) cerr << vv[i][j] << " "; cerr << endl;
    // }

    ll M = 26;

    vvec(ll) ans(N,vec(ll)(N,llINF));
    priority_queue<tri,vector<tri>, greater<tri>> pq;
    auto push = [&](ll c, ll i, ll j)->void{
        if(chmin(ans[i][j],c)) pq.push({c,i,j});
    };
    rep(i,N) push(0,i,i);
    rep(i,N)rep(j,N) if(vv[i][j]!=-1) push(1,i,j);

    while(!pq.empty()){
        auto [c,i,j] = pq.top();
        // cerr << c << " " << i << " " << j << endl;
        pq.pop();
        if(ans[i][j] < c) continue;

        vvec(ll) a(M),b(M);
        rep(k,N) if(vv[k][i]!=-1) a[vv[k][i]].push_back(k);
        rep(k,N) if(vv[j][k]!=-1) b[vv[j][k]].push_back(k);

        rep(k,M)for(ll ii:a[k])for(ll jj:b[k]){
            push(c+2,ii,jj);
        }
    }

    rep(i,N)rep(j,N) if(ans[i][j]>=llINF) ans[i][j] = -1;

    rep(i,N){

        rep(j,N) cout << ans[i][j] << " "; cout << endl;
    }


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
