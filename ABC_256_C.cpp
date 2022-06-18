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
 
    void solve(){
        vec(ll) h(3),w(3);
        rep(i,3) cin >> h[i];
        rep(i,3) cin >> w[i];
        

        vvvec(ll) vvv(3);
        rep1(a,30)rep1(b,30)rep1(c,30){
            vec(ll) v={a,b,c};
            bool isok=true;
            rep(i,3) if(v[i]>=w[i]) isok=false;
            if(!isok) continue;

            ll tot = a+b+c;
            rep(i,3) if(tot==h[i]) vvv[i].push_back(v);
        }


        ll ans = 0;
        for(vec(ll) v0:vvv[0])for(vec(ll) v1:vvv[1]){

            vec(ll) v2(3);
            rep(i,3) v2[i]=w[i]-v0[i]-v1[i];


            bool isok=true;
            ll tot=0;
            rep(i,3) tot+=v2[i];
            if(tot!=h[2]) isok=false;
            rep(i,3) if(v2[i]<=0) isok=false;

            if(isok) ans++;
        }
        cout << ans << endl;


        /*
        map<vec(ll),ll> m;
        for(vec(ll) v0:vvv[0])for(vec(ll) v1:vvv[1]){
            vec(ll) v(3);
            rep(i,3) v[i]=v0[i]+v1[i];

            bool isok=true;
            rep(i,3) if(v[i]>=w[i]) isok=false;
            if(!isok) continue;
            m[v]++;
        }

        ll ans = 0;
        for(auto mi:m)for(vec(ll) v2:vvv[2]){
            vec(ll) v01 = mi.first;
            bool isok=true;
            rep(i,3) if(v01[i]+v2[i]!=w[i]) isok=false;
            if(isok) ans+=mi.second;
        }
        */





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
