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


bool is_intersection(Pll p0, Pll p1, Pll q0, Pll q1){
    // 線分p0p1とq0q1が交差しているかどうか
    auto cross = [](Pll a, Pll b, Pll c)->ll{
        ll x1 = b.first - a.first, y1 = b.second - a.second;
        ll x2 = c.first - a.first, y2 = c.second - a.second;
        return x1*y2 - x2*y1;
    };

    ll c1 = cross(p0,p1,q0);
    c1 /= abs(c1);
    ll c2 = cross(p0,p1,q1);
    c2 /= abs(c2);
    ll c3 = cross(q0,q1,p0);
    c3 /= abs(c3);
    ll c4 = cross(q0,q1,p1);
    c4 /= abs(c4);

    if(c1*c2 > 0) return false;
    if(c3*c4 > 0) return false;
    return true;
};



void solve(){
    ll N;
    cin >> N;


    vec(ll) A(N),B(N),C(N),D(N);
    rep(i,N) cin >> A[i] >> B[i];
    rep(i,N) cin >> C[i] >> D[i];


    vec(ll) ans(N);
    rep(i,N) ans[i] = i;

    while(1){
        bool isok = true;
        rep(i,N)rep(j,i){
            ll ii = ans[i], jj = ans[j];
            if( is_intersection( {A[i],B[i]}, {C[ii],D[ii]}, {A[j],B[j]}, {C[jj],D[jj]}  ) ){
                swap(ans[i],ans[j]);
                // cerr << i << " " << j << endl;
                isok = false;
            }
        }
        // rep(i,N) cerr << ans[i]+1 << " "; cerr << endl;
        if(isok) break;
    }

    rep(i,N) cout << ans[i]+1 << " "; cout << endl;



    // ll nn = 2*N;
    // vec(ll) x,y;
    // rep(i,N) x.push_back(A[i]+1);
    // rep(i,N) x.push_back(C[i]+1);
    // rep(i,N) y.push_back(B[i]+1);
    // rep(i,N) y.push_back(D[i]+1);


    // vec(ll) v(nn);
    // rep(i,nn) v[i] = i;

    // sort(all(v),[&](ll i, ll j){
    //     ll c = x[i]*y[j] - y[i]*x[j];
    //     return c>0;
    // });


    // vec(ll) d2(nn);
    // rep(i,nn) d2[i] = x[i]*x[i] + y[i]*y[i];


    // vec(ll) p,q;
    // vec(ll) ans(N,-1);


    // for(ll ii:v){
    //     if(ii<N) p.push_back(ii);
    //     else q.push_back(ii);

    //     if(p.size() != q.size() || p.size() == 0) continue;

    //     sort(all(p),[&](ll i, ll j){return d2[i] < d2[j];});
    //     sort(all(q),[&](ll i, ll j){return d2[i] < d2[j];});

    //     while(!p.empty()){
    //         // cerr << p.back() << " " << q.back() << endl;
    //         ans[ p.back() ] = q.back() - N;
    //         p.pop_back();
    //         q.pop_back();
    //     }
    // }

    // rep(i,N) cout << ans[i]+1 << " "; cout << endl;


    // rep(i,N) assert(ans[i]>=0);    
    // rep(i,N)rep(j,i){
    //     ll ii = ans[i], jj = ans[j];
    //     bool cross = is_intersection( {A[i],B[i]}, {C[ii],D[ii]}, {A[j],B[j]}, {C[jj],D[jj]}  );
    //     if(cross){
    //         cout << "--- " << i << " " << j << endl;
    //         printf("(%lld,%lld) -> (%lld,%lld) \r\n", A[i],B[i],C[ii],D[ii]);
    //         printf("(%lld,%lld) -> (%lld,%lld) \r\n", A[j],B[j],C[jj],D[jj]);

    //     }
    // }









}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
