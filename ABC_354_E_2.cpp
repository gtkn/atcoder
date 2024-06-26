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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------
string toBinary(ll num, int N) {
    string binary;
    repr(i,N) binary += (num & (1 << i)) ? '1' : '0';
    return binary;
}



void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];

    vec(ll) v;
    rep(i,N)rep(j,i){
        if(A[i]==A[j] || B[i]==B[j]) v.push_back( (1<<i) + (1<<j) );
    }


    ll nn = (1<<N);
    vec(bool) dp(nn);

    rep(now,nn){
        for(ll vi:v){
            if((now&vi)!=vi) continue;
            if(dp[now^vi]==false){
                dp[now] = true;
                break;
            }
        }
    }

    // for(ll vi:v) cerr << toBinary(vi,N) << endl;
    // cerr << "---" << endl;
    // rep(i,nn) cerr << toBinary(i,N) << " " << dp[i] << endl;


    string ans = "Aoki";
    if(dp[nn-1]) ans = "Takahashi";
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
