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
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

ll op(ll a,ll b){return max(a,b);}
ll ee(){return -llINF;}


void solve(){
    ll N;
    cin >> N;

    vec(ll) l(N),r(N);
    rep(i,N) cin >> l[i] >> r[i];


    vec(ll) mr = {0};
    // for(ll x:l) mr.push_back(x);
    for(ll x:r) mr.push_back(x);

    sort(all(mr));
    mr.erase(unique(all(mr)),mr.end());

    ll nn = mr.size();

    map<ll,ll> mf;
    rep(i,nn) mf[mr[i]] = i;

    vec(ll) d0(nn), d1(nn);
    rep(i,nn) d1[i] = -mr[i];

    segtree<ll,op,ee> seg0(d0), seg1(d1);

    rep(i,N){
        ll li=l[i], ri=r[i];

        auto itr = lower_bound(all(mr),li);
        ll lx = distance(mr.begin(), itr);
        ll rx = mf[ri];


        ll tmp = 0;
        chmax(tmp, seg0.prod(0,lx) + ri-li+1);
        chmax(tmp, seg1.prod(lx,rx+1) + ri  );


        d0[rx] = tmp;
        d1[rx] = tmp-r[i];

        seg0.set( rx, d0[rx] );
        seg1.set( rx, d1[rx] );

        // cout << i << " : " << li << " , " << ri << " / " << lx <<" , " << rx << " :: " << tmp << endl;
        // rep(j,nn) cout << d0[j] << " "; cout << endl;
        // rep(j,nn) cout << d1[j] << " "; cout << endl;


    }

    cout << seg0.all_prod() << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
