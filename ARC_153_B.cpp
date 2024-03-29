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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

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

 
    void solve(){
        ll H,W;
        cin >> H >> W;
        vvec(char) A(H,vec(char)(W));
        rep(i,H){
            string s;
            cin >> s;
            rep(j,W) A[i][j] = s[j];
        }


        ll Q;
        cin >> Q;
        vec(ll) va(Q),vb(Q);
        rep(i,Q) cin >> va[i] >> vb[i];


        ll h0=0,h1=1;
        rep(i,Q){
            h0 = va[i]-1-h0;
            if(h0<0) h0+=H;

            h1 = va[i]-1-h1;
            if(h1<0) h1+=H;
        }

        ll w0=0,w1=1;
        rep(i,Q){
            w0 = vb[i]-1-w0;
            if(w0<0) w0+=W;

            w1 = vb[i]-1-w1;
            if(w1<0) w1+=W;
        }


        ll dh = h1-h0;
        vec(ll) vh(H);
        rep(i,H){
            if(i==0){
                vh[0]=h0;
            }else{
                vh[i]=(vh[i-1]+dh+H)%H;
            }
        }


        ll dw = w1-w0;
        vec(ll) vw(W);
        rep(i,W){
            if(i==0){
                vw[0]=w0;
            }else{
                vw[i]=(vw[i-1]+dw+W)%W;
            }
        }

        
        vvec(char) ans(H,vec(char)(W));
        rep(i,H)rep(j,W) ans[vh[i]][vw[j]] = A[i][j];

        rep(i,H){
            rep(j,W) cout << ans[i][j];
            cout << endl;
        }


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
