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

void doubling(vvec(ll) &db, ll xx){
    // 0列目まで埋めたダブリングの配列の残りを計算する
    // 遷移先がない場合はxx
    ll n,m;
    n = db.size();
    m = db[0].size();

    rep(j,m-1)rep(i,n){
        if(db[i][j]==xx){
            db[i][j+1] = xx;
        }else{
            db[i][j+1] = db[ db[i][j] ][j];
        }
    }
}

void solve(){
    ll N,Q,X;
    cin >> N >> Q >> X;

    vec(ll) W(N);
    rep(i,N) cin >> W[i];


    vec(ll) cum(N+1);
    rep(i,N) cum[i+1] = cum[i] + W[i];

    ll wtot = 0;
    rep(i,N) wtot += W[i];

    auto f1 = [&](ll l,ll r)->ll{
        return cum[r]-cum[l];
    };


    auto f2 = [&](ll st)->ll{
        ll res = 0;
        ll xx = X;
        res += xx/wtot*N;
        xx %= wtot;

        if(xx >= f1(st,N) ){
            res += N-st;
            xx -= f1(st,N);
            st = 0;
        }

        if(xx == 0) return res;

        ll l = st, r = N;
        while(r-l>1){
            ll m = (l+r)/2;
            if(f1(st,m) < xx) l = m;
            else r = m;
        }
        res += r-st;
        return res;
    };

    vec(ll) cnt(N);
    rep(i,N) cnt[i] = f2(i);

    ll M = 50;
    vvec(ll) db(N,vec(ll)(M));
    rep(i,N) db[i][0] = (i+cnt[i])%N;

    doubling(db,-1);

    while(Q--){
        ll k;
        cin >> k;
        --k;
        ll st = 0;
        rep(i,M) if(bit(k,i)) st = db[st][i];
        cout << cnt[st] << endl;
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
