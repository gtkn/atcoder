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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

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

//---素因数分解------
map<ll, ll > prime_factor(ll n) {
    map<ll, ll > pf;
    for(ll f=2; f*f<=n; ++f){
        while(n%f == 0){
            pf[f]++;
            n /= f;
        }
    }
    if(n!=1) pf[n] = 1;
    return pf;
}

// アリストテレスのふるいで素数を列挙
vec(ll) eratosthenes(ll n){
    vec(bool) isok(n+1,true);
    isok[0]=false; isok[1]=false;
    rep1(i,n){
        if(!isok[i]) continue;
        ll a=i*2;
        while(a<=n){
            isok[a]=false;
            a+=i;
        }
    }
    vec(ll) res;
    rep1(i,n) if(isok[i]) res.push_back(i);

    return res;
}


void solve(){
    ll N,K;
    cin >> N >> K;


    vec(ll) ps = eratosthenes(1e6);

    map<ll,ll> m;

    
    // map<ll,ll> num;
    // rep(i,K) num[N-i]=N-i;
    vec(ll) num(K);
    rep(i,K) num[i] = N-K+1+i;


    for(ll p:ps){
        ll a = ( (N-K+1 + p-1)/p )* p - (N-K+1);
        for(ll i=a; i<K; i+=p){
            while(num[i]%p==0){
                m[p]++;
                num[i]/=p;
            }
        }
    }

    ll cnt = 0;
    for(ll mi:num) if(mi>1) cnt++;


    // map<ll,ll> den;
    // rep1(i,K) den[i]=i;
    vec(ll) den(K);
    rep(i,K) den[i]=i+1;

    for(ll p:ps){
        for(ll i=p-1; i<K; i+=p){
            while(den[i]%p==0){
                m[p]--;
                den[i]/=p;
            }
        }
    }


    mint ans = 1;
    for(auto mi:m) ans *= (mi.second+1);
    ans *= mint(2).pow(cnt);

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
