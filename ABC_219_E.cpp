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
    vvec(ll) A(6,vec(ll)(6));
    rep1(i,4) rep1(j,4) cin >> A[i][j];


    ll ans = 0;
    rep(ptn,(1<<16)){
        vvec(bool) now(6,vec(bool)(6,false));
        rep(i,16){
            if(bit(ptn,i)){
                now[i/4 + 1][i%4 + 1] = true;
            }
        }

        bool isok = true;
        rep1(i,4) rep1(j,4){
            if(A[i][j]==1 && !now[i][j]) isok = false;
        }
        if(!isok) continue;

        dsu uf(36);
        rep(i,6)rep(j,6){
            if(i+1<6 && now[i][j] == now[i+1][j]){
                uf.merge(i*6+j,(i+1)*6+j);
            }
            if(j+1<6 && now[i][j] == now[i][j+1]){
                uf.merge(i*6+j,i*6+j+1);
            }
        }


        if(uf.groups().size()<=2) ans++;

        // cerr << "ptn: " << ptn << " : " << uf.groups().size() << endl;
        // rep(i,4){
        //     rep(j,4) cerr << now[i][j] << " "; cerr << endl;
        // }

    }

    cout << ans << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
