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
    ll N,H,W;
    cin >> N >> H >> W;

    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];


    vvec(bool) vv(H,vec(bool)(W));
    vec(bool) used(N);
    ll rem = H*W;//, used = 0, allused = (1<<N)-1;
    string ans = "No";


    auto f = [&](auto f)->void{
        // cerr << rem << endl;
        if(rem==0){
            ans = "Yes";
            return;
        }


        rep(i,H)rep(j,W){
            if(vv[i][j]) continue;

            rep(k,N){
                if(used[k]) continue;
                used[k]=true;
                f(f);
                ll a=A[k], b=B[k];
                rep(_,2){
                    swap(a,b);
                    if(i+a-1 >= H|| j+b-1>=W) continue;
                    bool isok=true;
                    for(ll ii=i; ii<i+a; ii++)for(ll jj=j; jj<j+b; jj++){
                        if(vv[ii][jj]) isok=false;                        
                    }
                    if(!isok) continue;
                    for(ll ii=i; ii<i+a; ii++)for(ll jj=j; jj<j+b; jj++){
                        vv[ii][jj] = true;
                    }
                    rem -= a*b;
                    f(f);
                    for(ll ii=i; ii<i+a; ii++)for(ll jj=j; jj<j+b; jj++){
                        vv[ii][jj] = false;
                    }
                    rem += a*b;
                }
                used[k]=false;

            }
            i=H; j=W;
        }

    };


    f(f);
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
