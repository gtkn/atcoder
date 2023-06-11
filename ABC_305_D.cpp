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
        ll N;
        cin >> N;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        ll Q;
        cin >> Q;
        vec(ll) l(Q),r(Q);
        rep(i,Q) cin >> l[i] >> r[i];

        vec(Pll) v;
        rep(i,N) v.emplace_back(A[i], i%2 ); // 1 sleep
        rep(i,Q) v.emplace_back(l[i], -1);
        rep(i,Q) v.emplace_back(r[i], -1);
        
        sort(all(v));

        ll pretime = 0;
        ll tot = 0;
        bool slp=false;
        map<ll,ll> dp;
        
        for(Pll vi:v){
            if(slp) tot += vi.first - pretime;
            pretime = vi.first;

            dp[vi.first] = tot;

           if(vi.second==1) slp=true;
           if(vi.second==0) slp=false;

        }

        rep(i,Q){
            cout << dp[r[i]]-dp[l[i]] << endl;
        }



        
        // set<ll> s;
        // for(Pll vi:v) s.insert(vi.first);
        // map<ll,ll> m;
        // ll cnt = 0;
        // for(ll si:s) m[si] = cnt++;

        // // vec(ll) mr(cnt);
        // // for(auto mi:m) mr[mi.second] = mi.first;

        // vec(ll) cum(cnt+10);
        // bool slp = false;
        // rep(i,v.size()){
        //     if(i==0) continue;

        //     cum[i] = cum[i-1];
        //     if(slp) cum[i] += v[i].first - v[i-1].first;

        //    if(v[i].second==1) slp=true;
        //    if(v[i].second==0) slp=false;
            
        // }

        // rep(i,Q){
        //     cout << cum[ m[r[i]] ] - cum[ m[l[i] ] ] << endl;
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
