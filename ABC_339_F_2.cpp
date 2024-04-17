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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


void solve(){

    ll N;
    cin >> N;

    vec(string) A(N);
    rep(i,N) cin >> A[i];

    ll M = 50;

    vec(ll) mods(M);
    rep(i,M) mods[i] = rand() % 1000000000 + 1000000000;
    mods[0] = 1000000007;
    mods[1] = 1000000009;
    mods[2] = 1000000021;
    mods[3] = 1000000033;
    mods[4] = 1000000087;
    mods[5] = 1000000093;
    mods[6] = 1000000097;
    mods[7] = 1000000103;
    mods[8] = 1000000123;
    mods[9] = 1000000181;
    mods[10] = 1000000207;
    mods[11] = 1000000223;
    mods[12] = 1000000241;
    mods[13] = 1000000271;
    mods[14] = 1000000289;
    mods[15] = 1000000297;
    mods[16] = 1000000321;
    mods[17] = 1000000349;
    mods[18] = 1000000369;
    mods[19] = 1000000403;
    mods[20] = 1000000409;


    
    auto f = [](string s, ll mod){
        ll res = 0;
        for(auto c:s){
            res = (res*10 + c - '0') % mod;
        }
        return res;
    };


    vvec(ll) a(N,vec(ll)(M));
    rep(i,N)rep(j,M){
        a[i][j] = f(A[i],mods[j]);
    }

    map<vector<ll>,ll> mp;
    rep(i,N) mp[a[i]]++;

    ll ans = 0;

    rep(i,N)rep(j,N){
        vec(ll) v(M);
        rep(k,M){
            v[k] = (a[i][k] * a[j][k]) % mods[k];
        }
        ans += mp[v];
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
