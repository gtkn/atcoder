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
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){
    ll N,M;
    cin >> N >> M;

    vvec(ll) A(N,vec(ll)(M));
    rep(i,N)rep(j,M) cin >> A[i][j];

    vvec(ll) ans(N,vec(ll)(M));

    rep(k,M){
        mf_graph<ll> g(2*N+2);
        ll st = 2*N, gl=2*N+1;

        rep(i,N) g.add_edge(st,i,1);
        rep(i,N) g.add_edge(N+i,gl,1);
        rep(i,N)rep(j,M) if(A[i][j]>0) g.add_edge(i, N+A[i][j]-1, 1);

        ll f = g.flow(st,gl);
        // cout << k << " " << f << endl;
        assert(f==N);

        for(auto e:g.edges()){
            if(e.from==st || e.to==gl || e.flow==0) continue;
            ll ii = e.from, a = e.to-N+1;
            ans[ii][k] = a;
            rep(j,M){
                if(A[ii][j]==a){
                    A[ii][j]=-1;
                    break;
                }
            }
        }
    }

    cout << "Yes" << endl;
    rep(i,N){
        rep(j,M) cout << ans[i][j] << " "; cout << endl;
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
