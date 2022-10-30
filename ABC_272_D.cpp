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
        cin >> N >>M;

        vec(Pll) v;
        for(ll x = 0; x*x<=M; x++){
            ll l=0,r=M;
            ll x2 = x*x;
            while(r-l>1){
                ll m = (l+r)/2;
                if( x2 + m*m <= M ) l=m;
                else r=m;
            }
            if(x2 + l*l != M) continue;
            v.emplace_back(x,l);
            v.emplace_back(x,-l);
            v.emplace_back(-x,l);
            v.emplace_back(-x,-l);

            v.emplace_back(l,x);
            v.emplace_back(l,-x);
            v.emplace_back(-l,x);
            v.emplace_back(-l,-x);

        }


        vvec(ll) dp(N,vec(ll)(N,llINF));
        
        queue<Pll> q;
        auto qpush = [&](ll x,ll y, ll c){
            if(x<0 || x>=N || y<0 || y>=N) return;
            if(chmin(dp[x][y], c)) q.emplace(x,y);            
        };

        qpush(0,0,0);

        while(!q.empty()){
            Pll q0 = q.front();
            q.pop();
            ll x0,y0;
            x0 = q0.first;
            y0 = q0.second;

            for(Pll vi:v){
                qpush(x0 + vi.first, y0+vi.second, dp[x0][y0]+1);
            }
        }

        rep(i,N){
            rep(j,N) cout << ( (dp[i][j]==llINF)? -1 : dp[i][j]  ) << " "; cout << endl;
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
