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
#define watch(x) cout << (#x) << " is " << (x) << endl
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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

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
    ll N,M,K;
    cin >> N >> M >> K;

    
    vvec(edge) g(N);
    vec(ll) W(M);
    rep(i,M){
        ll u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v,w,i);
        g[v].emplace_back(u,w,i);
        W[i]=w;
    }


    auto f = [&](const ll b){
        if(__builtin_popcount(b)!=N-1) return ll(-1);
        vec(bool) used(N);
        queue<ll> q;
        q.push(0);
        while(!q.empty()){
            ll now = q.front(); q.pop();
            if(used[now]) continue;
            used[now]=true;
            for(edge e:g[now]){
                if( bit(b,e.idx) ) q.push(e.to);
            }
        }

        ll res = 0;
        rep(i,M) if(bit(b,i)) res += W[i];
        bool isok = true;
        rep(i,N) if(!used[i]) isok=false;

        // cout <<  b << "; " << res << " , " << isok << endl;

        if(!isok) res = -1;

        return res;

    };

    ll ans = llINF;
    rep(pt,(1<<M)){
        
        ll tmp = f(pt);
        // cout << pt <<" , " << tmp << ", "<< tmp%K << endl;
        if(tmp>0) chmin(ans, tmp%K);
    }

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
