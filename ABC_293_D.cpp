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

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,M;
        cin >> N >> M;
        vvec(ll) g(N,vec(ll)(2,-1));

        dsu uf(N);

        rep(_,M){
            ll a,c;
            char b,d;
            cin >> a >> b >> c >> d;
            a--; c--;
            ll bb,dd;
            bb = (b=='R' ? 0 : 1); 
            dd = (d=='R' ? 0 : 1); 

            // cout << a << " , " << b << bb << " , " << c << " , " << d << dd << endl;
            g[a][bb] = c;
            g[c][dd] = a;
            uf.merge(a,c);            
        }

        ll X=0, Y=0;
        for(auto grp:uf.groups()){
            bool isc = true;
            // cout << " --- " << endl;
            for(ll a:grp){
                // cout << a << " ; " << g[a][0] << " , " << g[a][1] << endl;
                if(g[a][0]==-1 || g[a][1]==-1) isc = false;
            }
            if(isc) X++;
            else Y++;
        }

        cout << X << " " << Y << endl;




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
