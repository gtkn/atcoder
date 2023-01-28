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
        ll N;
        cin >> N;
        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        vvec(ll) g(N);
        rep(i,N){
            string S;
            cin >> S;
            rep(j,N) if(S[j]=='Y') g[i].push_back(j);
        }


        vvec(Pll) dp(N,vec(Pll)(N,{llINF,0}));
        rep(i,N) dp[i][i] = {0,A[i]};
        rep(i,N){
            for(ll j:g[i]) dp[i][j] = {1,A[i]+A[j]};
        }

        rep(k,N){
            rep(i,N)rep(j,N){
                ll dist = dp[i][k].first + dp[k][j].first;
                ll valu = dp[i][k].second + dp[k][j].second - A[k];

                if( dist > dp[i][j].first) continue;
                if( dist == dp[i][j].first and valu <= dp[i][j].second) continue;
                dp[i][j] = {dist, valu};
            }
        }



        ll Q;
        cin >> Q;
        while(Q--){
            ll U,V;
            cin >> U >> V;
            U--; V--;

            if(dp[U][V].first>=llINF){
                cout << "Impossible" << endl;
            }else{
                cout << dp[U][V].first << " " << dp[U][V].second << endl;
            }

            //rep(i,N) cout << dp[i].first << " :" << dp[i].second << endl;


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
