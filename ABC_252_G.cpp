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

//------------------------------------------------

struct Solver{

    ll N;
    ll P[510];
    mint dp0[510][510];
    mint dp1[510][510];
    bool used0[510][510];
    bool used1[510][510];


    mint f0(ll l,ll r){
        if(used0[l][r]) return dp0[l][r];

        mint res = 0;
        for(ll k=l;k<r;k++){
            res += f1(l,k)*f0(k+1,r);
        }
        dp0[l][r]=res;
        used0[l][r]=true;
        //cout << l << ", " << r << " ; " << res.val() << endl;
        return res;
    }

    mint f1(ll l,ll r){
        if(used1[l][r]) return dp1[l][r];

        mint res = 0;
        for(ll k=l;k<=r;k++){
            if(P[k+1]<P[r+1]) res += f1(l,k)*f0(k+1,r);
        }
        dp1[l][r]=res;
        used1[l][r]=true;
        return res;
    }




    void solve(){
        cin >> N;
        rep(i,N) cin >> P[i];
        P[N]=llINF;

        rep(i,510) dp0[i][i]=1;
        rep(i,510) dp1[i][i]=1;

        rep(i,510)rep(j,510) used0[i][j]=(i==j);
        rep(i,510)rep(j,510) used1[i][j]=(i==j);

        mint ans = f0(0,N-1);
        cout << ans.val() << endl;


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
