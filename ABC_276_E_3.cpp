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
using mint = modint998244353;
// using mint = modint;
// mint::set_mod(P);


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
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


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll H,W;
    cin >> H >> W;
    vec(string) C(H);
    rep(i,H) cin >> C[i];


    ll sh,sw;
    vvec(bool) vv(H,vec(bool)(W,false));

    rep(i,H)rep(j,W){
        if(C[i][j]=='S') sh=i,sw=j;
        if(C[i][j]=='#') vv[i][j]=true;
    }

    vec(Pll) gpos;
    for(auto [dh,dw]:dhw){
        ll nh=sh+dh,nw=sw+dw;
        if(nh<0||nh>=H||nw<0||nw>=W) continue;
        if(vv[nh][nw]) continue;
        gpos.push_back({nh,nw});
    }


    vv[sh][sw]=true;

    for(auto [h0,w0]:gpos){

        vvec(ll) dist(H,vec(ll)(W,llINF));
        queue<Pll> q;
        auto push = [&](ll h,ll w,ll d){
            if(h<0||h>=H||w<0||w>=W) return;
            if(vv[h][w]) return;
            if(chmin(dist[h][w],d)) q.push({h,w});
        };
        push(h0,w0,0);

        while(!q.empty()){
            auto [h,w]=q.front(); q.pop();
            ll d=dist[h][w];
            for(auto [dh,dw]:dhw){
                push(h+dh,w+dw,d+1);
            }
        }

        for(auto [h1,w1]:gpos){
            if(dist[h1][w1]==llINF) continue;
            if(h1==h0&&w1==w0) continue;
            sayyes;
        }
    }

    sayno;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}