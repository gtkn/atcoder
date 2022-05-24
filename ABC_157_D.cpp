//title
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (int i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目
#define vec(T) vector<T>
#define vvec(T) vector<vector<T>>
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
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

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };
 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,M,K;
        cin >> N >> M >> K;

        vvec(ll) vv(N);
        dsu d(N);
        rep(i,M+K){
            ll a,b;
            cin >> a >> b;
            a--;b--;
            if(i<M) d.merge(a,b);
            vv[a].push_back(b);
            vv[b].push_back(a);
        }

        vector<set<ll>> vs(N);
        ll cnt = 0;
        vec(ll) v(N);
        for(auto g:d.groups()){
            for(ll x:g){
                vs[cnt].insert(x);
                v[x]=cnt;
            }
            cnt++;
        }

        rep(i,N){
            ll x = v[i];
            ll res = vs[x].size()-1;
            for(ll j:vv[i]) if(vs[x].find(j)!=vs[x].end()) res--;
            cout << res << " ";
        }
        cout << endl;




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
