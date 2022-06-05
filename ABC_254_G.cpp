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

ll op(ll a,ll b){return max(a,b);};
ll ee(){return 0;};


struct Solver{
 
    void solve(){
        ll N,M,Q;
        cin >> N >> M >> Q;

        vvec(Pll) vv(N+1);
        rep(_,M){
            ll a,b,c;
            cin >> a >> b >> c;
            vv[a].emplace_back(b,c);
            vv[0].emplace_back(b,c);
        }

        rep(i,N+1) sort(all(vv[i]));
        
        vvec(ll) vb(N+1),vc(N+1);
        rep(i,N+1){
            for(Pll x:vv[i]){
                vb[i].push_back(x.first);
                vc[i].push_back(x.second);
            }
        }

        vector< segtree<ll,op,ee> > vsl(N+1);
        rep(i,N+1) vsl[i] = vc[i];

        auto f=[&](ll st,ll a){
            auto itr = upper_bound(all(vb[a]),st);
            return vsl[a].prod(0,*itr);
        };

        while(Q--){
            ll x,y,z,w;
            if(y>w){
                swap(x,z);
                swap(y,w);
            }

            





        }




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
