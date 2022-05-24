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
const ll llINF = 1LL << 62;
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

 
    ll f(Pll a,Pll b, Pll c){
        a.first  -= c.first;
        a.second -= c.second;
        b.first  -= c.first;
        b.second -= c.second;
        ll res = abs(a.first*b.second-a.second*b.first);
        res*=4;
        return res;
    }


 
    void solve(){
        ll N;
        cin >> N;

        vec(Pll) v;
        rep(_,N){
            ll x,y;
            cin >> x >> y;
            v.emplace_back(x,y);
        }

        vec(Pll) v2 = v;
        for(Pll vi:v) v2.push_back(vi);

        ll a = 0;
        ll x0,y0;
        x0 = (v[0].first +v[N/2].first)/2;
        y0 = (v[0].second+v[N/2].second)/2;
        rep(i,N) a += f(v2[i],v2[i+1], {x0,y0} );
        a/=4;

        //cout << a << endl;

        ll l=0,r=1;
        ll b = 0;
        ll ans = llINF;
        while(l<N){
            //cout << l << ", " << r << " : " << b << endl;
            if(b<=a){
                b += f(v2[l],v2[r],v2[r+1]);
                r++;
            }else{
                b -= f(v2[l],v2[l+1],v2[r]);
                l++;
            }
            assert(l<r);
            chmin(ans, abs(a-b));
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
