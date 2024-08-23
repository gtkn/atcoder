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

const ll M = 33;
const ll MM = 33*33;

ll dp[M][M][M][MM];

void solve(){
    string S;
    cin >> S;
    ll K;
    cin >> K;
    ll N = S.size();

    vec(ll) v(N);
    rep(i,N){
        if(S[i]=='K') v[i]=0;
        if(S[i]=='E') v[i]=1;
        if(S[i]=='Y') v[i]=2;
    }

    vec(ll) cnt(3);
    rep(i,N) cnt[v[i]]++;

    vvec(ll) pos(3);
    rep(i,N) pos[v[i]].push_back(i);

    rep(i,M) rep(j,M) rep(k,M) rep(l,MM) dp[i][j][k][l] = 0;
    dp[0][0][0][0] = 1;





    rep(l,N)rep(e,cnt[1]+1)rep(y,cnt[2]+1)rep(c,MM){
        ll k = l-e-y;
        if(k<0) continue;
        if(k>cnt[0]) continue;

        vec(ll) v;
        rep(i,k) v.push_back(pos[0][i]);
        rep(i,e) v.push_back(pos[1][i]);
        rep(i,y) v.push_back(pos[2][i]);
        sort(all(v));

        if(k<cnt[0]){
            ll x = pos[0][k];
            ll d = v.end() - upper_bound(all(v),x);
            ll cc = c + x + d - l;
            if(cc<MM) dp[l+1][e][y][cc] += dp[l][e][y][c];
        }

        if(e<cnt[1]){
            ll x = pos[1][e];
            ll d = v.end() - upper_bound(all(v),x);
            ll cc = c + x + d - l;
            if(cc<MM) dp[l+1][e+1][y][cc] += dp[l][e][y][c];
        }

        if(y<cnt[2]){
            ll x = pos[2][y];
            ll d = v.end() - upper_bound(all(v),x);
            ll cc = c + x + d - l;
            if(cc<MM) dp[l+1][e][y+1][cc] += dp[l][e][y][c];
        }
    }

    ll ans = 0;
    for(ll c=0; c<min(MM,K+1); ++c){
        ans += dp[N][cnt[1]][cnt[2]][c];
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
