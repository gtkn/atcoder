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
    ll N;
    cin >> N;
    string S;
    cin >> S;


    auto f = [&](ll k)->mint{
        ll cnt = 0;
        rep(i,k){
            bool yasumeru = true;
            for(ll j=i; j<N; j+=k){
                if(S[j]=='.'){
                    yasumeru = false;
                    break;
                }
            }
            if(yasumeru) cnt++;
        }
        return mint(2).pow(cnt);
    };


    map<ll,mint> mp;
    for(ll i=1; i*i<=N; i++){
        if(N%i==0){
            mp[i] = f(i);
            if(i!=N/i) mp[N/i] = f(N/i);
        }
    }

    // for(auto [k,v]:mp) cerr << k << " " << v.val() << endl;



    mint ans = 0;
    for(auto &[k,v]:mp){
        for(ll x=1; x*x<=k; x++){
            if(k%x==0){
                if(x<k) v-=mp[x];
                if(x!=k/x && k/x<k) v-=mp[k/x];
            }
        }
        if(k<N) ans += v;
    }

    cout << ans.val() << endl;
    // for(auto [k,v]:mp) cerr << k << " " << v.val() << endl;
    
}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
