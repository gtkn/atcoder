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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

//------------------------------------------------

ll op(ll a,ll b){return min(a,b);};
ll e(){return llINF;};


struct Solver{
 
    void solve(){
        ll N;
        cin >> N;

        vec(ll) v(N);
        rep(i,N) cin >> v[i];
        segtree<ll,op,e> seg(v);

        vec(Pll) q;
        rep(i,N) q.emplace_back(v[i],i);
        sort(all(q),[](Pll const& a, Pll const& b){
            if(a.first!=b.first) return a.first > b.first;
            return a.second<b.second;
        });

        map<ll,vector<ll>> mv;
        repr(i,N) mv[v[i]].push_back(i);


        ll ans = 0;
        for(Pll qi:q){
            ll x = seg.prod(0,qi.second);
            if(x<qi.first){
                cout << qi.first << "< " << x << endl;
                ans += qi.first-x;
                seg.set(qi.second, llINF);
                seg.set(mv[x].back() ,llINF);
                mv[x].pop_back();
            }
        }
        cout << ans << endl;

    }
};


int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
