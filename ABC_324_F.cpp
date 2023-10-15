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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

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


struct abc{
    ll a,b,c;
    abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}

    double get(double x){
        return b-x*c;
    }
};


void solve(){
    ll N, M ;
    cin >> N >> M;

    vvec(abc) g(N);
    rep(_,M){
        ll u,v,b,c;
        cin >> u >> v >> b >> c;
        g[u-1].emplace_back(v-1,b,c);
    }

    
    
    auto chk = [&](double x)->bool{

        vec(double) dp(N,-llINF);
        dp[0]=0;

        rep(i,N){
            for(abc &e:g[i]){
                chmax(dp[e.a], dp[i]+e.get(x));
            }
        }
        return dp[N-1]>=0;
    };
    
    
    
    
    double r = 1e9+10, l=0;
    double eps = 1e-10;
    
    while( abs(r-l) > eps){
        double mid = (r+l)*0.5;
        if(chk(mid)) l=mid;
        else r=mid;
        if(r<l) swap(l,r);
    }

    printf("%.10f\r\n",l);



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
