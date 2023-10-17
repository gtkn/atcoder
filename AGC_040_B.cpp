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

    vec(Pll) LR(N);
    rep(i,N) cin >> LR[i].first >> LR[i].second;

    ll ans = 0;

    auto f = [](Pll a){
        return a.second-a.first+1;
    };


    vec(Pll) v = LR;
    sort(all(v),[&](Pll const& a, Pll const& b){
        return f(a) < f(b);
    });

    Pll vmax = v.back();
    // v.pop_back();
    
    
    ll lmax=0, rmin=llINF;
    for(Pll vi:v) chmax(lmax,vi.first);
    for(Pll vi:v) chmin(rmin,vi.second);
    

    chmax(ans, f(vmax) + max(rmin-lmax+1,0LL));


    vec(Pll) ab;
    for(auto [l,r]:LR) ab.emplace_back( max(r-lmax+1,0LL), max(rmin-l+1,0LL) );
    
    sort(all(ab),[](Pll const& a,Pll const& b){
        if(a.first!=b.first) return a.first < b.first;
        return a.second > b.second;
    });


    ll bmin=llINF;
    rep(i,N-1){
        chmin(bmin, ab[i].second);
        chmax(ans, ab[i+1].first+bmin );
    }






    // vec(Pll) v1,v2;
    // v1.push_back(vmax);

    // ll th = 0;
    // for(Pll vi:v) if(vi.second==rmin) chmax(th, vi.first);

    // for(Pll vi:v){
    //     // if(vi.first==lmax) v1.push_back(vi);
    //     if(vi.first>=th) v1.push_back(vi);
    //     else v2.push_back(vi);
    // }

    // auto getrange = [](vec(Pll) const& a){
    //     ll lm=0, rm=llINF;
    //     for(Pll vi:a) chmax(lm,vi.first);
    //     for(Pll vi:a) chmin(rm,vi.second);
    //     return max(rm-lm+1,0LL);
    // };

    // if(!v2.empty()) chmax(ans, getrange(v1)+getrange(v2));

    // v1.clear();
    // v2.clear();
    // v1.push_back(vmax);

    // th = llINF;
    // for(Pll vi:v) if(vi.first==lmax) chmin(th,vi.second);

    // for(Pll vi:v){
    //     // if(vi.second==rmin) v1.push_back(vi);
    //     if(vi.second<=th) v1.push_back(vi);
    //     else v2.push_back(vi);
    // }

    // if(!v2.empty()) chmax(ans, getrange(v1)+getrange(v2));

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
