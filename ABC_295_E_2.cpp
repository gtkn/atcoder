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


constexpr ll nn = 2000;

void solve(){
    ll N,M,K;
    cin >> N >> M >> K;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vec(ll) cnt(M+1);
    rep(i,N) cnt[A[i]]++;
    ll nz = cnt[0];
    cnt[0]=0;

    // mcomb mc(N+10);


    vvec(mint) C(nn+1,vec(mint)(nn+1));
    C[0][0]=1;
    rep1(i,nn){
        C[i][0]=1;
        rep1(j,i) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }

    vvec(mint) P(nn+1,vec(mint)(nn+1));
    rep(i,nn+1){
        P[i][0]=1;
        rep1(j,nn){
            P[i][j] = P[i][j-1]*i;
        }
    }

    // cerr << "C:" << endl;
    // rep(i,M+1){
    //     rep(j,M+1) cerr << C[i][j].val() << " "; cout << endl;
    // }
    // cerr << "P:" << endl;
    // rep(i,M+1){
    //     rep(j,M+1) cerr << P[i][j].val() << " "; cout << endl;
    // }



    ll R = 0;
    rep1(i,M) R += cnt[i];
    ll L = 0;

    mint ans = 0;

    rep1(x,M){
        R-=cnt[x];
        L+=cnt[x-1];

        for(ll l=0; l<=nz; l++){
            if(L+l >= K) break;
            ans += C[nz][l]*P[x-1][l]*P[M-x+1][nz-l];
        }

    }
    ans /= P[M][nz];

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
