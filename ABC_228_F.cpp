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





void solve(){
    ll H,W,h1,w1,h2,w2;
    cin >> H >> W >> h1 >> w1 >> h2 >> w2;
    chmin(h2,h1); chmin(w2,w1);

    vvec(ll) A(H,vec(ll)(W));
    rep(i,H) rep(j,W) cin >> A[i][j];

    vvec(ll) cum(H+1,vec(ll)(W+1));
    rep(i,H) rep(j,W) cum[i+1][j+1] = cum[i+1][j] + cum[i][j+1] - cum[i][j] + A[i][j];

    auto sum = [&](ll h1, ll w1, ll h2, ll w2)->ll{
        if(h1<0||w1<0||h2>H||w2>W) return -llINF;
        return cum[h2][w2] - cum[h1][w2] - cum[h2][w1] + cum[h1][w1];
    };

    vvec(ll) vv(H+1,vec(ll)(W+1,llINF));
    rep(i,H) rep(j,W){
        ll ii = i+h2, jj = j+w2;
        vv[i][j] = sum(i,j,ii,jj);
    }

    ll tate = h1-h2+1, yoko = w1-w2+1;


    vvec(ll) vv2(H,vec(ll)(W,llINF));
    rep(j,W){
        multiset<ll> st;
        rep(i,tate){
            st.insert(vv[i][j]);
        }
        rep(i,H-h1+1){
            vv2[i][j] = *st.rbegin();
            st.erase(st.find(vv[i][j]));
            st.insert(vv[i+tate][j]);
        }
    }



    ll ans = 0;

    rep(i1,H-h1+1){
        multiset<ll> st;
        rep(j2,yoko) st.insert(vv2[i1][j2]);

        rep(j1,W-w1+1){
            ll max_val = *st.rbegin();

            // cerr << i1 << " " << j1 << " : " << sum(i1,j1,i1+h1,j1+w1) << ", " << max_val << endl;
            // for(ll a:st) cerr << a << " "; cerr << endl;

            chmax(ans, sum(i1,j1,i1+h1,j1+w1) - max_val);

            st.erase(st.find(vv2[i1][j1]));
            st.insert(vv2[i1][j1+yoko]);
        }
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
