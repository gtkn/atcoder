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


void doubling(vvec(ll) &db){
    // 0列目まで埋めたダブリングの配列の残りを計算する
    ll n,m;
    n = db.size();
    m = db[0].size();

    rep(j,m-1)rep(i,n){
        db[i][j+1] = db[ db[i][j] ][j];
    }
}



void solve(){
    ll N,K;
    cin >> N >> K;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];
    vec(ll) aa = A;
    rep(i,N) aa.push_back(A[i]);

    aa.push_back(llINF);

    ll nn = 2*N;
    ll M = 20;

    auto f = [&](ll w)->vec(bool){
        vvec(ll) db(nn+2,vec(ll)(M));

        ll sum = 0, r = 0;
        rep(l,nn+1){
            while(sum<w && r<nn){
                sum += aa[r];
                r++;
            }
            db[l][0] = r;
            sum -= aa[l];
        }
        db[nn+1][0] = nn+1;

        doubling(db);

        vec(bool) res(nn+2);
        rep(i,nn){
            ll now = i;
            rep(j,M){
                if(bit(K,j)) now = db[now][j];
            }
            res[i] = (now<=i+N);
        }
        return res;
    };


    auto ff = [&](ll w)->bool{
        vec(bool) res = f(w);
        rep(i,N) if(res[i]) return true;
        return false;
    };


    ll l = 0, r = 1e10;
    while(r-l>1){
        ll mid = (l+r)/2;
        if(ff(mid)) l = mid;
        else r = mid;
    }

    ll ans = l;
    vec(bool) isok = f(ans);
    ll anscnt = 0;
    rep(i,N) if(!isok[i]) anscnt++;

    cout << ans << " " << anscnt << endl;



    // auto f = [&](ll st, ll w)->bool{
    //     ll sum = 0;
    //     ll cnt = 0;
    //     for(ll i=st; i<st+N; i++){
    //         sum += aa[i];
    //         if(sum >= w){
    //             cnt++;
    //             sum = 0;
    //         }
    //     }
    //     if(cnt>=K) return true;
    //     return false;
    // };

    // auto ff = [&](ll w)->bool{
    //     rep(st,N) if(f(st,w)) return true;
    //     return false;
    // };

    // ll atot = 0;
    // rep(i,N) atot += A[i];
    
    // ll l = 0, r = (atot/K)+100;
    // while(r-l>1){
    //     ll mid = (l+r)/2;
    //     if(ff(mid)) l = mid;
    //     else r = mid;
    // }


    // ll ans = 0;
    // rep(i,N){
    //     if(!f(i,l)){
    //         // cerr << i << " ";
    //         ans++;
    //     }
    // }
    // // cerr << endl;

    // cout << l << " " << ans << endl;    




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
