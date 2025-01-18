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
    ll N,M,A,B;
    cin >> N >> M >> A >> B;
    vec(ll) L(M),R(M);
    rep(i,M) cin >> L[i] >> R[i];

    rep(i,M) L[i]--;
    
    rep(i,M){
        if(R[i]-L[i] >= B) sayno;
    }

    // cerr << "ok" << endl;

    if(A==B){
        rep(i,M){
            ll x = (R[i]-1)/A;
            if(A*x >= L[i]) sayno;
        }
        if( (N-1)%A != 0 ) sayno;
        sayyes;
    }

    // cerr << "ok" << endl;

    L.push_back(N);
    R.push_back(N+B-1);


    ll th = 1000;


    vvec(Pll) vv = {{}};
    rep(i,M+1){
        vec(Pll)& v = vv.back();
        if(v.empty()){
            v.push_back({L[i],R[i]});
        }else{
            if(v.back().second + th < L[i]){
                vv.push_back({});
            }
            vv.back().push_back({L[i],R[i]});
        }
    }

    // for(auto v:vv){
    //     cerr << "---" << endl;
    //     for(auto [l,r]:v) cerr << l << " " << r << endl;
    // }



    for(auto v:vv){
        ll st = max(0LL,v[0].first-th);
        ll en = v.back().second+th;
        ll nn = en - st;

        vec(bool) isok(nn,true);
        for(auto p:v){
            ll l = p.first - st;
            ll r = p.second - st;
            for(ll i=l; i<r; i++){
                isok[i] = false;
            }
        }

        vec(bool) dp(nn);
        dp[0] = true;

        rep(i,nn){
            if(!dp[i]) continue;
            for(ll j=i+A; j<=i+B; j++){
                if(j>=nn) break;
                if(isok[j]) dp[j] = true;
            }
        }

        // cerr << st << " " << en << endl;
        // rep(i,nn) cerr << dp[i] << " ";
        // cerr << endl;

        // rep(i,nn) cerr << isok[i] << " ";
        // cerr << endl;
        

        if(!dp[nn-1]) sayno;
    }

    sayyes;










    // ll n = (A-1)/(B-A);
    // ll th = n*A + A;

    // vvec(Pll) vv = {};
    // rep(i,M){
    //     vec(Pll)& v = vv.back();
    //     if(v.empty()){
    //         v.push_back({L[i],R[i]});
    //     }else{
    //         if(v.back().second + th < L[i]){
    //             vv.push_back({});
    //         }
    //         vv.back().push_back({L[i],R[i]});
    //     }
    // }


    // for(auto v:vv){
    //     ll st = max(0LL,v[0].first-B);
    //     ll en = min(N-1,v.back().second+A);
    //     ll nn = en - st;

    //     vec(bool) isok(nn,true);
    //     for(auto p:v){
    //         ll l = p.first - st;
    //         ll r = p.second - st;
    //         for(ll i=l; i<r; i++){
    //             isok[i] = false;
    //         }
    //     }

    //     vec(bool) dp(nn);
    //     rep(i,B) dp[i] = true;

    //     rep(i,nn){
    //         if(!dp[i]) continue;
    //         for(ll j=i+A; j<=i+B; j++){
    //             if(j>=nn) break;
    //             if(isok[j]) dp[j] = true;
    //         }
    //     }
    //     rep(i,A) if(!dp[nn-1-i]) sayno;
    // }

    // sayyes;

















}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
