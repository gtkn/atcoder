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
    ll N,K;
    cin >> N >> K;
    vec(ll) a(N);
    rep(i,N) cin >> a[i];

    
    vvec(bool) dpl(N+1,vec(bool)(K+1));
    dpl[0][0]=true;
    rep(i,N)rep(j,K+1){
        if(!dpl[i][j]) continue;
        dpl[i+1][j] = true;
        dpl[i+1][min(j+a[i],K)]=true;
    }

    vvec(bool) dpr(N+1,vec(bool)(K+1));
    dpr[N][0]=true;
    rep1r(i,N)rep(j,K+1){
        if(!dpr[i][j]) continue;
        dpr[i-1][j] = true;
        dpr[i-1][min(j+a[i-1],K)]=true;
    }

    // vec(set<ll>) sl(N+1),sr(N+1);
    // rep(i,N+1)rep(j,K+1) if(dpl[i][j]) sl[i].insert(j);
    // rep(i,N+1)rep(j,K+1) if(dpr[i][j]) sr[i].insert(j);


    // rep(i,N+1){
    //     cout << "---" << i << endl;
    //     for(ll x:sl[i]) cout << x << " "; cout << endl;
    //     for(ll x:sr[i]) cout << x << " "; cout << endl;
    // }

    ll ans = 0;
    // rep(i,N){
    //     bool isok=false;
    //     for(ll al:sl[i]){
    //         ll th = K-a[i] - al;
    //         auto itr = sr[i+1].lower_bound(th);
    //         if(itr==sr[i+1].end()) continue;
    //         ll ar = *itr;
    //         if(al+ar<K) isok=true;
    //     }
    //     if(!isok) ans++;
    // }


    rep(i,N){
        ll jj = K;
        bool isok=false;
        rep(j,K){
            if(!dpl[i][j]) continue;
            ll th = K-a[i]-j;
            while(jj>th && jj>0){
                jj--;
                if(dpr[i+1][jj] && j+jj < K) isok=true;
            }
        }
        if(!isok) ans++;
    }


    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
