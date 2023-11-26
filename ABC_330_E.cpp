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
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

ll op(ll a,ll b){return a*b;}
ll ee(){return 0LL;}


void solve(){
    ll N,Q;
    cin >> N >> Q;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vec(ll) iv(Q),xv(Q);
    rep(i,Q) cin >> iv[i] >> xv[i];
    rep(i,Q) iv[i]--;


    set<ll> s;
    s.insert(0);
    for(ll a:A) s.insert(a);
    for(ll a:A) s.insert(a+1);
    for(ll a:xv) s.insert(a);
    for(ll a:xv) s.insert(a+1);


    map<ll,ll> m;
    ll nn = 0;
    for(ll a:s) m[a] = nn++;

    vec(ll) sv;
    for(ll a:s) sv.push_back(a);


    vec(ll) cnt(nn);
    for(ll a:A) cnt[ m[a] ]++;    

    // segtree<ll,op,ee> seg(cnt);


    // for(ll a:sv) cout << a << ", "; cout << endl;

    set<ll> zeros;
    rep(i,nn) if(cnt[i]==0) zeros.insert(sv[i]);


    rep(qi,Q){
        ll ii = iv[qi], xx = xv[qi];
        ll prea = A[ii],newa = xx;

        A[ii] = xx;

        ll prei = m[prea], newi = m[newa];
        cnt[prei]--;
        if(cnt[prei]==0) zeros.insert(prea);
        
        if(cnt[newi]==0) zeros.erase(newa);
        cnt[newi]++;

        cout << *zeros.begin() << endl;

        // seg.set( prei, cnt[prei] );
        // seg.set( newi, cnt[newi] );

        // for(ll c:cnt) cout << c << " "; cout << endl;


        // ll l=0, r=nn+1;
        // while(r-l>1){
        //     ll mid = (l+r)/2;
        //     if(seg.prod(0,mid)) r=mid;
        //     else l=mid;
        // }

        // cout << sv[r] << endl;








    }





    



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
