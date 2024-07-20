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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;



    auto f = [](ll kk)->ll{
        if(kk==1){
            return 10;
        }
        ll res = 9;
        ll n = kk/2 - 1;
        if(kk&1) n++;
        rep(_,n) res *= 10;
        return res;
    };

    auto f2 = [](ll kk, ll x)->string{
        if(kk==1){
            return to_string(x-1);
        }
        if(kk&1){
            ll n = kk/2;
            ll a = 1;
            rep(_,n) a *= 10;
            a += x-1;
            string s = to_string(a);
            string t = s;
            t.pop_back();
            reverse(all(t));
            return s+t;
        }else{
            ll n = kk/2;
            ll a = 1;
            rep(_,n-1) a *= 10;
            a += x-1;
            string s = to_string(a);
            string t = s;
            reverse(all(t));
            return s+t;
        }
    };


    ll k = 1;
    while(N){
        ll nn = f(k);
        // cerr << k << " " << nn << " " << N << endl;

        if(N<=nn){
            cout << f2(k,N) << endl;
            return;
        }
        N -= nn;
        k++;

    }




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
