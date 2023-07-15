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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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

 
 
    vec(ll) dh = {1,0,-1,0};
    vec(ll) dw = {0,1,0,-1};
 
    void solve(){
        ll N,T,M;
        cin >> N >> T >> M;

        vvec(bool) vv(N,vec(bool)(N));
        rep(_,M){
            ll a,b; cin >> a >> b;
            --a;--b;
            vv[a][b]=true;
            vv[b][a]=true;
        }


        ll ans = 0;
        vvec(ll) tm;

        auto f = [&](auto f, ll now)->void{
            ll nn = tm.size();
            if(now==N){
                // cout << "----" << ans << "----" << endl;
                // rep(i,nn){
                //     cout << i << " : "; 
                //     for(ll x:tm[i]) cout << x << " ,"; cout << endl;
                // }

                if(nn==T) ans++;
                return;
            }
            if(nn>T) return;

            rep(i,nn){
                bool isok=true;
                for(ll x:tm[i]) if(vv[x][now]) isok=false;
                if(!isok) continue;

                tm[i].push_back(now);
                f(f,now+1);
                tm[i].pop_back();
            }
            tm.push_back({now});
            f(f,now+1);
            tm.pop_back();

            return;
        };

        f(f,0);
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
