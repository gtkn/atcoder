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
        ll N,M;
        cin >> N >> M;

        vvec(bool) vv(N,vec(bool)(M+1));

        rep(i,N){
            string S;
            cin >> S;
            rep(j,M) vv[i][j+1] = (S[j]=='1');
        }


        vec(ll) dpf(N,llINF);
        dpf[0]=0;
        rep(i,N){
            rep1(j,M) if(vv[i][j]) chmin(dpf[i+j], dpf[i]+1);
        }

        vec(ll) dpr(N,llINF);
        dpr[N-1]=0;
        repr(i,N){
            rep1(j,M) if(vv[i][j]) chmin(dpr[i], dpr[i+j]+1);
        }


        for(ll k=1; k<=N-2; k++){
            ll ans = llINF;
            for(ll l=k-1; l>=max(0LL,k-M); l--){
                rep1(j,M){
                    if(!vv[l][j]) continue;
                    ll r = l+j;
                    if(r<=k) continue;

                    chmin(ans, dpf[l] + 1 + dpr[r]);
                }
            }
            if(ans==llINF) ans = -1;
            cout << ans << " ";

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
