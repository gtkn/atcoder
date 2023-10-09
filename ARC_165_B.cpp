//title
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
    ll N,K;
    cin >> N >> K;

    vec(ll) P(N+1);
    rep1(i,N) cin >> P[i];

    ll cnt = 0, cmax=0;
    rep1(i,N){
        if(P[i]>P[i-1]) cnt++;
        else cnt = 1;
        chmax(cmax, cnt);
    }

    if(cmax>=K){
        rep1(i,N) cout << P[i] << " "; cout << endl;
        return;
    }


    set<ll> s;
    for(ll i=N-K+1; i<=N; i++) s.insert(P[i]);
    ll st = N-K+1;

    for(ll i=N-K; i>max(N-2*K,0LL); i--){
        if(P[i]>P[i+1]) break;
        s.erase(P[i+K]);
        if(s.empty()) break;

        if(P[N-K] < *s.begin()) st = i;
    }

    // cout << st << " !" << endl;
    sort(P.begin()+st, P.begin()+st+K);
    rep1(i,N) cout << P[i] << " "; cout << endl;








}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
