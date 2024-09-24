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


vec(Pll) dhw = { {1,1},{-1,1},{1,-1},{-1,-1} };

void solve(){
    ll N;
    cin >> N;

    ll Ax,Ay,Bx,By;
    cin >> Ax >> Ay >> Bx >> By;
    Ax--; Ay--; Bx--; By--;

    vvec(bool) w(N,vec(bool)(N));
    rep(i,N){
        string S;
        cin >> S;
        rep(j,N) w[i][j] = (S[j]=='#');
    }

    vvec(ll) dp(N,vec(ll)(N,llINF));
    priority_queue<tri,vector<tri>,greater<tri>> pq;
    auto push = [&](ll c, ll x, ll y)->bool{
        if(x<0||x>=N||y<0||y>=N) return false;
        if(w[x][y]) return false;
        if(chmin(dp[x][y],c)){
            pq.push({c,x,y});
            return true;
        }
        return (dp[x][y]>=c);
    };
    push(0,Ax,Ay);

    while(!pq.empty()){
        auto [c0,x0,y0] = pq.top(); pq.pop();
        if(dp[x0][y0]<c0) continue;

        for(auto [dx,dy]:dhw){
            ll x1 = x0 + dx, y1 = y0 + dy;
            while(push(c0+1,x1,y1)){
                x1 += dx; y1 += dy;
            }
        }
    }

    ll ans = dp[Bx][By];
    if(ans>=llINF) ans = -1;
    cout << ans << endl;

    // rep(i,N){
    //     rep(j,N) cerr << (dp[i][j] >= llINF? -1 : dp[i][j]) << ' '; cerr << endl;
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
