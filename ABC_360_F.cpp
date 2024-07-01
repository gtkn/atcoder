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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------



ll op(ll a, ll b){ return max(a,b);}
ll ee(){return 0;}
ll mapping(ll f, ll x){return f+x;}
ll composition(ll f,ll g){return f+g;}
ll id(){return 0;}


void solve(){
    ll N;
    cin >> N;
    vec(ll) L(N),R(N);
    rep(i,N) cin >> L[i] >> R[i];

    ll RMAX = 1e9;

    set<ll> st;
    st.insert(0); st.insert(RMAX); st.insert(RMAX+1);
    rep(i,N)for(ll d:{-1,0,1}) st.insert(L[i]+d);
    rep(i,N)for(ll d:{-1,0,1}) st.insert(R[i]+d);

    ll nn = 0;
    map<ll,ll> mp;
    for(ll x: st) mp[x] = nn++;

    vec(ll) pm(nn);
    for(auto [k,v]: mp) pm[v] = k;

    vvec(tri) q(nn);
    rep(i,N){
        ll x = mp[L[i]], y = mp[R[i]];
        q[0].emplace_back(x+1,y,1);
        q[x].emplace_back(x+1,y,-1);
        q[x+1].emplace_back(y+1,nn,1);
        q[y].emplace_back(y+1,nn,-1);
    }

    lazy_segtree<ll, op, ee, ll, mapping, composition, id> lseg(nn);

    ll cmax = 0;
    ll ansl=0,ansr=1;
    ll th = mp[RMAX+1];

    rep(x,nn){
        for(auto [yl,yr,d]: q[x]){
            lseg.apply(yl,yr,d);
        }

        if(pm[x]<0 || pm[x]>=RMAX) continue;
        // cerr << x << " , " << pm[x] << endl;
        
        ll c = lseg.prod(x+1,th);
        if(c<=cmax) continue;
        
        ll y = lseg.max_right(x+1, [&](ll ci){return ci<c;});
        if(pm[y]>RMAX) continue;
        
        ansl = pm[x];
        ansr = pm[y];
        cmax = c;
        // cerr << ansl << " " << ansr << " : " << cmax << endl;
    }


    cout << ansl << " " << ansr << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
