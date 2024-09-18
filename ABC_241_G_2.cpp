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
//using mint = modint998244353;


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
    ll N,M;
    cin >> N >> M;

    vec(ll) W(M),L(M);
    rep(i,M) cin >> W[i] >> L[i];
    rep(i,M) W[i]--, L[i]--;

    vec(ll) ans;
    rep(idx,N){
        vvec(ll) vv(N,vec(ll)(N));
        rep(i,N) vv[i][i] = -llINF;
        rep(i,M){
            vv[W[i]][L[i]] = 1;
            vv[L[i]][W[i]] = -1;
        }
        // if(idx==3){
        //     rep(i,N){
        //         rep(j,N) cerr << vv[i][j] << " ";
        //         cerr << endl;
        //     }
        // }


        rep(i,N){
            if(vv[idx][i]!=0) continue;
            vv[idx][i] = 1;
            vv[i][idx] = -1;
        }


        vec(ll) win(N);
        rep(i,N)rep(j,N) if(vv[i][j]==1) win[i]++;


        // if(idx==3){
        //     rep(i,N){
        //         cerr << win[i] << " : ";
        //         rep(j,N) cerr << vv[i][j] << " ";
        //         cerr << endl;
        //     }
        // }



        bool isok = true;
        rep(i,N)if(i!=idx && win[idx]<=win[i]) isok = false;
        if(!isok) continue;


        vvec(ll) memo(N);
        ll cnt = 0;
        rep(i,N)rep(j,i){
            if(vv[i][j]!=0) continue;
            memo[i].push_back(cnt);
            memo[j].push_back(cnt);
            cnt++;
        }

        ll st = N+cnt, gl = st+1;
        mf_graph<ll> g(gl+1);
        rep(i,N)if(i!=idx) g.add_edge(st,i,win[idx]-win[i]-1);
        rep(i,N)for(ll j: memo[i]) g.add_edge(i,N+j,1);
        rep(i,cnt) g.add_edge(N+i,gl,1);

        if(cnt == g.flow(st,gl)){
            ans.push_back(idx+1);
        }
    }

    for(ll a: ans) cout << a << " "; cout << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
