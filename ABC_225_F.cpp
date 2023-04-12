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
    ll N,K;
    vec(string) S;
    string ans;

    vec(bool) used;

    void dfs(string now,ll cnt){
        if(now>ans) return;
        if(cnt==K){
            chmin(ans,now);
            return;
        }

        rep(i,N){
            if(used[i]) continue;
            used[i]=true;
            dfs(now+S[i],cnt+1);
            used[i]=false;
        }

    }


 
    void solve(){
        cin >> N >> K;

        S.resize(N);
        rep(i,N) cin >> S[i];
        // sort(all(S));

        // used.resize(N);

        // ans = "";
        // rep(i,2520) ans+='z';

        // dfs("",0);

        // cout << ans << endl;


        sort(all(S), [](string const& a, string const& b){
            return a+b < b+a;
        });

        string tmp = "";
        rep(i,2520) tmp+='z';
        tmp = ('z'+1);

        vvec(string) dp(N+1,vec(string)(K+1,tmp));

        dp[N][0]="";
        repr(i,N)rep(j,K+1){
            chmin(dp[i][j], dp[i+1][j]);
            if(j>0) chmin(dp[i][j], S[i]+dp[i+1][j-1]);
        }


        ans = dp[0][K];
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
