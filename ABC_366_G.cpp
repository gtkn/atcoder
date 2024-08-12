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




// https://atcoder.jp/contests/abc366/submissions/56581995
// bit xor の掃き出し法
// dは連立方程式のAとbをまとめたもの
vector<bool> bit_row_reduction(vvec(bool) d){
    ll h = d.size(), w = d[0].size();

    ll now_i = 0;
    rep(j,w-1){
        for(ll i=now_i; i<h; ++i){
            if(d[i][j]){
                swap(d[i],d[now_i]);
                break;
            }
        }
        if( !d[now_i][j] ) continue;
        rep(i,h){
            if(i==now_i) continue;
            if(d[i][j]) rep(jj,w) d[i][jj] =  d[i][jj]^d[now_i][jj];
        }
        now_i++;
        if(now_i == h) break;
    }

    vec(bool) res(w); // 変数はw-1個, w番目は解なしかどうか
    rep(i,h){
        ll j = 0;
        while(j<w-1 && !d[i][j]) j++;
        if(j==w-1){
            if(d[i][w-1]){ // 解なし
                res[w-1] = true;
                return res;
            }
            continue;
        }
        res[j] = d[i][w-1];
    }
    return res;
}





void solve(){
    
    ll N,M;
    cin >> N >> M;


    vvec(bool) g(N,vec(bool)(N));
    rep(_,M){
        ll u,v;
        cin >> u >> v;
        --u; --v;
        g[u][v] = true;
        g[v][u] = true;
    }

    ll now_i = 0;
    rep(j,N){
        for(ll i=now_i; i<N; ++i){
            if(g[i][j]){
                swap(g[i],g[now_i]);
                break;
            }
        }
        if( !g[now_i][j] ) continue;
        rep(i,N){
            if(i==now_i) continue;
            if(g[i][j]) rep(jj,N) g[i][jj] =  g[i][jj]^g[now_i][jj];
        }
        now_i++;
        if(now_i == N) break;
    }

    rep(j,N){
        bool isok = false;
        rep(i,N) if(g[i][j]) isok = true;
        if(!isok) sayno;
    }

    vec(ll) ans(N);
    rep(i,N){
        rep(j,N) if(g[i][j]) ans[i] |= (1ll<<j);
    }

    cout << "Yes" << nl;
    rep(i,N) cout << ans[i] << " "; cout << endl;



}




void solve2(){
    
    ll N,M;
    cin >> N >> M;

    vvec(bool) g(N,vec(bool)(N));
    rep(_,M){
        ll u,v;
        cin >> u >> v;
        --u; --v;
        g[u][v] = true;
        g[v][u] = true;
    }

    vec(ll) ans(N);
    rep(i,N){
        vvec(bool) d(N+1,vec(bool)(N+1));
        rep(i,N)rep(j,N) d[i][j] = g[i][j];
        d[N][i] = true; d[N][N] = true;
        vec(bool) res = bit_row_reduction(d);
        if(res[N]) sayno;
        rep(j,N) if(res[j]) ans[j] |= (1ll<<i);
    }

    cout << "Yes" << nl;
    rep(i,N) cout << ans[i] << " "; cout << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        // solve();
        solve2();
    }
    return 0;
}
