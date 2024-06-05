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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


ll op(ll a,ll b){return max(a,b);}
ll e(){return 0;}


void solve(){
    ll N,H;
    cin >> N >> H;

    vec(ll) t(N),d(N);
    segtree<ll,op,e> seg0(d);

    rep(i,N) cin >> t[i] >> d[i];

    set<ll> st;
    st.insert(1);
    rep(i,N) st.insert(t[i]);

    map<ll,vector<ll>> memo;
    rep(i,N) memo[t[i]].push_back(i);

    segtree<ll,op,e> seg1(d);

    vec(ll) vt;
    for(ll ti:st) vt.emplace_back(ti);

    ll nn = st.size();
    vec(Pll) dmg;
    // ll dmax = seg1.all_prod();
    dmg.emplace_back( 0, seg1.all_prod() );
    for(auto [ti, vi]:memo){
        for(ll ii:vi){
            seg1.set(ii,0);
            seg0.set(ii,t[ii]*d[ii]);
        }
        dmg.emplace_back( seg0.all_prod(), seg1.all_prod() );
    }

    // cerr << "nn: " << nn << endl;
    // cerr << "dmg: " << endl;
    // rep(i,nn) cerr << vt[i] << " : " << dmg[i].first << " " << dmg[i].second << endl;


    auto mul = [](ll a, ll b, ll th) {
        if (a > th / b) {
            return th;
        } else {
            return a * b;
        }
    };

    auto f = [&](ll rem)->bool{
        ll hp = H;
        repr(i,nn){
            ll ti = vt[i];
            if(rem<ti) continue;

            ll tt = rem-ti+1;
            ll ttt = mul(tt,tt+1,llINF)/2;
            // ll xx = max(dmg[i].first*tt, dmg[i].second*ttt );
            ll xx = 0;
            chmax(xx, mul(dmg[i].first, tt, hp) );
            chmax(xx, mul(dmg[i].second, ttt, hp) );
            if(dmg[i].first <= hp/tt + 1) chmax(xx, dmg[i].first*tt);
            else chmax(xx, hp);


            hp -= xx;
            rem -= tt;
            // cerr << "rem: " << rem << " hp: " << hp << " tt:" << tt << " xx:" << xx << endl;
            // cerr << dmg[i].first << " " << dmg[i].second << endl;
        }
        // hp-=dmax;

        return (hp<=0);
    };

    // f(576460752303423497);
    // return;
    



    ll l=0,r=llINF+10;
    while(r-l>1){
        ll mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }

    cout << r << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
