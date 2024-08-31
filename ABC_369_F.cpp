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


ll op(ll a,ll b){
    return max(a,b);
}
ll ee(){
    return -llINF;
}

ll mapping(ll f, ll x){
    return max(f,x);
}

ll composition(ll f, ll g){
    return max(f,g);
}

ll id(){
    return -llINF;
}




void solve(){
    ll H,W,N;
    cin >> H >> W >> N;

    vec(ll) R(N),C(N);
    rep(i,N) cin >> R[i] >> C[i];
    rep(i,N) R[i]--;
    rep(i,N) C[i]--;

    vvec(ll) vv(H);
    rep(i,N) vv[R[i]].push_back(C[i]);
    rep(i,H) vv[i].push_back(W);
    rep(i,H) sort(all(vv[i]));

    lazy_segtree<ll,op,ee,ll,mapping,composition,id> lseg(W+2);
    lseg.set(0,0);

    vvec(Pll) memo(H);

    rep(h,H){
        // cerr << h << " : h" <<endl;
        ll pred = -1;
        ll tmax = 0;
        for(ll ci:vv[h]){
            // cerr << pred << " , " << ci << endl;
            lseg.apply(max(pred,0LL), ci, tmax);
            chmax(tmax, lseg.prod(pred+1,ci+1));
            tmax++;
            pred = ci;
        }
        for(ll ci:vv[h]){
            memo[h].emplace_back(ci, lseg.get(ci));
        }
    }

    ll ans = lseg.get(W-1);
    ll cnt = ans;

    vec(Pll) tour;
    Pll now = {H-1,W-1};
    tour.push_back(now);

    // rep(h,H){
    //     cerr << h << " : ";
    //     for(auto [wi,ci]: memo[h]) cerr << wi << "," << ci << " / ";
    //     cerr <<endl;
    // }


    repr(h,H){
        reverse(all(memo[h]));
        for(auto [wi,ci]:memo[h]){
            if(wi>now.second) continue;
            if(ci!=cnt) continue;
            now = {h,wi};
            tour.push_back(now);
            cnt--;
            // cerr << h << " " << wi << " " << ci << endl;
        }
    }


    // cerr << "cnt : " << cnt << endl;

    now = {0,0};
    reverse(all(tour));
    string anss = "";

    for(auto nxt:tour){
        rep(_,nxt.first-now.first) anss += "D";
        rep(_,nxt.second-now.second) anss += "R";
        now = nxt;
    }

    cout << ans << endl;
    cout << anss << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
