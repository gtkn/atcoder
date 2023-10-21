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
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------



void solve(){
    ll N;
    cin >> N;

    vec(ll) T(N),D(N);
    rep(i,N) cin >> T[i] >> D[i];

    vec(ll) E(N);
    rep(i,N) E[i] = T[i]+D[i]+1;

    set<ll> s;
    for(ll x:T) s.insert(x);
    for(ll x:E) s.insert(x);
    s.insert(llINF);

    map<ll,ll> m;
    ll nn = 0;
    for(ll x:s) m[x] = nn++;

    vec(ll) r(nn);
    for(auto mi:m) r[mi.second] = mi.first;

    vvec(ll) vv(nn);
    rep(i,N) vv[ m[T[i]] ].push_back( E[i] );




    priority_queue<ll,vector<ll>,greater<ll>> q;
    ll ans = 0;

    rep(i,nn-1){
        for(ll d:vv[i]) q.push(d);

        // cout << "now " << i << ", " << r[i] << endl;

        for(ll now = r[i]; now<r[i+1]; now++){
            while(!q.empty() && q.top() <= now) q.pop();
            if(q.empty()) break;
            // cout <<now << " , "<< q.top() << endl;
            q.pop();
            ans++;
        }
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
