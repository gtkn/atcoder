//title
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
using mint = modint998244353;


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


void solve(){
    ll N,K;
    cin >> N >> K;

    string S;
    cin >> S;


    ll nn = (1<<K);

    vvec(mint) dp(N+1,vec(mint)(nn));


    auto f = [](string s)->ll{
        ll res = 0;
        for(char c:s){
            res = res*2 + (c=='B');
        }
        return res;
    };

    ll m = 0;
    vec(ll) v;
    rep(i,K)if(S[i]=='?'){
        m++;
        v.push_back(i);
    }

    rep(ptn,(1<<m)){
        string t = S.substr(0,K);
        rep(i,m){
            if(bit(ptn,i)) t[v[i]] = 'A';
            else t[v[i]] = 'B';
        }
        bool kaibun = true;
        rep(i,K/2) if(t[i]!=t[K-i-1]) kaibun = false;
        if(!kaibun) dp[K][f(t)]++;
    }


    for(ll i = K; i < N; i++)rep(j,nn){

        vec(ll) cand;
        if(S[i]=='A' || S[i]=='?') cand.push_back(0);
        if(S[i]=='B' || S[i]=='?') cand.push_back(1);
        for(ll x : cand){
            ll jj = (j*2)%nn + x;
            bool kaibun = true;
            rep(k,K/2) if(bit(jj,k)!=bit(jj,K-k-1)) kaibun = false;
            if(!kaibun) dp[i+1][jj] += dp[i][j];
        }
    }   

    // rep(i,N+1){
    //     rep(j,nn) cerr << dp[i][j].val() << " "; cerr << endl;
    // }



    mint ans = 0;
    rep(j,nn) ans += dp[N][j];
    cout << ans.val() << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
