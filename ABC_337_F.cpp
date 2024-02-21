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
    ll N,M,K;
    cin >> N >> M >> K;

    vec(ll) C(N);
    rep(i,N) cin >> C[i];
    rep(i,N) C[i]--;

    vec(ll) cc = C;
    cc.insert(cc.end(), all(C));

    vec(ll) ink(N);
    for(ll ci:C) ink[ci]++;
    // rep(i,N) chmin(ink[i],K);

    ll r=0, ccnt=0;
    vec(ll) checked(N);
    while(r<N && ccnt<M){
        ll ci = cc[r];
        if( checked[ci]%K==0 ) ccnt++;
        checked[ci]++;
        r++;
    }

    ll res = 0;
    rep(i,N){
        res += min(ink[i], ( (checked[i]+K-1)/K)*K );
    }
    cout << res << endl;

    rep(l,N-1){
        ll cl=cc[l];
        checked[cl]--;
        if(checked[cl]%K==0){
            
            res -= min(ink[cl], ( (checked[cl]+K)/K)*K );
            res += min(ink[cl], ( (checked[cl]+K-1)/K)*K );

            while(r<l+N+1){
                ll cr = cc[r];
                checked[cr]++;
                r++;
                if((checked[cr]-1)%K==0){
                    res -= min(ink[cr], ( (checked[cr]+K-2)/K)*K );
                    res += min(ink[cr], ( (checked[cr]+K-1)/K)*K );
                    break;
                }
            }
        }
        cout << res << endl;
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
