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

        ll N,X,D;
        cin >> N >> X >> D;

        if(D==0){
            if(X==0) cout << 1 << endl;
            else cout << N+1 << endl;
            return;
        }

        if(D<0){
            X = -X;
            D = -D;
        }


        map<ll,vector<Pll>> vv;
        rep(a,N+1){

            // ll l = a*(a-1)/2;
            // ll r = a*N - a*(a+1)/2;

            // ll s = a*X;
            // ll m = s%D;
            // if(m<0) m+=D;



            // l = (l*D + s + (D<<30))/D;
            // r = (r*D + s + (D<<30))/D;



            // vv[(s+(D<<30))%D].emplace_back(l,r+1);

            ll smin=a*X,smax=a*X;
            smin += ( a*(a-1)/2 )*D;
            smax += ( a*N - a*(a+1)/2 )*D;
            

            ll m = smin%D;
            if(m<0) m+=D;

            ll st,gl;
            st = smin/D;
            if(smin%D<0) st--;

            gl = smax/D;
            if(smax%D<0) gl--;

            assert(st<=gl);

            vv[m].emplace_back(st,gl+1);
        }

        ll ans = 0;

        set<ll> s;
        for(auto mi:vv) s.insert(mi.first);
        for(ll i:s){
            sort(all(vv[i]));

            ll st=-llINF,gl=-llINF;
            vv[i].emplace_back(llINF,llINF);
            
            // cout << "now : " << i << endl;
            for(Pll w:vv[i]){
                // cout << w.first << "," << w.second << endl;

                ans += gl-st;
                st = max(w.first,gl);
                gl = max(st,w.second);
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
