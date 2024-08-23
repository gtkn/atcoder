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
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
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


    ll M = 1e6;
    vec(bool) isprime(M+1,true);
    vec(ll) ps;
    for(ll i=2; i<=M; i++){
        if(!isprime[i]) continue;
        ps.push_back(i);
        for(ll j=i*2; j<=M; j+=i) isprime[j] = false;
    }
    sort(all(ps));


    vvec(ll) vv(K); // N-iの素因数
    for(ll pi:ps){
        for(ll x=(N/pi)*pi; x>N-K; x-=pi){
            vv[N-x].push_back(pi);
        }
    }

    map<ll,ll> mp;
    rep(d,K){
        ll x = N-d;
        for(ll pi:vv[d]){
            if(x<pi) break; 
            while(x%pi==0){
                mp[pi]++;
                x/=pi;
            }
        }
        if(x>1) mp[x]++;
    }

    // cerr << "----" << endl;
    // for(auto [pi,cnt]:mp) cerr << pi << " " << cnt << endl;

    vvec(ll) vv2(K); // K-i    
    for(ll pi:ps){
        if(pi>K) break;
        for(ll x=(K/pi)*pi; x>0; x-=pi){
            vv2[K-x].push_back(pi);
        }
    }
    rep(d,K){
        ll x = K-d;
        for(ll pi:vv2[d]){
            if(x<pi) break; 
            while(x%pi==0){
                mp[pi]--;
                x/=pi;
            }
        }
        if(x>1) mp[x]--;
    }

    // cerr << "----" << endl;
    // for(auto [pi,cnt]:mp) cerr << pi << " " << cnt << endl;


    mint ans = 1;
    for(auto [pi,cnt]:mp) ans *= (cnt+1);
    cout << ans.val() << endl;


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


void solve2(){
    ll N,K;
    cin >> N >> K;


    ll M = 1e6;
    vec(bool) isprime(M+1,true);
    vec(ll) ps;
    for(ll i=2; i<=M; i++){
        if(!isprime[i]) continue;
        ps.push_back(i);
        for(ll j=i*2; j<=M; j+=i) isprime[j] = false;
    }
    sort(all(ps));

    // vec(ll) ps = eratosthenes(M);

    vec(ll) v(K+1);
    rep1(i,K) v[i] = i;

    map<ll,ll> mp;
    for(ll pi:ps){
        if(pi>K) break;
        for(ll i=pi; i<=K; i+=pi){
            while(v[i]%pi==0){
                mp[pi]--;
                v[i]/=pi;
            }
        }
    }

    
    // cerr << "----" << endl;
    // for(auto [pi,cnt]:mp) cerr << pi << " " << cnt << endl;


    rep(i,K) v[i] = N-i;
    for(ll pi:ps){
        ll x = (N/pi)*pi;
        for(ll i = (N-x); i<K; i+=pi){
            while(v[i]%pi==0){
                mp[pi]++;
                v[i]/=pi;
            }
        }
    }

    ll cnt = 0;
    rep(i,K) if(v[i]>1) mp[v[i]]++;
    // rep(i,K) if(v[i]>1) cnt++;


    mint ans = 1;
    for(auto [pi,cnt]:mp) ans *= (cnt+1);
    // ans *= mint(2).pow(cnt);
    cout << ans.val() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve2();
    }
    return 0;
}
