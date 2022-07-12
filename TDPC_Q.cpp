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


        vvec(bool) vv0(128,vec(bool)(8));
        vvec(bool) vv1(128,vec(bool)(8));
        rep(i,128){
            string s;
            rep(j,7) s += ((bit(i,j)? '1' : '0'));
            
            rep(j,8){
                string s0,s1;
                s0 = '0' + s.substr(0,j);
                s1 = '1' + s.substr(0,j);

                rep(k,N) if(s0==w[k]) vv0[i][j]=true;
                rep(k,N) if(s1==w[k]) vv1[i][j]=true;
            }
        }

        ll m7 = (1<<7)-1;
        ll m8 = (1<<8)-1;


        vvvec(mint) dp(L+1,vvec(mint)(128,vec(mint)(256)));
        dp[0][0][1]=1;
        rep(n,L)rep(i,128)rep(j,256){
            ll ii = (i<<1)&m7;
            ll j0,j1;
            j0 = j1 = j*2;
            rep(k,8) if(bit(j,k) && vv0[i][k]) j0 = j*2+1;
            rep(k,8) if(bit(j,k) && vv1[i][k]) j1 = j*2+1;
            j0 &= m8;
            j1 &= m8;

            dp[n+1][ii][j0] += dp[n][i][j];
            dp[n+1][ii+1][j1] += dp[n][i][j];
        }

        /*
        rep(i,4){
            rep(j,4) cout << vv0[i][j] << " ";cout<<endl;
        }cout << endl;
        rep(i,4){
            rep(j,4) cout << vv1[i][j] << " ";cout<<endl;
        }cout << endl;

        rep(n,L+1){
            rep(i,4){
                rep(j,4) cout << dp[n][i][j].val() << " "; cout<< endl;
            }cout << endl;
        }
        */

        mint ans = 0;
        rep(i,128)for(ll j=1; j<256; j+=2) ans += dp[L][i][j];
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
