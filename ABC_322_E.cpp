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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

void solve(){
    ll N,K,P;
    cin >> N >> K >> P;

    vec(ll) C(N);
    vvec(ll) A(N,vec(ll)(K));
    
    rep(i,N){
        cin >> C[i];
        rep(j,K) cin >> A[i][j];
    }


    auto f = [](const vec(ll) &v)->ll{
        ll res = 0;
        for(ll vi:v) res = res*6+vi;
        return res;
    };

    auto r = [&](ll x)->vec(ll){
        vec(ll) res(K);
        repr(i,K){
            res[i] = x%6;
            x/=6;
        }
        return res;
    };

    ll nn = 1;
    rep(_,K) nn*=6;
    // vec(ll) v(nn,llINF);
    // rep(i,N) chmin( v[ f(A[i]) ], C[i] );


    vvec(ll) vs(nn);
    rep(i,nn) vs[i] = r(i);


    vvec(ll) dp(N+1,vec(ll)(nn,llINF));
    dp[0][0] = 0;

    // cout << "0 ;;" << f(A[0]) << endl;
    // vec(ll) aa = r(f(A[0]));
    // for(ll ai:aa) cout << ai << " "; cout << endl;

    rep(i,N){
        rep(j,nn){
            chmin(dp[i+1][j], dp[i][j] );

            vec(ll) nxt = vs[j];
            rep(k,K) nxt[k] += A[i][k];
            rep(k,K) chmin(nxt[k],(ll)5);
            chmin( dp[i+1][f(nxt)], dp[i][j]+C[i] );
        }
    }

    // cout << "1 ;;" << f(A[1]) << endl;

    auto chk = [&](ll x)->bool{
        vec(ll) tmp = r(x);
        bool res = true;
        for(ll t:tmp) if(t<P) res = false;
        return res;
    };


    ll ans = llINF;
    rep(j,nn){
        if(chk(j)) chmin(ans, dp[N][j]);
    }

    if(ans>=llINF) ans = -1;
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
