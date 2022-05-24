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
#define watch(x) cout << (#x) << " is " << (x) << endl
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

//------------------------------------------------

struct Solver{
    
    //---modintで組み合わせ扱う用の構造体---
    struct mconb{
        ll nmax;
        vec(mint) fa,af;
        mconb(ll sz=1e9+10){
            nmax = sz;
            fa.resize(nmax+1);
            fa[0]=1;
            rep1(i,nmax) fa[i]=fa[i-1]*i;
            af.resize(nmax+1);
            rep(i,nmax+1) af[i]=fa[i].inv();
        }
        mint c(ll n, ll k){
            if(n>=0 && n<=nmax && k>=0 && k<=n) return fa[n]*af[k]*af[n-k];
            return 0;
        }
    };




    void solve(){
        ll N,M,B,W;
        cin >> N >> M >> B >>W;

        mconb mc(N*M+10);

        vvec(mint) dpb(N+1,vec(mint)(M+1));
        vvec(mint) dpw(N+1,vec(mint)(M+1));

        rep1(i,N)rep1(j,M){
            dpb[i][j] = mc.c( i*j,B );
            dpw[i][j] = mc.c( i*j,W );
            rep1(ii,i)rep1(jj,j){
                if(ii==i && jj==j) continue;
                dpb[i][j] -= mc.c(i,ii)*mc.c(j,jj)*dpb[ii][jj];
                dpw[i][j] -= mc.c(i,ii)*mc.c(j,jj)*dpw[ii][jj];
            }
            //cout << i << " , " << j << " : " << dpb[i][j].val() << endl;
        }

        mint ans = 0;
        rep1(ib,N)rep1(jb,M)rep1(iw,N)rep1(jw,M){
            ans += mc.c(N,ib)*mc.c(N-ib,iw)*mc.c(M,jb)*mc.c(M-jb,jw)*dpb[ib][jb]*dpw[iw][jw];
        }
        cout << ans.val() << endl;

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
