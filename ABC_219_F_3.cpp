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


struct Coordinate{
    ll x,y;
    Coordinate(ll x=0, ll y=0):x(x),y(y){}

    Coordinate operator+(const Coordinate& c) const { return Coordinate(x+c.x,y+c.y); }
    Coordinate operator-(const Coordinate& c) const { return Coordinate(x-c.x,y-c.y); }

    bool operator==(const Coordinate& c) const { return x==c.x && y==c.y; }
    bool operator!=(const Coordinate& c) const { return x!=c.x || y!=c.y; }
    bool operator<(const Coordinate& c) const { return x!=c.x ? x<c.x : y<c.y; }
    bool operator>(const Coordinate& c) const { return x!=c.x ? x>c.x : y>c.y; }
    bool operator<=(const Coordinate& c) const { return x!=c.x ? x<=c.x : y<=c.y; }
    bool operator>=(const Coordinate& c) const { return x!=c.x ? x>=c.x : y>=c.y; }
    Coordinate operator*(const ll& k) const { return Coordinate(x*k,y*k); }
    Coordinate operator/(const ll& k) const { return Coordinate(x/k,y/k); }
    Coordinate operator%(const ll& k) const { return Coordinate(x%k,y%k); }
    ll operator*(const Coordinate& c) const { return x*c.x + y*c.y; }
    ll operator^(const Coordinate& c) const { return x*c.y - y*c.x; }
    
};



struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
// vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

vec(Coordinate) dhw = { {1,0},{0,1},{-1,0},{0,-1} };


void solve(){
    string S;
    cin >> S;
    ll K;
    cin >> K;

    ll N = S.size();

    set<Coordinate> st;
    Coordinate now(0,0);
    st.insert(now);
    rep(i,N){
        if(S[i]=='L') now.x--;
        if(S[i]=='R') now.x++;
        if(S[i]=='U') now.y++;
        if(S[i]=='D') now.y--;
        st.insert(now);
    }

    Coordinate d = now;

    if(d.x==0 && d.y==0){
        cout << st.size() << endl;
        return;
    }

    if(d.x==0){
        swap(d.x,d.y);
        set<Coordinate> st2;
        for(auto c: st){
            st2.insert(Coordinate(c.y,c.x));
        }
        swap(st,st2);
    }

    if(d.x<0){
        d.x *= -1;
        set<Coordinate> st2;
        for(auto c: st){
            st2.insert(Coordinate(-c.x,c.y));
        }
        swap(st,st2);
    }


    map<Pll, vector<ll>> mp;

    for(auto c: st){
        ll b = d.x*c.y - d.y*c.x;
        ll m = mod(c.x, d.x);
        mp[{b,m}].push_back(c.x);
    }


    ll ans = 0;
    for(auto p: mp){
        auto v = p.second;
        sort(all(v));
        ll n = v.size();
        rep(i,n-1){
            ll w = v[i+1] - v[i];
            ans += min(w/d.x,K);
        }
        ans += K;
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
