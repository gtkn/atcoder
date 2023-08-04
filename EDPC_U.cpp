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

using ull = unsigned long long;

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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

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
    ll N;
    cin >> N;

    vvec(ll) a(N,vec(ll)(N));
    rep(i,N)rep(j,N) cin >> a[i][j];


    ll nn = (1<<N);
    vec(ll) dp(nn,-llINF);

    auto f =[&](auto f, ll now)->ll{
        if(dp[now]>-llINF) return dp[now];
        
        dp[now] = 0;
        rep(i,N)rep(j,i) if(bit(now,i) && bit(now,j)) dp[now] += a[i][j];

        ll tmp = 0;
        for(ll t = now; t>=0; t--){
            t &= now;
            if(t==now || t==0 ) continue;
            chmax( dp[now], f(f,t) + f(f, t^now) );
        }
        return dp[now];
    };

    ll ans = f( f, nn-1 );
    cout << ans << endl;




    // ll nn = (1<<N);
    // vvec(ll) dp(N+1,vec(ll)(nn,-llINF));

    // dp[0][0] = 0;
    // rep(i,N)rep(j,nn){
    //     ll tmp = 0;
    //     rep(k,i) if(bit(j,k)) tmp += a[i][k];
    //     ll jj = j | (1<<i);
    //     chmax(dp[i+1][jj], dp[i][j]+tmp);
    //     jj ^= (2<<i)-1;
    //     chmax(dp[i+1][!jj], dp[i][j]+tmp);
    // }

    // ll ans = 0;
    // rep(j,nn) chmax(ans,dp[N][j]);
    // cout << ans << endl;



    // ll ans = 0;
    // vvec(ll) vv;

    // auto f = [&](auto f,ll now, ll score)->void{
    //     // cout << now << " ; " << score << endl;
    //     if(now==N){
    //         chmax(ans,score);
    //         return;
    //     }

    //     vv.push_back({});
    //     rep(i,vv.size()){
    //         ll tmp = 0;
    //         for(ll x:vv[i]) tmp += a[x][now];
    //         vv[i].push_back(now);
    //         f(f, now+1, score+tmp);
    //         vv[i].pop_back();
    //     }
    //     vv.pop_back();
    // };

    // f(f,0,0);
    // cout << ans << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
