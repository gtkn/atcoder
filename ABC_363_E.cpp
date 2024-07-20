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
#define watch(x) cerr << (#x) << " is " << (x) << endl
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
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll H,W,Y;
    cin >> H >> W >> Y;

    vvec(ll) A(H,vec(ll)(W));
    rep(i,H) rep(j,W) cin >> A[i][j];

    vvec(bool) used(H,vec(bool)(W,false));
    priority_queue<tri,vector<tri>,greater<tri>> pq;

    rep(i,H) pq.emplace(A[i][0],i,0);
    rep(i,H) pq.emplace(A[i][W-1],i,W-1);
    rep(j,W) pq.emplace(A[0][j],0,j);
    rep(j,W) pq.emplace(A[H-1][j],H-1,j);

    ll rem = H*W;

    rep1(y,Y){

        while(!pq.empty()){
            auto [a,i,j] = pq.top();
            if(a>y) break;
            pq.pop();
            if(used[i][j]) continue;
            used[i][j] = true;
            rem--;
            rep(k,4){
                ll ni = i+dh[k], nj = j+dw[k];
                if(ni<0||ni>=H||nj<0||nj>=W) continue;
                if(used[ni][nj]) continue;
                pq.emplace(A[ni][nj],ni,nj);
            }
        }
        cout << rem << endl;
    }





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
