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
    ll N, K;
    cin >> N >> K;


    vvec(ll) g(N);
    rep1(i,N-1){
        ll p; cin >> p;
        g[p-1].push_back(i);
    }

    vec(ll) A(N);
    rep(i,N) cin >> A[i];



    string ans = "Bob";

    auto f = [&](auto f, ll now)->vec(ll){
        vec(ll) v = {A[now]};

        for(ll nxt:g[now]){
            vec(ll) tmp = f(f,nxt);
            v.insert(v.end(), all(tmp));
        }

        
        vec(ll) used(N+1);
        ll rem = 0;
        for(ll vi:v){
            if(vi==-1) rem++;
            else used[vi]=true;
        }
        if(used[K]) return v;
        
        ll cnt = 0;
        rep(i,K) if(!used[i]) cnt++;

        if(cnt==0 && rem==0) ans = "Alice";
        if(cnt==0 && rem==1) ans = "Alice";
        if(cnt==1 && rem==1) ans = "Alice";

        return v;
    };


    f(f,0);
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
