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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


void solve(){
    ll N,M;
    cin >> N >> M;

    vvec(ll) vv0(N,vec(ll)(N)); // vv[i][j] ; iがjに 1:勝ち, -1:負け, 0:未定, -10:自分
    rep(i,N) vv0[i][i] = -10;

    rep(_,M){
        ll w,l;
        cin >> w >> l;
        --w, --l;
        vv0[w][l] = 1;
        vv0[l][w] = -1;
    }


    vvec(ll) idx(N,vec(ll)(N));
    ll nn = 0;
    rep(i,N)rep(j,i) idx[i][j] = nn++;
    assert(nn == N*(N-1)/2);    

    vec(ll) ans;
    ll st = nn+N, gl = nn+N+1;

    rep(p,N){
        vvec(ll) vv = vv0;
        ll wcnt = 0;
        rep(i,N){
            if(vv[p][i]==0){
                vv[p][i] = 1;
                vv[i][p] = -1;
            }
            if(vv[p][i]==1) ++wcnt;
        }
        if(wcnt==0) continue;


        mf_graph<ll> mf(nn+N+2);

        rep(i,N)rep(j,i){
            mf.add_edge(st,idx[i][j],1);
            if(vv[i][j]==1){
                mf.add_edge(idx[i][j],nn+i,1);
            }
            if(vv[i][j]==-1){
                mf.add_edge(idx[i][j],nn+j,1);
            }
            if(vv[i][j]==0){
                mf.add_edge(idx[i][j],nn+i,1);
                mf.add_edge(idx[i][j],nn+j,1);
            }
        }
        rep(i,N){
            if(i==p) mf.add_edge(nn+i,gl,wcnt);
            else mf.add_edge(nn+i,gl,wcnt-1);
        }

        if(mf.flow(st,gl)==nn){
            ans.push_back(p+1);
        }
    }

    for(ll ai:ans) cout << ai << " "; cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
