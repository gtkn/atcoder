//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (int i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目
#define vec(T) vector<T>
#define vvec(T) vector<vector<T>>
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
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

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };
 
 
    vec(int) dh = {1,-1,-1,1};
    vec(int) dw = {1,1,-1,-1};
 
    void solve(){
        ll N;
        cin >> N;
        ll ax,ay,bx,by;
        cin >> ax >> ay;
        cin >> bx >> by;
        ax--;ay--;bx--;by--;


        vvec(bool) vv(N,vec(bool)(N));
        rep(i,N){
            string s;
            cin >> s;
            rep(j,N) vv[i][j]=(s[j]=='#');
        }

        vvec(ll) dp(N,vec(ll)(N,llINF));
        queue<Pll> q;
        auto qpush = [&](ll x,ll y,ll c){
            if(x<0 || x>=N || y<0 || y>=N) return false;
            if(vv[x][y]) return false;
            if(dp[x][y]==c) return true;
            if(chmin(dp[x][y],c)){
                q.emplace(x,y);
                return true;
            }
            return false;
        };
        qpush(ax,ay,0);

        while(!q.empty()){
            ll x0,y0;
            x0 = q.front().first;
            y0 = q.front().second;
            q.pop();
            ll c1 = dp[x0][y0]+1;
            //cout << x0 << ", " << y0 << " : " << c1 << endl;
            rep(di,4){
                rep1(d,N){
                    ll x1,y1;
                    x1 = x0 + dh[di]*d;
                    y1 = y0 + dw[di]*d;
                    if(!qpush(x1,y1,c1)) break;
                }
            }
        }

        ll ans = dp[bx][by];
        if(ans==llINF) ans=-1;
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
