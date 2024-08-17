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

    vec(ll) X(N),Y(N),C(N);
    rep(i,N) cin >> X[i] >> Y[i] >> C[i];
    rep(i,N) X[i]*=2;
    rep(i,N) Y[i]*=2;

    map<tri,vector<Pll>> mp;
    rep(i,N)rep(j,i){
        ll u = X[i]-X[j];
        ll v = Y[i]-Y[j];
        ll cx = (X[i]+X[j])/2;
        ll cy = (Y[i]+Y[j])/2;
        if(u==0){
            v = 1;
        }else if(v==0){
            u = 1;
        }else{
            if(u<0){
                u = -u;
                v = -v;
            }
            ll g = abs(__gcd(u,v));
            u /= g;
            v /= g;
        }
        ll c = u*cx+v*cy;
        mp[{u,v,c}].emplace_back(i,j);
    }


    ll ans = -1;
    for(auto p:mp){
        map<ll,ll> mp2;
        for(auto [ii,jj]:p.second){
            ll csum = C[ii]+C[jj];
            ll u = X[ii]-X[jj];
            ll v = Y[ii]-Y[jj];
            if(u==0){
                v = 1;
            }else if(v==0){
                u = 1;
            }else{
                if(u<0){
                    u = -u;
                    v = -v;
                }
                ll g = abs(__gcd(u,v));
                u /= g;
                v /= g;
            }
            ll c = -v*X[ii]+u*Y[ii];
            mp2[c] = max(mp2[c],csum);    
        }
        vec(ll) cand;
        for(auto [c,csum]:mp2){
            cand.emplace_back(csum);
        }
        if(cand.size()<2) continue;
        sort(all(cand),greater<ll>());
        chmax(ans,cand[0]+cand[1]);
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
