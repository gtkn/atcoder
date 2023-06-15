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
    void solve(){
        int N,M;
        cin >> N >> M;

        vec(string) S(N);
        rep(i,N) cin >> S[i];

        int n5 = 5*N;
        int n3 = 3*N;
        vvec(int) vvx(n3,vec(int)(n5));
        vvec(int) vvy(n3,vec(int)(n5));

        rep(i,N)rep(j,N){
            if(S[i][j]=='X') continue;
            vvx[i][j]++;
            vvx[i+M][j]--;
            vvy[i][j+2*M]--;
            vvy[i+M][j]++;
        }

        rep(i,n3)rep(j,n5){
            if(i==0) continue;
            vvx[i][j] += vvx[i-1][j];
            if(j+2<n5) vvy[i][j] += vvy[i-1][j+2];
        }

        vvec(int) vv(n3,vec(int)(n5));
        rep(i,n3)rep(j,n5) vv[i][j] = vvx[i][j] + vvy[i][j];

        rep(i,n3)rep(j,n5){
            if(j>0) vv[i][j] += vv[i][j-1];
        }


        int Q;
        cin >> Q;
        // vec(int) X(Q),Y(Q);
        // rep(i,Q) cin >> X[i] >> Y[i];

        while(Q--){
            int x,y;
            cin >> x >> y;
            cout << vv[x-1][y-1] << endl;
        }        


        // rep(i,nn){
        //     rep(j,nn) cout << vv[i][j] << " "; cout << endl;
        // }



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