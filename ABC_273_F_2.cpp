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
    ll N,X;
    cin >> N >> X;
    vec(ll) Y(N),Z(N);
    rep(i,N) cin >> Y[i];
    rep(i,N) cin >> Z[i];

    ll nn = 2*N + 2;
    vec(ll) pos;
    rep(i,N) pos.push_back(Y[i]);
    rep(i,N) pos.push_back(Z[i]);
    pos.push_back(0);
    pos.push_back(X);

    sort(all(pos));
    map<ll,ll> mp;
    rep(i,nn) mp[pos[i]] = i;

    vec(bool) iswall(nn);
    rep(i,N) iswall[mp[Y[i]]] = true;




    vec(Pll) v;
    rep(i,N) v.emplace_back(mp[Y[i]],mp[Z[i]]);
    v.emplace_back(mp[X],0);
    v.emplace_back(-llINF,0);
    v.emplace_back(llINF,0);
    sort(all(v));

    

    ll xx = mp[X];


    auto fr = [&](ll now)->Pll{
        return *upper_bound(all(v),Pll(now,llINF));
    };

    auto fl = [&](ll now)->Pll{
        return *--lower_bound(all(v),Pll(now,-llINF));
    };

    auto dist = [&](ll idx,ll jdx)->ll{
        return abs(pos[jdx] - pos[idx]);
    };


    ll ans = llINF;
    vvvec(ll) dp(nn,vvec(ll)(nn,vec(ll)(2,llINF)));

    ll zz = mp[0];
    dp[zz][zz][0] = 0;
    dp[zz][zz][1] = 0;


    repr(l,nn)for(ll r=l; r<nn; r++){
        if(l>0){
            ll l2 = l-1;
            if(iswall[l2]){
                auto [w,h] = fl(l);
                if(abs(w)!=llINF && l<=h && h<=r){
                    chmin(dp[l2][r][0],dp[l][r][0]+dist(l2,l));
                    chmin(dp[l2][r][0],dp[l][r][1]+dist(l2,r));
                }
            }else{
                chmin(dp[l2][r][0],dp[l][r][0]+dist(l2,l));
                chmin(dp[l2][r][0],dp[l][r][1]+dist(l2,r));
            }
        }
        if(r+1<nn){
            ll r2 = r+1;
            if(iswall[r2]){
                auto [w,h] = fr(r);
                if(abs(w)!=llINF && l<=h && h<=r){
                    chmin(dp[l][r2][1],dp[l][r][0]+dist(l,r2));
                    chmin(dp[l][r2][1],dp[l][r][1]+dist(r,r2));
                }
            }else{
                chmin(dp[l][r2][1],dp[l][r][0]+dist(l,r2));
                chmin(dp[l][r2][1],dp[l][r][1]+dist(r,r2));
            }
        }
    }

    rep(l,nn)for(ll r=l; r<nn; r++){
        if(l<=xx && xx<=r){
            chmin(ans,dp[l][r][0]);
            chmin(ans,dp[l][r][1]);
        }
    }



    // rep(l,nn){
    //     // for(ll r=l; r<nn; r++) cerr << l << ' ' << r << " : " << dp[l][r][0] << ' ' << dp[l][r][1] << endl;
    //     for(ll r=l; r<nn; r++) cerr << pos[l] << ' ' << pos[r] << " : " << dp[l][r][0] << ' ' << dp[l][r][1] << endl;
    // }

    if(ans == llINF) ans = -1;
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
