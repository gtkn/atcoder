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




struct D {
    vvec(double) xs;

    D(){
        xs = vvec(double)(3,vec(double)(2));
        rep(i,3){
            xs[i][0]=iINF; xs[i][1]= -iINF;
        }

    } 

    void add(double x,ll dir){ // dir= -1,0,1
        ll ii = dir+1;
        chmin(xs[dir+1][0],x);
        chmax(xs[dir+1][1],x);
    }

    double getxt(double x0, double t, double dir){
        return x0 + dir*t;
    }

    double getwidth(double t){
        double xmin=iINF,xmax=-iINF;
        rep(i,3)rep(j,2){
            chmin(xmin, getxt(xs[i][0], t, i-1));
            chmax(xmax, getxt(xs[i][1], t, i-1));
        }
        return xmax-xmin;
    }


    vec(double) check(){
        vec(double) res;
        rep(i,3)rep(j,i)rep(k,2){
            double tmp = -(xs[i][k]-xs[j][k])/(i-j);
            if(tmp>0) res.push_back(tmp);
        }
        return res;
    }



};


void solve(){
    ll N;
    cin >> N;

    D xd,yd;

    rep(_,N){
        double x,y;
        char d;
        cin >> x >> y >> d;

        if(d=='R'){xd.add(x, 1); yd.add(y, 0);}
        if(d=='L'){xd.add(x,-1); yd.add(y, 0);}
        if(d=='U'){xd.add(x, 0); yd.add(y, 1);}
        if(d=='D'){xd.add(x, 0); yd.add(y,-1);}
    }


    vec(double) ts={0,iINF};
    {
        vec(double) tmp = xd.check();
        ts.insert( ts.end(), tmp.begin(), tmp.end() );
    }
    {
        vec(double) tmp = yd.check();
        ts.insert( ts.end(), tmp.begin(), tmp.end() );
    }

    double ans = llINF;
    for(double t:ts){
        // cout << t << " " << ans << endl;
        chmin(ans, xd.getwidth(t)*yd.getwidth(t));
    }
    printf("%.10f\r\n",ans);

}





int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
