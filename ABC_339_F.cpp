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


// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}


bool is_prime(ll M){
    for(ll x=2; x*x<=M; x++){
        if(M%x==0) return false;
    }
    return true;

}



void solve(){
    ll N;
    cin >> N;
    vec(string) A(N);
    rep(i,N) cin >> A[i];

    ll nn = 20;
    vec(ll) ps(nn);
    rep(i,nn){
        ll M = 4;
        while(!is_prime(M)){
            M = RandInt(1e9,2e9);
        }
        ps[i]=M;
    }

    vvec(ll) as(N,vec(ll)(nn));
    rep(i,N){
        rep(j,nn){
            ll rem = 0;
            for(char c:A[i]){
                rem = (rem*10 + (c-'0'))%ps[j];
            }
            as[i][j] = rem;
        }
    }


    map<vec(ll),ll> cnt;
    rep(i,N) cnt[as[i]]++;

    ll ans = 0;
    rep(i,N)rep(j,N){
        vec(ll) v(nn);
        rep(k,nn){
            v[k] = ( as[i][k]*as[j][k] )%ps[k];
        }
        ans += cnt[v];
    }

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
