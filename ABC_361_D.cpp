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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;
    string S,T;
    cin >> S >> T;


    ll nn = 1;
    rep(_,16) nn *= 3;

    vec(ll) dp(nn,llINF);

    auto f = [&](string s)->ll{
        ll res = 0;
        repr(i,N){
            res *= 3;
            if(s[i]=='W') res += 1;
            if(s[i]=='B') res += 2;
        }
        return res;
    };

    ll N2 = N+2;

    auto n2v = [&](ll n)->vector<ll>{
        vector<ll> res(N2);
        rep(i,N2){
            res[i] = n%3;
            n /= 3;
        }
        return res;
    };

    auto v2n = [&](const vector<ll>& v)->ll{
        ll res = 0;
        repr(i,N2){
            res *= 3;
            res += v[i];
        }
        return res;
    };


    priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
    auto push = [&](ll c, ll st){
        if(chmin(dp[st],c)) pq.push({c,st});
    };
    push(0,f(S));

    
    // ll tmp = f(S);
    // vec(ll) v = n2v(tmp);
    // for(auto vi:v) cerr << vi << " "; cerr << endl;
    // return;

    while(!pq.empty()){
        auto [c0,now] = pq.top(); pq.pop();
        if(c0>dp[now]) continue;

        vec(ll) v = n2v(now);

        ll k = 0;
        rep(i,N2){
            if(v[i]==0){
                k = i;
                break;
            }
        }

        rep(i,N2-1){
            if(v[i]==0 || v[i+1]==0) continue;
            swap(v[i],v[k]);
            swap(v[i+1],v[k+1]);
            push( c0+1, v2n(v) );
            swap(v[i],v[k]);
            swap(v[i+1],v[k+1]);
        }
    }    
    

    ll ans = dp[f(T)];
    if(ans>=llINF) ans = -1;
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
