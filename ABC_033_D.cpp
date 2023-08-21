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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

const double PI = acos(-1);

void solve(){
    ll N;
    cin >> N;

    vec(ll) x(N),y(N);
    rep(i,N) cin >> x[i] >> y[i];

    ll ans0=0,ans1=0,ans2=0;

    double th = PI*0.5;
    double eps = 1e-12;


    rep(ii,N){

        vec(double) v;
        rep(i,N) if(i!=ii) v.push_back( atan2(y[i]-y[ii],x[i]-x[ii]) );

        sort(all(v));

        ll nn = v.size();
        rep(i,nn) v.push_back(v[i]+2*PI);

        // for(double vi:v) cout << vi << " "; cout << endl;

        ll l=0, r=0;
        rep(i,nn){
            while(l<2*nn && v[l]-v[i] < th-eps ) l++;
            while(r<2*nn && v[r]-v[i] < PI-eps ) r++;

            // cout << i << ":: " << l << " , " << r << endl;
            // cout << v[i] <<" , " << v[l] <<" , " << v[r] << endl;


            if( abs(v[l]-v[i]-th) < eps ) ans1++;
            ans2 += (r-l);
        }
    }
    ans2 -= ans1;
    ans0 = N*(N-1)*(N-2)/6 - ans1 - ans2;

    cout << ans0 <<" " << ans1 << " " << ans2 << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
