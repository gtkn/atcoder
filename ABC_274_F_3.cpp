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
using Pdl = pair<double,ll>;
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
    ll N,A;
    cin >> N >> A;

    vec(ll) W(N),X(N),V(N);
    rep(i,N) cin >> W[i] >> X[i] >> V[i];



    auto make_events = [&](ll k)->vec(Pdl){
        vec(Pdl) res;

        rep(i,N){
            if(V[k]==V[i]){
                if(X[k] <= X[i] && X[i] <= X[k]+A ){
                    res.emplace_back(-1., W[i]);
                }
                continue;
            }

            
            double t1 = (double)(X[i] - X[k]) / (V[k] - V[i]);
            double t2 = (double)(X[i] - X[k]-A) / (V[k] - V[i]);

            if(t1 > t2) swap(t1,t2);
            if(t2 < 0) continue;
            res.emplace_back(t1,W[i]);
            res.emplace_back(t2,-W[i]);

        }

        sort(all(res),[](const Pdl& a, const Pdl& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        return res;
    };


    ll ans = 0;

    rep(ii,N){
        auto events = make_events(ii);
        ll sum = 0;
        for(auto [t,w] : events){
            sum += w;
            chmax(ans,sum);
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
