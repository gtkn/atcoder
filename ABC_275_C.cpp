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
        vvec(bool) vv(9,vec(bool)(9));
        rep(i,9){
            string s;
            cin >> s;
            rep(j,9) vv[i][j] = (s[j]=='#');
        }

        ll ans = 0;
        rep(h0,9)rep(w0,9){

            rep(dh,9){
                rep1(dw,9){
                    ll hh,ww;

                    hh = h0; ww=w0;
                    if(hh<0|| hh>=9 || ww<0 || ww>=9) continue;
                    if(!vv[hh][ww]) continue;
                
                    
                    hh += dh; ww += dw;
                    if(hh<0|| hh>=9 || ww<0 || ww>=9) continue;
                    if(!vv[hh][ww]) continue;
                
                    hh += dw; ww -= dh;
                    if(hh<0|| hh>=9 || ww<0 || ww>=9) continue;
                    if(!vv[hh][ww]) continue;
                
                    hh -= dh; ww -= dw;
                    if(hh<0|| hh>=9 || ww<0 || ww>=9) continue;
                    if(!vv[hh][ww]) continue;
                
                    ans++;
                    //cout << h0<<" " << w0 <<" "<< dh <<" "<< dw <<" "<< endl;
                }
            }
        }

        cout << ans << endl;


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
