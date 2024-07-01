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


vvec(mint) vvxvv(vvec(mint) const& vv1, vvec(mint) const& vv2){
    ll h,w,d;
    h = vv1.size(); w=vv1[0].size(); d=vv2[0].size();
    assert(w==vv2.size());

    vvec(mint) res(h,vec(mint)(d));
    rep(i,h)rep(j,d)rep(k,w) res[i][j]+=vv1[i][k]*vv2[k][j];
    return res;
}


// lxlの2次元正方行列のn乗
vvec(mint) vvpow(vvec(mint) vv, ll n){
    ll l = vv.size();
    assert(vv[0].size()==l);

    vvec(mint) res(l,vec(mint)(l));
    rep(i,l) res[i][i]=1;

    while(n){
        if(n&1) res = vvxvv(vv, res);
        vv = vvxvv(vv,vv);
        n >>= 1;
    }
    return res;

};




void solve(){
    ll N,K;
    cin >> N >> K;

    mint p = mint(1)/N;
    mint q = p*(N-1);


    vvec(mint) vv(2,vec(mint)(2));
    vv[0][0] = p*p + q*q;
    vv[0][1] = p*q*2;
    vv[1][0] = p*p*2;
    vv[1][1] = 1-2*p*p;


// rep(j,2){
//     mint tmp = 0;
//     rep(i,2) tmp += vv[i][j];
//     cerr << "j ; " << tmp.val() << endl;
// }


    vv = vvpow(vv,K);

    // cerr << vv[0][0].val() << " " << vv[1][0].val() << endl;
    // cerr << (mint(5)/9).val() << " " << (mint(4)/9).val() << endl;



    mint ans = 0;
    ans += vv[0][0];
    //ans += vv[1][0] * ( (N+2)*(N-2+1)/2 );
    ans += vv[0][1] /(N-1)* ( (N+2)*(N-2+1)/2 );
    cout << ans.val() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
