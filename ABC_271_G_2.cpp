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






void solve(){
    ll N, X, Y;
    cin >> N >> X >> Y;
    string c;
    cin >> c;

    mint px = mint(X)/100, py = mint(Y)/100;

    ll M = 24;

    vvec(mint) dp(M+1, vec(mint)(M+2,0));
    dp[0][0] = 1;
    rep(i,M)rep(j,M+1){
        if(c[i]=='T'){
            dp[i+1][j+1] += dp[i][j]*px;
            dp[i+1][j] += dp[i][j]*(1-px);
        }else{
            dp[i+1][j+1] += dp[i][j]*py;
            dp[i+1][j] += dp[i][j]*(1-py);
        }
    }

    // rep(i,M+1){
    //     rep(j,M+1) cerr << dp[i][j].val() << " "; cerr << endl;
    // }


    mint tot = 0;
    rep1(i,M) tot += dp[M][i];


    vvec(mint) vv(M,vec(mint)(M));
    rep(i,M) vv[0][i] = dp[M][i+1]/tot;
    rep1(i,M-1) vv[i][i-1] = 1;




    // cerr << "=---" << endl;
    // rep(i,M){
    //     rep(j,M) cerr << vv[i][j].val() << " "; cerr << endl;
    // }

    vv = vvpow(vv,N-1);

    // cerr << "=---" << endl;
    // rep(i,M){
    //     rep(j,M) cerr << vv[i][j].val() << " "; cerr << endl;
    // }




    mint ans = 0;
    mint q = dp[M][0];

    rep(i,M){
        ll rem = i+1;
        mint p0 = vv[i][0];
        // cerr << i << " " << p0.val() << endl;
        rep(j,M){
            if(c[j]=='A'){
                ans += p0*dp[j][rem-1]*py/(1-q);
            }
        }
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
