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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{


    void solve(){
        ll N,M,K;
        cin >> N >> M >> K;
        vec(ll) cnt(N+1);
        rep(_,M){
            ll u,v;
            cin >> u >> v;
            cnt[u]++;
            cnt[v]++;
        }

        ll a=0,b=0;
        rep1(i,N){
            if(cnt[i]&1) a++;
            else b++;
        }

        vec(mint) fa(N+1);
        fa[0]=1;
        rep1(i,N) fa[i] = fa[i-1]*i;

        auto cmb = [&](ll n,ll k){
            if(n>=k && k>=0) return fa[n]*fa[k].inv()*fa[n-k].inv();
            return mint(0);
        };


        mint ans = 0;
        for(ll x=0; x<=a; x+=2) ans += cmb(a,x)*cmb(b,K-x);

        cout << ans.val() << endl;

    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
