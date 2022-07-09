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

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
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
        ll N,L;
        cin >> N >> L;

        vec(string) w(N);
        rep(i,N) cin >> w[i];

        vec(ll) v(N);
        rep(i,N){
            for(char c:w[i]){
                v[i]<<=1;
                if(c=='1') v[i]+=1;
            }
        }


        ll m8 = (1<<8)-1;

        vvec(ll) vv0(128,vec(ll)(8));
        vvec(ll) vv1(128,vec(ll)(8));
        rep(i,128){
            string s;
            rep(j,7) s += ((bit(i,j)? '1' : '0'));

            rep(j,7){
                string s0,s1;
                s0 = s.substr(7-j,j) + '0';
                s1 = s.substr(7-j,j) + '1';

                bool f = true;
                rep(k,N) if(s0==w[k]) f=false;
                if(f) vv0[i][j] = j+1;

                f = true;
                rep(k,N) if(s1==w[k]) f=false;
                if(f) vv1[i][j] = j+1;
            }
        }

        vvvec(mint) dp(L+1,vvec(mint)(256,vec(mint)(9)));
        dp[0][0][0]=1;
        rep(i,L)rep(j,128)rep(k,7){
            ll x = i & ((1<<j) -1);
            ll x0,x1;
            x0 = x<<1;
            x1 = x0+1;
            x0&=m8;
            x1&=m8;                
            dp[i+1][x0][vv0[j][k]] += dp[i][j][k];
            dp[i+1][x1][vv1[j][k]] += dp[i][j][k];
        }

        mint ans = 0;
        rep(j,128) ans += dp[L][j][0];
        cout << ans.val() << endl;

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
