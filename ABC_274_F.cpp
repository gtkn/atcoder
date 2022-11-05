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
        ll N,A;
        cin >> N >> A;

        vec(ll) W(N),X(N),V(N);
        rep(i,N) cin >> W[i] >> X[i] >> V[i];

        ll ans = 0;
        rep(st,N){
            map<double,ll> m;
            m[0]=0;
            ll x = 0;
            rep(i,N){
                if(V[st]==V[i]){
                    ll dx = X[i]-X[st];
                    if(dx>=0 && dx<=A) x+=W[i];
                    continue;
                }

                double t1,t2;
                t1 = -1.*(X[st]-X[i])/(V[st]-V[i]);
                t2 = -1.*(X[st]+A-X[i])/(V[st]-V[i]);
                if(t1>t2) swap(t1,t2);
                if(t2<0) continue;
                chmax(t1,0.);
                m[t1]+=W[i];
                m[t2+1e-10]-=W[i];
            }
            for(auto mi:m){
                x += mi.second;
                chmax(ans,x);         
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
