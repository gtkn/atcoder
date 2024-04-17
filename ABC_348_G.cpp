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

struct P{
    ll a,b;
    P(ll a=0, ll b=0):a(a),b(b){}
    bool operator<(const P& x) const{
        return b < x.b;
    }
};


// bが凸
vector<ll> max_plus_convolution(const vector<ll> &a, const vector<ll> &b) {
    ll na = a.size();
    ll nb = b.size();
    
    auto f = [&](ll i, ll j)->ll{
        if(i-j<0 || i-j>=nb) return -llINF;
        return a[j]+b[i-j];
    };

    auto g = [&](auto g,vector<ll> is) -> vector<ll>{
        ll m = is.size();
        if(m==1){
            ll res = -1, mx = -llINF;
            rep(j,na){
                if(chmax(mx,f(is[0],j))) res = j;
            };
            return {res};
        }

        vec(ll) nis;
        for(ll i=0; i<m; i+=2) nis.push_back(is[i]);
        auto js = g(g, nis);
        js.push_back(na-1);
        vec(ll) res(m);
        rep(i,m){
            if(i%2 == 0){
                res[i] = js[i/2];
            }else{
                ll l=js[i/2], r=js[i/2+1];
                ll bj = l, mx=-llINF;
                for(ll j=l; j<=r; j++){
                    if(chmax(mx,f(is[i],j))) bj = j;
                }
                res[i] = bj;
            }
        }

        return res;
    };

    ll n = na+nb-1;
    vec(ll) is(n);
    iota(all(is),0);
    vec(ll) js = g(g,is);

    vec(ll) res(n);
    rep(i,n) res[i] = f(i,js[i]);
    return res;
}



void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N), B(N);
    rep(i,N) cin >> A[i] >> B[i];


    vec(P) pv(N);
    rep(i,N) pv[i] = P(A[i],B[i]);
    sort(all(pv));

    auto f = [&](auto f, ll l,ll r)->vec(ll){
        ll w = r-l;
        if(w==1){
            return {pv[l].a-pv[l].b};
        }

        ll mid = (l+r)/2;
        vec(ll) rv = f(f, mid,r);
        vec(ll) av;
        for(ll i=l; i<mid; i++) av.push_back(pv[i].a);
        sort(all(av),greater<ll>());
        vec(ll) lv = {0};
        for(ll ai:av) lv.push_back(lv.back()+ai);

        vec(ll) res = max_plus_convolution(rv,lv);
        vec(ll) lres = f(f,l,mid);
        rep(i,lres.size()) chmax(res[i],lres[i]);
        return res;
    };

    vec(ll) ans = f(f,0,N);
    rep(i,N) cout << ans[i] << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
