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
    ll N, M;
    cin >> N >> M;

    vvec(Pll) g(N);
    rep(_,M){
        ll a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b,c);
        // g[b].emplace_back(a,c);
    }

    
    vec(bool) used(N),cand(N);
    cand[N-1]=true;

    auto f = [&](auto f,ll now)->bool{
        if(used[now]) return cand[now];
        used[now] = true;

        for(auto [nxt,_]: g[now]) if(f(f,nxt)) cand[now] = true;
        return cand[now];
    };
    f(f,0);




    vec(ll) dp(N,-llINF);
    dp[0]=0;

    rep(i,N){
        bool chk = false;
        rep(now,N) for(auto [nxt,c]: g[now]){
            // if(dp[now]==-llINF)continue;
            if(chmax(dp[nxt], dp[now]+c)) if(cand[nxt]) chk=true;
        }
        if(i==N-1 && chk){
            cout << "inf" << endl;
            return;
        }
    }    
    cout << dp[N-1] << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
