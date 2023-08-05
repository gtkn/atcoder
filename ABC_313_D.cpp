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


void solve(){
    ll N, K;
    cin >> N >> K;

    vvec(ll) vs;
    vec(ll) ts;

    auto f = [&](vec(ll) const& v){
        cout << "? ";
        for(ll vi:v) cout << vi+1 << " ";
        cout << endl;

        ll t_;
        cin >> t_;

        vs.push_back(v);
        ts.push_back(t_);

        return t_;
    };

    ll pret = -1;



    vec(ll) ans(N+1,-1);
    rep(i,K+1){
        ll x = K-i;
        vec(ll) v;
        rep(j,x) v.push_back(j);
        for(ll j=x+1; j<=K; j++) v.push_back(j);

        ll t = f(v);

        if(pret==-1){
            ans[x] = t;    
        }else{
            if(pret==t) ans[x] = ans[x+1];
            else ans[x]=1-ans[x+1];
        }
        pret = t;
    }

    rep(i, N-(K+1)){
        ll st = 2+i;
        vec(ll) v;
        rep(j,K) v.push_back(st+j);
        ll t = f(v);

        if(pret==t) ans[st+K-1] = ans[st-1];
        else ans[st+K-1] = 1-ans[st-1];
        pret = t;
    }


    rep(i,N){
        ll tot = 0;
        for(ll x:vs[i]) tot+=ans[x];
        if( (tot&1) != ts[i]){
            rep(j,N) ans[j] = 1-ans[j];
            break;
        }
    }

    cout << "! ";
    rep(i,N) cout << ans[i] << " ";
    cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
