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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N, K;
    cin >> N >> K;

    vec(ll) X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];
    sort(all(X));
    sort(all(Y));

    vec(ll) rX(N),rY(N);
    rep(i,N) rX[i] = -X[N-1-i];
    rep(i,N) rY[i] = -Y[N-1-i];

    // vec(ll) xl(N+1),xu(N+1);
    // rep(i,N) xl[i+1] = xl[i]+X[i];
    // repr(i,N) xu[i] = xu[i+1]+X[i];

    // vec(ll) yl(N+1),yu(N+1);
    // rep(i,N) yl[i+1] = yl[i]+Y[i];
    // repr(i,N) yu[i] = yu[i+1]+Y[i];



    auto f = [](ll th, const vec(ll) &v)->ll{
        ll res = llINF;
        ll nn = v.size();

        ll rtot = 0;
        rep(i,nn) rtot += v[i];
        ll ltot=0;

        ll ri = 0;
        rep(i,nn){
            ll left = v[i];
            while(ri<nn && v[ri] - left < th){
                rtot -= v[ri];
                ri++;
            }

            ll right = left + th;

            // cout << i << " : " << left <<" , " << ri << " , " << ltot <<" , " << rtot << endl;

            ll tmp = 0;
            tmp += i*left - ltot;
            tmp += rtot - right*(nn-ri);
            chmin(res,tmp);

            ltot += v[i];

        }

        return res;
    };

    // cout << f(2,X) << endl;
    // return;

    // rep(w,5) cout << w << " : " << f(w,X) << ", " << f(w,Y) << endl; 



    ll l=-1,r=1e9+10;
    while(r-l>1){
        ll mid = (l+r)/2;
        ll kk = 0;
        kk += min(f(mid, X),f(mid,rX));
        kk += min(f(mid, Y),f(mid,rY));
        if(kk<=K) r=mid;
        else l=mid;
    }

    cout << r << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
