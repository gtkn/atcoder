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
#define watch(x) // cerr << (#x) << " is " << (x) << endl
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
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct S{
    Pll p0, p1;
    S(Pll p0={-llINF,-10}, Pll p1={-llINF,-20}):p0(p0),p1(p1){}

    void update(Pll p){
        if(p1.first < p.first){
            swap(p1,p);
            if(p0.first < p1.first){
                swap(p0,p1);
            }
        }
        if(p0.second==p1.second){
            p1 = p;
        }

    }

    void show(){
        cerr << this->p0.first << " ";
        cerr << this->p0.second << " ";
        cerr << this->p1.first << " ";
        cerr << this->p1.second << " ";
        cerr << endl;
    }

};



void solve(){
    ll N,K;
    cin >> N >> K;

    vec(ll) C(N),V(N);
    rep(i,N) cin >> C[i] >> V[i];


    vec(S) dp(K+1);
    dp[0].update({0,0});

    rep(i,N){
        vec(S) dp2(K+1);

        rep(j,K+1){
            if(j<K){
                dp2[j+1].update(dp[j].p0);
                dp2[j+1].update(dp[j].p1);
            }

            if(dp[j].p0.second!=C[i]){
                dp2[j].update( {dp[j].p0.first+V[i],C[i]} );
            }
            else{
                dp2[j].update( {dp[j].p1.first+V[i],C[i]} );
            }
        }
        swap(dp,dp2);
    }

    ll ans = dp[K].p0.first;
    if(ans<0) ans = -1;
    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
