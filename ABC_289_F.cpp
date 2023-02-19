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
#define printPair(x) cout << x.first <<" " << x.second << endl;

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
        ll sx,sy,tx,ty;
        cin >> sx >> sy;
        cin >> tx >> ty;

        ll a,b,c,d;
        cin >> a >> b >> c >> d;


        if(sx==tx && sy==ty){
            cout << "Yes" << endl;
            return;
        }

        if( (sx%2 != tx%2) || (sy%2!=ty%2) ){
            cout << "No" << endl;
            return;
        }




        ll itmax = 1e6;
        vec(Pll) xrange(itmax+1);
        vec(Pll) yrange(itmax+1);
        
        xrange[0] = {sx,sx}; // fi <= se
        yrange[0] = {sy,sy};


        auto chk = [](Pll xr, ll x){
            return (xr.first <= x && x <= xr.second );
        };

        ll itmin = llINF;
        rep1(i,itmax){
            xrange[i] = {2*a-xrange[i-1].second, 2*b-xrange[i-1].first};
            yrange[i] = {2*c-yrange[i-1].second, 2*d-yrange[i-1].first};
            if( chk(xrange[i],tx) && chk(yrange[i],ty) ){
                itmin=i;
                break;
            }
        }
        
        if(itmin==llINF){
            cout << "No" << endl;
            return;
        }

        // cout << itmin << "!" << endl;

        ll xx = tx, yy = ty;
        vec(Pll) ans(itmin);
        repr(it,itmin){
            ll xx2 = max(2*a-xx, xrange[it].first);
            ll yy2 = max(2*c-yy, yrange[it].first);

            // cout <<"---"<< xx2 << "," << yy2 << endl;
            // printPair(xrange[it]);
            // cout << 2*a-xx << " " << 2*b-xx << endl;
            // printPair(yrange[it]);
            // cout << 2*c-yy << " " << 2*d-yy << endl;


            // assert(chk(xrange[it],xx2));
            // assert(chk({2*a-xx,2*b-xx},xx2));
            // assert(chk(yrange[it],yy2));
            // assert(chk({2*c-yy,2*d-yy},yy2));

            ans[it] = { (xx+xx2)/2, (yy+yy2)/2 };
            xx = xx2;
            yy = yy2;
        }

        cout << "Yes" << endl;
        for(Pll ai:ans) cout << ai.first <<" " << ai.second << endl;




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
