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
//using mint = modint998244353;


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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,K,X;
    cin >> N >> K >> X;
    vec(ll) T(N);
    rep(i,N) cin >> T[i];

    map<Pll,ll> mp;
    priority_queue<tri, vector<tri>, greater<tri>> pq;
    auto push = [&](ll hu, ll day, ll last)->void{
        if(mp.find({day,last})==mp.end()){
            mp[{day,last}] = hu;
            pq.push({hu,day,last});
            return;
        }
        if(chmin(mp[{day,last}],hu)){
            pq.push({hu,day,last});
        }
    };
    push(0,0,0);

    auto f = [&](ll last, ll day)->ll{
        ll res = 0;
        for(ll i=last; i<N; i++){
            if(T[i]<=day) res++;
            else break;
        }
        return res;
    };

    auto f2 = [&](ll day, ll tom)->ll{
        ll res = 0;
        rep(i,N){
            if(T[i]>day && T[i]<=tom) res += tom - T[i];
        }
        return res;
    };


    ll ans = llINF;
    while(!pq.empty()){
        auto [hu,day,last] = pq.top(); pq.pop();
        // cerr << "hu: " << hu << " day: " << day << " last: " << last << endl;
        // if(hu<0) break;
        if(last==N){
            chmin(ans,hu);
            continue;
        }
        if(hu > mp[{day,last}]) continue;

        ll cnt = f(last,day);
        auto itr = upper_bound(all(T),day);

        if(itr!=T.end()){
            ll tom = *itr;
            push(hu + cnt*(tom-day) + f2(day,tom), tom, last);
        }

        ll s = min(cnt,K);
        push(hu + (cnt-s)*X + f2(day,day+X), day+X, last+s);
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
