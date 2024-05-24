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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];
    
    ll Q;
    cin >> Q;
    vec(ll) t(Q), x(Q), y(Q);
    rep(i,Q){
        cin >> t[i] >> x[i];
        if(t[i] == 1) cin >> y[i];
    }

    set<ll> st;
    for(ll ai:A) st.insert(ai);
    for(ll ai:x) st.insert(ai);
    for(ll ai:y) st.insert(ai);
    st.insert(0);
    st.insert(llINF);
    map<ll,ll> mp;
    ll nn = 0;
    for(ll si:st) mp[si] = nn++;

    vec(ll) mae(nn,-1);
    rep(i,N){
        if(i==0) mae[mp[A[i]]] = 0;
        else mae[mp[A[i]]] = mp[A[i-1]];
    }
    mae[nn-1] = mp[A[N-1]];

    vec(ll) ato(nn,-1);
    rep(i,N){
        if(i==N-1) ato[mp[A[i]]] = nn-1;
        else ato[mp[A[i]]] = mp[A[i+1]];
    }
    ato[0] = mp[A[0]];


    rep(i,Q){
        if(t[i]==1){
            ll xi = mp[x[i]];
            ll yi = mp[y[i]];
            ll zi = ato[xi];

            // mae[xi]
            ato[xi] = yi;
            mae[yi] = xi;
            ato[yi] = zi;
            mae[zi] = yi;
            // ato[zi]
        }else{
            ll xi = mp[x[i]];
            ll wi = mae[xi];
            ll zi = ato[xi];

            // mae[wi]
            ato[wi] = zi;
            mae[xi] = -1;
            ato[xi] = -1;
            mae[zi] = wi;
            // ato[zi]
        }
    }

    vec(ll) pm(nn);
    for(auto [key,val]:mp) pm[val] = key;

    ll now = ato[0];
    while(now != nn-1){
        cout << pm[now] << ' ';
        now = ato[now];
    }
    cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
