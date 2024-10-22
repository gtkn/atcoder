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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,Q;
    cin >> N >> Q;

    auto dist = [&](auto dist, ll frm, ll to, ll d)->ll{
        if(d==1){
            if(frm<=to) return to-frm;
            else return N-frm+to;
        }else{
            return dist(dist, to, frm, -d);
        }
    };


    auto f = [&](ll x,ll y, ll t, ll d)->Pll{
        if(x==t){
            return {0,y};
        }

        ll tt = (t+d+N)%N;
        ll dx = dist(dist,x,t,d);
        bool isok = true;
        if(d==1){
            if(x<t && x<y && y<=t){
                isok = false;
            }
            if(x>t && (x<y || y<=t)){
                isok = false;
            }            
        }else{
            if(x<t && (x>y || y>=t)){
                isok = false;
            }
            if(x>t && x>y && y>=t){
                isok = false;
            }
        }
        if(isok) return {dx,y}; 

        ll dy = 0;
        dy = dist(dist,y,tt,d);
        return {dx+dy,tt};

    };


    map<Pll,ll> dp;
    dp[{0,1}] = 0;


    while(Q--){
        char h;
        ll t;
        cin >> h >> t;
        t--;

        // cerr << "---" << endl;
        // for(auto [lr,cnt]:dp){
        //     cerr << lr.first << " " << lr.second << " : " << cnt << endl;
        // }

        map<Pll,ll> dp2;
        if(h=='L'){
            rep(r,N) dp2[{t,r}] = llINF;
        }else{
            rep(l,N) dp2[{l,t}] = llINF;
        }
        

        if(h=='L'){
            for(auto [lr,cnt]:dp){
                auto [l,r] = lr;
                for(ll d:{-1,1}){
                    auto [a,y] = f(l,r,t,d);
                    chmin(dp2[{t,y}], cnt+a);
                }
            }
        }else{
            for(auto [lr,cnt]:dp){
                auto [l,r] = lr;
                for(ll d:{-1,1}){
                    auto [a,y] = f(r,l,t,d);
                    // cerr << "l,r,t,d : " << l << " " << r << " " << t << " " << d << " : " << a << " " << y << endl;
                    chmin(dp2[{y,t}], cnt+a);
                }
            }
        }
        swap(dp,dp2);
    }

    ll ans = llINF;
    for(auto [lr,cnt]:dp){
        chmin(ans,cnt);
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
