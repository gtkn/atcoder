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

double eps = 1e-8;

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
        ll N,M;
        cin >> N >> M;

        vec(ll) s(M),t(M);
        rep(i,M) cin >> s[i] >> t[i];

        vvec(ll) gf(N+1),gr(N+1);
        rep(i,M){
            gf[s[i]].push_back(t[i]);
            gr[t[i]].push_back(s[i]);
        }

        vec(double) dpf(N+1);
        dpf[1] = 1;
        rep1(now,N){
            if(gf[now].empty()) continue;
            double p = 1./gf[now].size();
            for(ll nxt:gf[now]) dpf[nxt] += dpf[now]*p;
        }

        vec(double) dpr(N+1);
        dpr[N] = 0;
        rep1r(now,N){
            if(gf[now].empty()) continue;
            double p = 1./gf[now].size();
            for(ll nxt:gf[now]) dpr[now] += (dpr[nxt]+1)*p;
        }

        double ans = dpr[1];
        // cout << ans << endl;

        rep(i,M){
            double tmp = dpr[1];

            tmp -= dpf[s[i]]*dpr[s[i]];
            ll nn = gf[s[i]].size();
            if(nn==1) continue;
            double p = 1./(nn-1);
            for(ll x:gf[s[i]]){
                if(x!=t[i]) tmp += dpf[s[i]]*p*(dpr[x]+1);
            }

            // cout << tmp << endl;
            if(tmp>eps) chmin(ans,tmp);
        }

        // rep1(i,N) cout << dpf[i] << " "; cout << endl;
        // rep1(i,N) cout << dpr[i] << " "; cout << endl;

        printf("%.8f\r\n",ans);


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
