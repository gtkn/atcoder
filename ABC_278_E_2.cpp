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
    ll H,W,N,h,w;
    cin >> H >> W >> N >> h >> w;
    vvec(ll) A(H,vec(ll)(W,0));
    rep(i,H) rep(j,W) cin >> A[i][j];

    vec(ll) cnt0(N+1);
    rep(i,H)rep(j,W) cnt0[A[i][j]]++;    

    vvec(ll) ans(H-h+1,vec(ll)(W-w+1));

    rep(h0,H-h+1){
        vec(ll) cnt = cnt0;
        for(ll i=h0; i<h0+h; ++i){
            for(ll j=0; j<w; ++j){
                cnt[A[i][j]]--;
            }
        }
        rep1(x,N) if(cnt[x]>0) ans[h0][0]++;

        // cerr << h0 << "---" << endl;
        // rep1(x,N) cerr << cnt[x] << " "; cerr << nl;

        rep(w0,W-w){
            for(ll i=h0; i<h0+h; ++i){
                cnt[A[i][w0]]++;
                cnt[A[i][w0+w]]--;
            }
            // rep1(x,N) cerr << cnt[x] << " "; cerr << nl;
            rep1(x,N) if(cnt[x]>0) ans[h0][w0+1]++;
        }
    }

    rep(i,H-h+1){
        rep(j,W-w+1){
            cout << ans[i][j] << " ";
        }
        cout << nl;
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
