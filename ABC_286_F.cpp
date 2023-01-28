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

        vec(ll) v={4,9,5,7,11,13,17,19,23};
        vec(ll) A;

        vec(ll) chk;

        for(ll vi:v){
            ll a0 = A.size()+1;
            chk.push_back(a0);
            rep(i,vi){
                ll diff = (i+1+vi)%vi;
                A.push_back(a0+diff);
            }
        }

        ll M = A.size();
        cout << M << endl;
        rep(i,M) cout << A[i] <<" ";
        cout << endl;

        vec(ll) B(M);
        rep(i,M) cin >> B[i];

        vec(ll) amari;
        rep(i,v.size()){
            ll ci = chk[i];
            amari.push_back( (B[ci-1]-ci)%v[i] );
        }

        ll x0 = 0;
        rep1(i,210){
            bool isok=true;
            rep(j,4) if(i%v[j]!=amari[j]) isok=false;
            if(isok) x0=i;
        }

        Pll res = crt(amari,v);
        cout << res.first << endl;




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
