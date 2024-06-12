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


struct state{
    ll c,x,y,d;
    state(ll c=0, ll x=0, ll y=0, ll d=0):c(c),x(x),y(y),d(d){}
};


void solve(){
    ll N;
    cin >> N;
    ll Ax,Ay,Bx,By;
    cin >> Ax >> Ay >> Bx >> By;
    Ax--; Ay--; Bx--; By--;

    vvec(bool) S(N,vec(bool)(N));
    rep(i,N){
        string si; cin >> si;
        rep(j,N) S[i][j] = (si[j]=='#');
    }

    vec(Pll) dd = { {1,1}, {1,-1}, {-1,1}, {-1,-1} };

    vvvec(ll) dp(N,vvec(ll)(N,vec(ll)(4,llINF)));
    queue<state> q; // c,x,y,d
    
    auto qpush = [&](ll c, ll x, ll y, ll d)->void{
        if(x<0 || x>=N || y<0 || y>=N) return;
        if(S[x][y]) return;
        if (chmin(dp[x][y][d],c)){
            q.emplace(c,x,y,d);
        }
    };

    rep(k,4) qpush(1,Ax,Ay,k);

    while(!q.empty()){
        auto [c,x,y,d] = q.front(); q.pop();
        if(dp[x][y][d]<c) continue;

        rep(k,4){
            auto [dx,dy] = dd[k];
            ll nx = x+dx, ny = y+dy;
            ll nc = c+(k!=d);
            qpush(nc,nx,ny,k);
        }
    }


    ll ans = llINF;
    rep(k,4) chmin(ans,dp[Bx][By][k]);
    if(ans>=llINF) ans = -1;
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
