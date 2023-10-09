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
    ll N,M,P;
    cin >> N >> M >> P;

    vvec(Pll) g(N);
    vvec(ll) gr(N);
    rep(_,M){
        ll a,b,c;
        cin >> a >> b >> c;
        g[a-1].emplace_back(b-1, c-P );
        gr[b-1].push_back(a-1);
    }

    vec(bool) isok(N);
    queue<ll> q;
    auto qpush = [&](ll x){
        if(isok[x]) return;
        isok[x] = true;
        q.push(x);
    };
    qpush(N-1);
    while(!q.empty()){
        ll q0 = q.front(); q.pop();
        for(ll q1:gr[q0]) qpush(q1);
    }




    vec(ll) dp(N,-llINF);
    dp[0]=0;

    rep1(i,N){
        rep(now,N)for(auto [nxt, c] :g[now]){
            if(dp[now]==-llINF) continue;
            if( chmax(dp[nxt], dp[now]+c) &&  i==N && isok[nxt]) dame;
        }
    }

    cout << max(dp[N-1],0LL) << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
