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

#define dame { puts("-1"); return 0;}
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
        ll N,Q,X;
        cin >> N >> Q >> X;

        vec(ll) W(N);
        rep(i,N) cin >> W[i];

        vec(ll) v(N);
        vvec(ll) db(N,vec(ll)(50));

        ll aa = 0;
        rep(i,N) aa+=W[i];

        ll tot=0;
        ll cnt=0;
        ll idx=0;
        rep(st,N){

            ll z = (X-tot)/aa;
            tot += z*aa;
            cnt += z*N;

            while(tot<X){
                tot+=W[idx];
                cnt++;
                idx = (idx+1)%N;
            }

            v[st]=cnt;
            db[st][0]=idx;
            cnt--;
            tot-=W[st];
        }

        rep1(j,49){
            rep(i,N) db[i][j] = db[ db[i][j-1] ][j-1];
        }

        while(Q--){
            ll K;
            cin >> K;
            K--;
            ll x = 0;
            rep(i,50){
                if(bit(K,i)) x = db[x][i];
            }
            cout << v[x] << endl;
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
