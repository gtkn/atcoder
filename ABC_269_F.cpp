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
using mint = modint998244353;


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
        ll N,M;
        cin >> N >> M;
        ll Q;
        cin >> Q;

        while(Q--){
            ll a,b,c,d;
            cin >> a >> b >> c >> d;

            mint res = 0;

            // a gyoume
            mint x0 = (a-1)*M+c;
            mint m0 = (d-c+2)/2;
            if( (a+c)&1 ){
                x0++;
                m0 = (d-c+1)/2;
            }
            mint t0 = m0*x0 + m0*(m0-1);

            mint n0 = (b-a+2)/2;
            res += n0*t0 + M*m0*n0*(n0-1);


            // a+1 gyoume
            mint x1 = a*M+c;
            mint m1 = (d-c+2)/2;
            if( (a+1+c)&1 ){
                x1++;
                m1 = (d-c+1)/2;
            }
            mint t1 = m1*x1 + m1*(m1-1);

            mint n1 = (b-a+1)/2;
            res += n1*t1 + M*m1*n1*(n1-1);


            cout << res.val() << endl;

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
