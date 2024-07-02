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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

ll op(ll a,ll b){return max(a,b);}
ll ee(){return 0;}


void solve(){
    ll N,M;
    cin >> N >> M;

    vvec(ll) A(N,vec(ll)(N));
    rep(i,N)rep(j,N) cin >> A[i][j];


    vvvec(ll) dps(4);
    ll ans = 0;


    auto rot = [](vvec(ll) vv)->vvec(ll){
        ll nn = vv.size();
        assert(vv[0].size()==nn);
        vvec(ll) res(nn,vec(ll)(nn));
        rep(i,nn)rep(j,nn) res[nn-1-j][i] = vv[i][j];
        return res;
    };

    rep(k,4){
        vvec(ll) tot(N+1,vec(ll)(N+1));
        rep1(i,N)rep1(j,N) tot[i][j] = tot[i-1][j] + tot[i][j-1] - tot[i-1][j-1] + A[i-1][j-1];

        auto f = [&](ll ii, ll jj)->ll{
            if(ii<=N && jj<=N && ii-M>=0 && jj-M>=0){
                return tot[ii][jj] - tot[ii-M][jj] - tot[ii][jj-M] + tot[ii-M][jj-M];
            }
            return -llINF;
        };

        vvec(ll) dp(N+1,vec(ll)(N+1,-llINF));
        rep1(i,N)rep1(j,N){
            chmax(dp[i][j], f(i,j));
            chmax(dp[i][j], dp[i-1][j]);
            chmax(dp[i][j], dp[i][j-1]);
        }
        dps[k] = dp;



        vec(ll) v(N+1,-llINF);
        rep1(i,N)rep1(j,N) chmax(v[i], f(i,j));

        segtree<ll,op,ee> seg(v);
        auto f2 = [&](ll l, ll r)->ll{
            if(l>=r) return -llINF;
            return seg.prod(l,r);
        };

        rep(i1,N)rep(i0,i1){
            chmax(ans, f2(M-1,i0) + f2(i0+M-1,i1) + f2(i1+M-1,N+1) );
        }

        A = rot(A);
    }


    rep(i0,N+1)rep(j0,N+1){
        ll i1 = N-j0, j1 = i0;
        ll i2 = N-j1, j2 = i1;
        ll i3 = N-j2, j3 = i2;
        chmax(ans, dps[0][i0][j0] + dps[1][i1][j1] + dps[2][i2][N] );
        chmax(ans, dps[1][i1][j1] + dps[2][i2][j2] + dps[3][i3][N] );
        chmax(ans, dps[2][i2][j2] + dps[3][i3][j3] + dps[0][i0][N] );
        chmax(ans, dps[3][i3][j3] + dps[0][i0][j0] + dps[1][i1][N] );
    }

    // vvec(ll) dp = dps[0];
    // rep(_,2){
    //     vec(ll) v(N+1,-llINF);
    //     rep1(i,N)rep1(j,N) chmax(v[i], dp[i][j]);

    //     segtree<ll,op,ee> seg(v);
    //     auto f2 = [&](ll l, ll r)->ll{
    //         if(r-l<M) return -llINF;
    //         return seg.prod(l,r);
    //     };

    //     rep(i1,N)rep(i0,i1){
    //         chmax(ans, f2(M-1,i0) + f2(i0+M-1,i1) + f2(i1+M-1,N+1) );
    //     }

    //     rep1(i,N)rep1(j,i) swap(dp[i][j], dp[j][i]);
    // }

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
