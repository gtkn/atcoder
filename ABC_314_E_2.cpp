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
constexpr ll llINF = 1LL << 60;
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
    ll N,M;
    cin >> N >> M;

    vec(ll) C(N), P(N);
    vvec(ll) S(N);

    rep(i,N){
        cin >> C[i] >> P[i];
        S[i].resize(P[i]);
        rep(j,P[i]) cin >> S[i][j];
    }


    vec(double) prob(N);
    rep(i,N) prob[i]=1./P[i];

    vec(double) dp_c(210,llINF),dp_p(210);
    for(ll i=M; i<210; i++) dp_c[i]=0;
    for(ll i=M; i<210; i++) dp_p[i]=1;

    repr(now,M){
        rep(i,N){
            double tmp_c = 0, tmp_p = 0;
            ll z = 0;
            for(ll s:S[i]){
                if(s==0){
                    z++;
                    continue;
                }
                ll nxt = now + s;
                tmp_c += prob[i]*dp_c[nxt] + prob[i]*C[i]*dp_p[nxt];
                tmp_p += prob[i]*dp_p[nxt];
            }
            tmp_p *= 1.*P[i]/(P[i]-z);
            tmp_c += prob[i]*C[i]*tmp_p*z;
            tmp_c *= 1.*P[i]/(P[i]-z);

            if(chmin(dp_c[now],tmp_c)) dp_p[now]=tmp_p;
        }
    }


    printf("%.10f\n",dp_c[0]);



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
