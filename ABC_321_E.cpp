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
    ll N, X, K;
    cin >> N >> X >> K;

    vec(Pll) v;

    ll t = 1;
    while(t<=N){
        v.emplace_back(t, min(N,t*2-1) );
        t *= 2;
    }

    ll nn = v.size();

    auto f = [&](ll st,ll now, ll d)->ll{
        if(d<0) return 0LL;
        if(now+d>=nn) return 0LL;
        

        ll l=st, r=st;
        rep1(ii,d){
            l = max(l*2, v[now+ii].first);
            r = min(r*2+1, v[now+ii].second);
        }

        // cout << st << " : " << now << " " << d << " / " << l << " " << r << endl;

        return max(r-l+1,0LL);
    };


    ll d0 = 0;
    rep(i,nn){
        if(v[i].first<=X && X<=v[i].second){
            d0 = i;
            break;
        }
    }

    ll ans = f(X,d0,K);
    ll pre = X;

    rep1(dd, K){
        if(d0-dd<0) break;
        if(K-dd==0){
            ans++;
            break;
        }

        ll par = pre/2;
        ans += f(par, d0-dd, K-dd) - f(pre, d0-dd+1, K-dd-1);
        pre = par;
    }

    cout << ans << endl;



}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
