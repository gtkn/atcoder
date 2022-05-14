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

        vec(ll) a(N),b(N);
        rep(i,N) cin >> a[i];
        rep(i,N) cin >> b[i];

        vec(Pll) v(N, {0,0});
        set<ll> sa,sb,saa,sbb;
        ll a0=0,b0=0;
        while(a0<N && b0<N){
            sa.insert(a[a0]);
            sb.insert(b[b0]);

            if(sfind(sbb,a[a0])) sbb.erase(a[a0]);
            else saa.insert(a[a0]);
            if(sfind(saa,b[b0])) saa.erase(b[b0]);
            else sbb.insert(b[b0]);

            ll a1=a0,b1=b0;
            while(sfind(sa,a[a1])) a1++;
            while(sfind(sb,b[b1])) b1++;
            
            if(saa.empty() && sbb.empty()) for(ll i = a0; i<a1; i++) v[i] = {b0,b1};
            a0=a1;
            b0=b1;
        }

        ll Q; cin >> Q;
        while(Q--){
            ll x,y;
            cin >> x >> y;
            x--; y--;
            cout << ( (v[x].first<=y && y<v[x].second)? "Yes" : "No" ) << endl;
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
