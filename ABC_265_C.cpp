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

 
 
    vec(int) dh = {-1,1,0,0};
    vec(int) dw = {0,0,-1,1};
 
    void solve(){
        ll H,W;
        cin >> H >> W;

        map<char,ll> m;
        m['U'] = 0;
        m['D'] = 1;
        m['L'] = 2;
        m['R'] = 3;


        vvec(ll) vv(H,vec(ll)(W));
        rep(i,H){
            string s;
            cin >> s;
            rep(j,W) vv[i][j] = m[s[j]];
        }

        vvec(bool) dp(H,vec(bool)(W));

        ll h=0,w=0;
        bool chk = false;
        
        while(1){
            dp[h][w]=true;
            ll x = vv[h][w];
            ll hh,ww;
            hh = h+dh[x];
            ww = w+dw[x];
            if(hh >=0 && hh<H && ww >=0 && ww<W){
                if(dp[hh][ww]){
                    chk=true;
                    break;
                }
                h=hh;
                w=ww;
            }else{
                break;
            }
        }

        if(chk) cout << -1 << endl;
        else cout << h+1 << " " << w+1 << endl;

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
