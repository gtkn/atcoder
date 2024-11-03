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
// using mint = modint998244353;
using mint = modint;


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


void solve(){
    ll P,A,B,S,G;
    cin >> P >> A >> B >> S >> G;

    mint::set_mod(P);

    mint s = S, g = G;


    if(A==0){
        ll ans = -1;
        if(S==G){
            ans = 0;
        }else if(B==G){
            ans = 1;
        }
        cout << ans << endl;
        return;
    }


    auto f = [&](mint x, ll n)->mint{
        mint an = mint(A).pow(n);
        mint c = n;
        if(A!=1) c = (an-1)/(A-1);
        return x*an + c*B;
    };




    ll M = sqrt(P);
    // cerr << M << "---" << endl;

    {
        mint now = s;
        rep(i,M){
            // cerr << i << " " << now.val() <<" : " << g.val() << endl;
            if(now==g){
                cout << i << endl;
                return;
            }
            now = now*A+B;
        }
    }


    map<ll,ll> mp;
    {
        mint now = g;
        rep(i,M){
            mp[now.val()] = i;
            // cerr << i << " " << now.val() << endl;
            now = now*A+B;
        }        
    }


    rep1(i,M+1){
        mint x0 = f(s,i*M);
        if(mp.find(x0.val())!=mp.end()){
            ll res = i*M - mp[x0.val()];
            // cerr << i << " " << x0.val() << " : " << mp[x0.val()] << endl;
            cout << res << endl;
            return;
        }
    }
    dame;




    // if(A==1){
    //     ll ans = G-S;
    //     if(G<S) ans += P;
    //     cout << ans << endl;
    //     return;
    // }



    // vec(ll) gs;
    // {
    //     ll now = G;
    //     rep(_,M){
    //         gs.push_back(now);
    //         now = (now*A+B)%P;
    //     }
    // }
    // map<ll,ll> mp;
    // for(ll x:gs) mp[x]++;
    // bool smallloop = false;
    // for(auto p:mp){
    //     if(p.second>=2){
    //         smallloop = true;
    //         break;
    //     }
    // }

    // if(smallloop){
    //     ll now = S;
    //     ll ans = 0;
    //     while(now!=G){
    //         now = (now*A+B)%P;
    //         ans++;
    //     }
    //     cout << ans << endl;
    //     return;
    // }

    





}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
