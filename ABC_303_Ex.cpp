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
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){
    ll N, K;
    cin >> N >> K;

    vec(ll) S(K);
    rep(i,K) cin >> S[i];

    ll nn = 2*N;

    vec(mint) fa(nn+1);
    fa[0]=1;
    rep1(i,nn) fa[i]=fa[i-1]*i;
    vec(mint) af(nn+1);
    rep(i,nn+1) af[i] = fa[i].inv();



    vec(mint) v(nn);
    for(ll si:S) v[si] = af[si-1];

    auto fx = [](vec(mint) &a, vec(mint) const& b){
        ll n_ = a.size();
        a = convolution(a,b);
        a.resize( n_ );
        return;
    };

    vec(mint) res(nn);
    res[0]=1;
    ll tmp = N;
    while(tmp){
        if(tmp&1) fx(res,v);
        tmp>>=1;
        fx(v,v);
    }

    mint ans = res[2*N-2] * fa[N-2];
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
