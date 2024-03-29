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

double chk(ll now){
    ll tmp = now;
    ll sum = 0;
    while(tmp){
        sum+=tmp%10;
        tmp/=10;
    }
    double res = 1.*now/sum;
    // cout << now << " : " << res << endl;

    return res;
}


ll f(ll n){
    ll memo = n;
    n++;
    ll res = llINF;
    double ns = llINF;

    ll q = 0;
    ll ten = 1;

    auto update = [&](ll x){
        if(x<=memo) return;
        double a = chk(x);
        if(ns > a){
            ns = a;
            res = x;
        }
        if(ns == a) chmin(res,x);
        return;
    };


    while(n){
        rep(d,10){
            update((n+d)*ten + q);
        }
        n/=10;
        q = q*10+9;
        ten*=10;
    }
    update(q);

    return res;
}


void solve(){
    ll K;
    cin >> K;

    ll now = 0;
    while(K--){
        now = f(now);
        cout << now << endl;
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
