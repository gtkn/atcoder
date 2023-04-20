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
using Pdd = pair<double,double>;
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
    ll N;
    vec(ll) X,Y;
    double th = 1e-8;


    double get_dist(Pdd a,Pdd b){
        double dx = a.first-b.first;
        double dy = a.second-b.second;
        return sqrt(dx*dx+dy*dy);
    }


    double f(Pdd xy){
        double res = 0;
        rep(i,N) chmax(res, get_dist(xy,{X[i],Y[i]}));
        return res;
    }

    double tsy(double x){
        double l=0,r=1000;
        while(r-l>th){
            double y1,y2;
            y1 = (2*l+r)/3.;
            y2 = (l+2*r)/3.;

            if(f({x,y1}) < f({x,y2})) r = y2;
            else l=y1;
            if(l>r) swap(l,r);
        }

        return f({x,l});
    }


    double tsx(){
        double l=0,r=1000;
        while(r-l>th){
            double x1,x2;
            x1 = (2*l+r)/3.;
            x2 = (l+2*r)/3.;

            if( tsy(x1) < tsy(x2) ) r=x2;
            else l=x1;
        }

        return tsy(l);
    }


    void solve(){
        cin >> N;
        X.resize(N);
        Y.resize(N);
        rep(i,N) cin >> X[i] >> Y[i];

        double ans = tsx();

        printf("%.8f\r\n",ans);

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
