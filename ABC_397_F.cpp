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
// using mint = modint;
// mint::set_mod(P);


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


ll op(ll a, ll b){ return max(a,b);}
ll ee(){return -llINF;}
ll mapping(ll f, ll x){return f+x;}
ll composition(ll f,ll g){return f+g;}
ll id(){return 0;}


void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    set<ll> st;
    rep(i,N) st.insert(A[i]);
    map<ll,ll> mp;
    ll nn = 0;
    for(auto si:st){
        mp[si] = nn;
        nn++;
    }
    rep(i,N) A[i] = mp[A[i]];

    vvec(ll) pos(nn);
    rep(i,N) pos[A[i]].push_back(i);
    rep(i,nn) pos[i].push_back(N);
    rep(i,nn) reverse(all(pos[i]));


    vec(ll) v0(N),v1(N);
    {
        set<ll> used;
        ll cnt = 0;
        rep(i,N){
            if(used.find(A[i])==used.end()){
                used.insert(A[i]);
                cnt++;
            }
            v0[i] = cnt;
        }
    }
    {
        set<ll> used;
        ll cnt = 0;
        repr(i,N){
            if(used.find(A[i])==used.end()){
                used.insert(A[i]);
                cnt++;
            }
            v1[i] = cnt;
        }
    }




    vec(ll) v(N);
    v[0] = -llINF;
    rep1(i,N-1) v[i] = v0[i-1]+v1[i];
    // rep(j,N) cerr << v[j] << " "; cerr << endl;
    
    lazy_segtree<ll, op, ee, ll, mapping, composition, id> ls(v);

    ll ans = 0;
    rep(i,N-2){
        ll a = A[i];
        ll p1 = pos[a].back(); pos[a].pop_back();
        ll p2 = pos[a].back();
        ls.apply(p1,min(p2+1,N),-1);
        ll tmp = v0[i] + ls.prod(i+2,N);
        // cerr << i << " : " << v0[i] << " " << ls.prod(i+1,N) << ", " << p1 << ", " << p2 <<  endl;
        // rep(j,N) cerr << ls.get(j) << " "; cerr << endl; 
        chmax(ans,tmp);
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
