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

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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


    void solve(){
        ll N;
        cin >> N;

        vvec(ll) g(N);
        rep(_,N-1){
            ll a,b;
            cin >> a >> b;
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }


        vec(ll) ans(N,-1);
        
        vec(bool) used(N);
        vec(ll) t(N);
        auto calcT = [&](auto calcT, ll now, ll frm) -> ll{
            ll res = 1;
            for(ll nxt:g[now]){
                if(nxt==frm) continue;
                if(used[nxt]) continue;
                res += calcT(calcT, nxt, now);
            }
            t[now] = res;
            return res;
        };

        auto getCent = [&](auto getCent, ll sz, ll now, ll frm) ->Pll{
            ll tmax = sz-t[now];
            Pll res = {sz,-1}; // nowの部分木の中で、隣接する部分木のサイズの最大値が一番小さい時の、サイズとその頂点
            for(ll nxt:g[now]){
                if(nxt==frm) continue;
                if(used[nxt]) continue;
                chmin(res, getCent(getCent, sz, nxt, now));
                chmax(tmax, t[nxt]);
            }
            chmin(res, Pll(tmax,now));
            return res;
        };


        auto dec = [&](auto dec, ll v) -> ll{
            ll sz = calcT(calcT, v, -1); // vのいる木のサイズ
            ll c = getCent(getCent, sz, v, -1).second; // vのいる木の重心
            used[c] = true;
            for(ll child:g[c]){
                if(used[child]) continue;
                ans[ dec(dec,child) ] = c+1;
            }
            return c;
        };

        dec(dec,0);

        for(ll ai:ans) cout << ai << " "; cout << endl;




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
