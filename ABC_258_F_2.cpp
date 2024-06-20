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

ll dist(Pll a, Pll b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}


void solve(){
    ll B,K,Sx,Sy,Gx,Gy;
    cin >> B >> K >> Sx >> Sy >> Gx >> Gy;


    auto f = [&](ll x, ll y){
        vec(Pll) res;
        ll xr = x%B, yr = y%B;
        res.emplace_back(x-xr, y);
        res.emplace_back(x-xr+B, y);
        res.emplace_back(x, y-yr);
        res.emplace_back(x, y-yr+B);
        return res;
    };


    auto f2 = [&](Pll s){
        if(s.first%B==0 && s.second%B==0) return vec(Pll){s};
        if(s.first%B==0){
            vec(Pll) res;
            res.emplace_back(s.first,s.second-s.second%B);
            res.emplace_back(s.first,s.second-s.second%B+B);
            return res;
        }else{
            vec(Pll) res;
            res.emplace_back(s.first-s.first%B,s.second);
            res.emplace_back(s.first-s.first%B+B,s.second);
            return res;
        }
    };


    auto f3 = [&](Pll ss, Pll gg){
        if( (ss.first==gg.first && ss.first%B==0) || (ss.second==gg.second && ss.second%B==0)) return dist(ss,gg);
        ll res = llINF;
        for(auto ssi: f2(ss))for(auto ggi: f2(gg)){
            chmin(res, dist(ss,ssi) + dist(ssi,ggi) + dist(ggi,gg));
        }
        return res;
    };



    Pll sp = {Sx,Sy}, gp = {Gx,Gy};
    ll ans = dist(sp, gp)*K;


    for(auto si: f(Sx,Sy))for(auto gi: f(Gx,Gy)){
        chmin(ans, f3(si,gi) + dist(sp,si)*K + dist(gp,gi)*K);
    }

    

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
