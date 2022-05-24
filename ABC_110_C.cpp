//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (int i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目
#define vec(T) vector<T>
#define vvec(T) vector<vector<T>>
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
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

//------------------------------------------------

struct Solver{
 
    void solve(){
        string s,t;
        cin >> s >> t;

        vec(ll) used(26,-1);
        ll cnt=0;
        vec(ll) vs,vt;
        for(char ci : s){
            ll x = ci-'a';
            if(used[x]<0) used[x]=cnt++;
            vs.push_back(used[x]);
        }
        rep(i,26) used[i]=-1;
        cnt=0;
        for(char ci : t){
            ll x = ci-'a';
            if(used[x]<0) used[x]=cnt++;
            vt.push_back(used[x]);
        }
        string ans = "Yes";
        rep(i,vs.size()){
            if(vs[i]!=vt[i]) ans = "No";
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
