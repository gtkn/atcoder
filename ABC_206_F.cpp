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
using Pii = pair<int,int>;
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


    ll N;
    vvec(ll) grandy;
    vec(ll) L,R;


    ll dfs(ll l, ll r){
        if(grandy[l][r]!=-1) return grandy[l][r];

        set<ll> s;

        rep(i,N){
            if(L[i]<l || R[i]>r) continue;
            s.insert(dfs(l,L[i]) ^ dfs(R[i],r));
        }

        ll res = 0;
        while(s.count(res)!=0) res++;
        grandy[l][r] = res;

        return res;

    }

    // ll dfs2(ll l, ll r){
    //     if(grandy[l][r]!=-1) return grandy[l][r];

    //     ll res = 0;

    //     rep(i,N){
    //         if(dfs(l,L[i])==0) res = 1;
    //         if(dfs(R[i],r)==0) res = 1;
    //     }

    //     grandy[l][r] = res;

    //     return res;
    // }


    void solve(){
        cin >> N;

        L.resize(N);
        R.resize(N);
        grandy = vvec(ll)(110,vec(ll)(110,-1));


        rep(i,N) cin >> L[i] >> R[i];

        string ans = "Alice";
        if( dfs(0,101) == 0) ans = "Bob";

        cout << ans << endl;


    }
};



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
