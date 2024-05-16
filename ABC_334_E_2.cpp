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


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 60;
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
    ll H,W;
    cin >> H >> W;

    vvec(bool) S(H,vec(bool)(W));
    rep(i,H){
        string si; cin >> si;
        rep(j,W) S[i][j] = (si[j]=='#');
    }

    ll nn = H*W;
    dsu uf(nn);
    rep(i,H)rep(j,W){
        if(i+1<H && S[i][j] && S[i+1][j]) uf.merge(i*W+j,(i+1)*W+j);
        if(j+1<W && S[i][j] && S[i][j+1]) uf.merge(i*W+j,i*W+j+1);
    }

    vvec(ll) vv(H,vec(ll)(W));
    ll cnt = 0;
    for(auto g:uf.groups()){
        ll ij = g[0];
        if(!S[ij/W][ij%W]) continue;

        cnt++;
        for(auto v:g){
            ll i = v/W, j = v%W;
            vv[i][j] = cnt;
        }
    }

    mint ans = 0;
    rep(i,H)rep(j,W){
        if(S[i][j]) continue;
        set<ll> st;
        rep(k,4){
            ll ni = i+dh[k], nj = j+dw[k];
            if(ni<0||ni>=H||nj<0||nj>=W) continue;
            if(vv[ni][nj] > 0) st.insert(vv[ni][nj]);
        }
        ll d = -(st.size()-1);
        ans += cnt + d;
        // cerr << i <<","<<j<< ": "<< cnt+d << endl;
    }

    mint rcnt = 0;
    rep(i,H)rep(j,W){
        if(S[i][j]) continue;
        rcnt++;
    }
    // cerr << rcnt.val() << endl;
    ans /= rcnt;

    cout << ans.val() << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
