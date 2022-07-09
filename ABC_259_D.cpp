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
        ll N;
        cin >> N;

        ll sx,sy,tx,ty;
        cin >> sx >> sy >> tx >> ty;

        vvec(ll) vv(N,vec(ll)(3));
        rep(i,N) rep(j,3) cin >> vv[i][j];

        vvec(ll) g(N);
        rep(i,N){
            rep(j,N){
                if(i==j)continue;

                ll dx,dy;
                dx = vv[i][0]-vv[j][0];
                dy = vv[i][1]-vv[j][1];
                ll dd = dx*dx+dy*dy;
                ll r1,r2;
                r1 = vv[i][2]-vv[j][2];
                r2 = vv[i][2]+vv[j][2];
                if( r1*r1 <= dd && dd<=r2*r2 ) g[i].push_back(j);
            }
        }

        ll s=0,t=0;
        rep(i,N){
            ll dx,dy;
            dx = vv[i][0]-sx;
            dy = vv[i][1]-sy;
            if(dx*dx+dy*dy == vv[i][2]*vv[i][2]) s=i;
        }

        rep(i,N){
            ll dx,dy;
            dx = vv[i][0]-tx;
            dy = vv[i][1]-ty;
            if(dx*dx+dy*dy == vv[i][2]*vv[i][2]) t=i;
        }


        vec(bool) used(N);
        queue<ll> q;
        q.push(s);
        used[s]=true;
        while(!q.empty()){
            ll q0 = q.front();
            q.pop();

            for(ll to:g[q0]){
                if(used[to]) continue;
                q.push(to);
                used[to]=true;
            }

        }

        if(used[t]) yn;

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
