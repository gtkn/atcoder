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
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll H,W;
        cin >> H >> W;

        vvec(ll) vv(H,vec(ll)(W));
        rep(i,H){
            string s;
            cin >> s;
            rep(j,W){
                if(s[j]=='?') vv[i][j]=0;
                if(s[j]=='1') vv[i][j]=1;
                if(s[j]=='2') vv[i][j]=2;
            }
        }

        mf_graph<ll> mfg(H*W+4);
        ll st = H*W, gl=H*W+1;
        ll st2 = st+2, gl2 = gl+2;

        auto f = [&](ll h,ll w){return h*W+w;};

        ll b = 0;
        rep(i,H){
            // even
            for(ll j=i%2; j<W; j+=2){
                if(vv[i][j]==1) continue;
                if(vv[i][j]==2){
                    mfg.add_edge(st2, f(i,j), 1);
                    mfg.add_edge(st, gl2, 1);
                    b++;
                }
                if(vv[i][j]==0){
                    mfg.add_edge(st, f(i,j), 1);
                }
    
                rep(di,4){
                    ll ii = i+dh[di];
                    ll jj = j+dw[di];
                    if(ii<0 || ii>=H || jj<0 || jj>=W) continue;
                    if(vv[ii][jj]==1) continue;
                    mfg.add_edge(f(i,j), f(ii,jj), 1);
                }

            }
            // odd
            for(ll j=1-i%2; j<W; j+=2){
                if(vv[i][j]==1) continue;
                if(vv[i][j]==2){
                    mfg.add_edge(st2, gl, 1);
                    mfg.add_edge(f(i,j), gl2, 1);
                    b++;
                }
                if(vv[i][j]==0){
                    mfg.add_edge(f(i,j), gl, 1);
                }
            }
        }
        mfg.add_edge(gl, st, llINF);


        ll res = mfg.flow(st2,gl2);
        // cout << res << " , " << b << endl;
        if(res==b) yn;


        // auto ff=[&](ll idx)->Pll{
        //     if(idx>=H*W) return {-1,-1};
        //     return {idx/W, idx%W};
        // };

        // for(auto e:mfg.edges()){

        //     ll i,j,ii,jj;
        //     tie(i,j) = ff(e.from);
        //     tie(ii,jj) = ff(e.to);

        //     printf("(%lld,%lld)->(%lld,%lld) : %lld\r\n",i,j,ii,jj,e.flow);

        //     if(i<0 || ii<0 || e.flow==0) continue;

        //     vv[i][j] = -1;
        //     vv[ii][jj] = -1;

        // }

        // string ans = "Yes";
        // rep(i,H)rep(j,W) if(vv[i][j]==2) ans = "No";

        // cout << ans << endl;



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
