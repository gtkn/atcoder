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
#define watch(x) cerr << (#x) << " is " << (x) << endl
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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

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
    string s;
    cin >> s;

    ll X=0,Y=0;
    for(char c:s){
        if(c=='/'){
            swap(X,Y);
        }else{
            X = (X*10)+(c-'0');
        }
    }
    swap(X,Y);

    ll g = __gcd(X,Y);
    // cerr << X << "," << Y << ", " << g << " : "<< s << endl;

    X /= g;
    Y /= g;

    ll amin,amax;
    ll rr = (1LL<<30)/Y;
    ll l=0,r=rr;

    // // amin
    // while(r-l>1){
    //     ll mid = (l+r)/2;
    //     ll N = mid*Y;
    //     ll M = -mid*X + N*(N+1)/2;
    //     if(M>0) r=mid;
    //     else l=mid;
    // }
    // amin = r;

    
    // l=0,r=rr;
    // // amin
    // while(r-l>1){
    //     ll mid = (l+r)/2;
    //     ll N = mid*Y;
    //     ll M = -mid*X + N*(N+1)/2;
    //     if(M>N) r=mid;
    //     else l=mid;
    // }
    // amax = r;

    amin = (4*X - 2*Y)/Y/Y+1;
    amax = (4*X + 2*Y)/Y/Y+1;


    // cout << amin << ", " << amax << endl;
    // return;



    // if(amin==amax){
    //     cout << "Impossible" << endl;
    //     return;
    // }


    bool isok=false;
    for(ll a=amin; a<amax; a++){

        if( (a*X)&1 ) continue;
        if( (a*Y)&1 ) continue;

        ll N = a*Y/2;
        ll M = -a*X/2 + N*(N+1)/2;

        if(M<0 || N==0 || M>N) continue;

        cout << N << " " << M << endl;
        isok=true;
    }
    if(!isok){
        cout << "Impossible" << endl;
    }


    
    



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
