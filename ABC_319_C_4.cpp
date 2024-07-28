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


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    vvec(ll) c(3,vec(ll)(3));
    rep(i,3) rep(j,3) cin >> c[i][j];


    vec(Pll) p;
    rep(i,3) rep(j,3) p.push_back({i,j});

    ll num = 0;
    ll den = 0;

    

    do{
        den++;
        vvec(ll) vv(3,vec(ll)(3,-1));

        bool isok = true;
        for(auto [h,w]:p){ 
            ll memo = -1;
            rep(i,3){
                if(i==h) continue;
                if(memo==-1) memo = vv[i][w];
                else if(memo==vv[i][w]) isok = false;
            }
            memo = -1;
            rep(j,3){
                if(j==w) continue;
                if(memo==-1) memo = vv[h][j];
                else if(memo==vv[h][j]) isok = false;
            }
            if(h==w){
                ll memo = -1;
                rep(i,3){
                    if(i==h) continue;
                    if(memo==-1) memo = vv[i][i];
                    else if(memo==vv[i][i]) isok = false;
                }
            }
            if(h==2-w){
                ll memo = -1;
                rep(i,3){
                    if(i==h) continue;
                    if(memo==-1) memo = vv[i][2-i];
                    else if(memo==vv[i][2-i]) isok = false;
                }
            }
            if(!isok) break;
            vv[h][w] = c[h][w];
        }
        if(isok) num++;

    }while(next_permutation(all(p)));


    double ans = 1.*num/den;
    // cerr << num << " " << den << endl;
    printf("%.10f\n",ans);



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
