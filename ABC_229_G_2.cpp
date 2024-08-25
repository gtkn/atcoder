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
    string S;
    cin >> S;
    ll N = S.size();
    ll K;
    cin >> K;

    vec(ll) cum(N+1);
    rep(i,N){
        cum[i+1] = cum[i] + (S[i]=='Y')*i;
    }
    auto sum([&](ll l,ll r)->ll{
        return cum[r] - cum[l];
    });



    vec(ll) vl,vr;
    rep(i,N) if(S[i]=='Y') vr.push_back(i);
    reverse(all(vr));

    auto f = [&](ll c,ll n)->ll{
        ll a = n/2;
        ll b = n-a;

        if(vl.size() < a || vr.size() < b) return llINF;


        ll ka = 0;
        if(a>0){
            ka = (c-1)*a - sum(vl[vl.size()-a], c) - a*(a-1)/2;
        }
        ll kb = sum(c, vr[vr.size()-b]+1) - c*b - b*(b-1)/2;

        // cerr << "c = " << c << " n = " << n << " a = " << a << " b = " << b << " ka = " << ka << " kb = " << kb << endl;
        return ka+kb;
    };

    // vr.pop_back();
    // vl.push_back(0);
    // cerr << f(1,2) << endl;
    // cerr << f(1,3) << endl;
    // return;


    ll ans = 0;
    rep(i,N){
        // cerr << "i = " << i << endl;
        // cerr << "vl.size() = " << vl.size() << endl;
        // for(ll x:vl) cerr << x << " "; cerr << endl;
        // cerr << "vr.size() = " << vr.size() << endl;
        // for(ll x:vr) cerr << x << " "; cerr << endl;



        ll l = 0, r = N+1;
        while(r-l>1){
            ll m = (l+r)/2;
            if(f(i,m) <= K) l = m;
            else r = m;
        }
        // cerr << i << " " << l << " " << f(i,l) << endl;
        chmax(ans,l);

        if(!vr.empty() && vr.back()==i){
            vr.pop_back();
            vl.push_back(i);
        }
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
