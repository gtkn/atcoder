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
    ll N;
    cin >> N;


    vec(string) S(N);
    rep(i,N) cin >> S[i];

    map<string,set<ll>> used;
    map<pair<string,ll>,ll> memo;

    rep(i,N){
        auto z = z_algorithm(S[i]);

        ll nn = S[i].size();
        ll lmin = nn;
        rep(j,nn){
            ll l = nn-j;
            if( nn%l != 0 ) continue;
            
            bool isok=true;
            for(ll st = j; st>=0; st-=l){
                if( z[st] != nn-st ) isok=false;
            }
            if(isok) chmin(lmin,l);
        }

        string k = S[i].substr(0,lmin);
        
        ll now = memo[{k,nn}];
        used[k].insert(0);
        while(sfind(used[k], now)) now += nn;

        ll res = now/nn;
        cout << res << " ";
        memo[{k,nn}] = now;
        used[k].insert(now);
    }
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
