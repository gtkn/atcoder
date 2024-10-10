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

vvec(mint) vvxvv(vvec(mint) const& vv1, vvec(mint) const& vv2){
    ll h,w,d;
    h = vv1.size(); w=vv1[0].size(); d=vv2[0].size();
    assert(w==vv2.size());

    vvec(mint) res(h,vec(mint)(d));
    rep(i,h)rep(j,d)rep(k,w) res[i][j]+=vv1[i][k]*vv2[k][j];
    return res;
}


vec(mint) vvxv(vvec(mint) const& vv, vec(mint) const& v){
    ll h,w;
    h = vv.size(); w=vv[0].size();
    assert(w==v.size());

    vec(mint) res(h);
    rep(i,h)rep(j,w) res[i]+=vv[i][j]*v[j];
    return res;
}

mint vxv(vec(mint) const& v1, vec(mint) const& v2){
    ll h;
    h = v1.size();
    assert(h==v2.size());

    mint res=0;
    rep(i,h) res+=v1[i]*v2[i];
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



struct mcomb{
    ll nmax;
    vec(mint) fa,af;
    mcomb(ll sz=200020){
        nmax = sz;
        fa.resize(nmax+1);
        fa[0]=1;
        rep1(i,nmax) fa[i]=fa[i-1]*i;
        af.resize(nmax+1);
        rep(i,nmax+1) af[i]=fa[i].inv();
    }
    mint c(ll n, ll k){
        if(n<k || k<0 || n>nmax) return 0;
        return fa[n]*af[k]*af[n-k];
    }
};


void solve(){
    ll N,D;
    cin >> N >> D;

    mcomb mc(20020);


    mint ans = 0;

    rep(w,D+2){

        vvec(mint) vv(2,vec(mint)(2));
        vv[0][0] = mc.c(D-1, w);
        vv[0][1] = mc.c(D-1, w-1);
        vv[1][0] = mc.c(D-1, w-1);
        vv[1][1] = mc.c(D-1, w-2);

        vv = vvpow(vv, N);

        mint tmp = vv[0][0] + vv[1][1];
        // cerr << w << " " << tmp.val() << endl;
        ans += tmp; 

    }

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
