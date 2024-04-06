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


void solve(){
    string S;
    cin >> S;
    ll K;
    cin >> K;

    set<Pll> st;
    ll dx=0,dy=0;
    st.insert({0,0});
    rep(i,S.size()){
        if(S[i]=='U') dy--;
        if(S[i]=='D') dy++;
        if(S[i]=='L') dx--;
        if(S[i]=='R') dx++;
        st.insert({dx,dy});
    }

    if(dx==0 && dy==0){
        ll ans = st.size();
        cout << ans << endl;
        return;
    }


    if(dx==0){
        swap(dx,dy);
        set<Pll> st2;
        for(auto [x,y]:st){
            st2.insert({y,x});
        }
        st = st2;
    }



    map<Pll,vector<ll>> mp;
    for(auto [x,y]:st){
        ll c = dx*y-dy*x;
        ll r = mod(x,abs(dx));
        ll q = (x-r)/abs(dx);
        mp[{c,r}].push_back(q);
    }

    ll ans = 0;
    for(auto [_,v]:mp){
        sort(all(v));
        ll nn = v.size();
        v.push_back(llINF);
        rep(i,nn){
            ll d = v[i+1]-v[i];
            ans += min(d,K);
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
