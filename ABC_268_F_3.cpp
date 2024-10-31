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


// using arr = array<ll,10>;


void solve(){
    ll N;
    cin >> N;
    vec(string) S(N);
    rep(i,N) cin >> S[i];


    vec(Pll) v(N);
    rep(i,N){
        for(char c:S[i]){
            if(c=='X'){
                v[i].first++;
            }else{
                ll x = c-'0';
                v[i].second += x;
            }
        }
    }


    sort(all(v),[](const Pll& l, const Pll& r){
        return l.first*r.second > r.first*l.second;
    });

    ll ans = 0;
    for(string si:S){
        reverse(all(si));
        ll sum = 0;
        for(char c:si){
            if(c=='X'){
                ans += sum;
            }else{
                ll x = c-'0';
                sum += x;
            }
        }
    }


    ll sum = 0;
    repr(i,N){
        ans += v[i].first * sum;
        sum += v[i].second;
    }

    cout << ans << endl;


    // vec(arr) a(N);
    // rep(i,N){
    //     for(char c:S[i]){
    //         ll x = 0;
    //         if(c!='X') x = c-'1';
    //         a[i][x]++;
    //     }
    // }

    // sort(all(a),[](const arr& l, const arr& r){
    //     ll cl = 0;
    //     rep1(i,9) cl += r[i]*i;
    //     ll cr = 0;
    //     rep1(i,9) 

    // });






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
