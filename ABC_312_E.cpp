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

struct edge{
    ll to,c;
    edge(ll to=0, ll c=0):to(to),c(c){}
};

struct abc{
    ll a,b,c;
    abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;

    ll M = 110;
    vvvec(ll) vvv(M, vvec(ll)(M,vec(ll)(M)));

    rep1(i,N){
        ll x1,y1,z1, x2,y2,z2;
        cin >> x1>>y1>>z1>> x2>>y2>>z2;
        for(ll x=x1; x<x2; x++)for(ll y=y1; y<y2; y++)for(ll z=z1; z<z2; z++) vvv[x][y][z] = i;
    }

    vector<set<ll>> cnt(N+1);

    rep(x,M-1)rep(y,M-1)rep(z,M-1){
        ll now = vvv[x][y][z];
        if( now==0 ) continue;
        
        ll nei;
        nei = vvv[x+1][y][z];
        if(nei != now && nei!=0){
            cnt[now].insert(nei);
            cnt[nei].insert(now);
        }
        nei = vvv[x][y+1][z];
        if(nei != now && nei!=0){
            cnt[now].insert(nei);
            cnt[nei].insert(now);
        }
        nei = vvv[x][y][z+1];
        if(nei != now && nei!=0){
            cnt[now].insert(nei);
            cnt[nei].insert(now);
        }

    }


    rep1(i,N) cout << cnt[i].size() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
