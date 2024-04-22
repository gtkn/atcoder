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

using Pdl = pair<double,ll>;
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




void solve(){
    ll N,A;
    cin >> N >> A;

    vec(ll) W(N),X(N),V(N);
    rep(i,N) cin >> W[i] >> X[i] >> V[i];

    ll ans = 0;
    rep(lf,N){
        ll sum = W[lf];
        vec(tri) q;

        rep(i,N)if(i!=lf){
            if(V[i]==V[lf]){
                if(X[lf] <= X[i] && X[i] <= X[lf]+A) sum += W[i];
                continue;
            }

            ll num = -(X[lf]-X[i]);
            ll den = V[lf]-V[i];
            if(den<0) num = -num, den = -den;
            bool isin = (V[i]>V[lf]);
            q.emplace_back(num,den,(isin?1:-1)*W[i]);

            num = -(X[lf]+A-X[i]);
            den = V[lf]-V[i];
            if(den<0) num = -num, den = -den;
            isin = (V[i]<V[lf]);
            q.emplace_back(num,den,(isin?1:-1)*W[i]);
        }


        sort(all(q),[](const tri& a, const tri& b){
            auto [na,da,wa] = a;
            auto [nb,db,wb] = b;
            if(na*db == nb*da) return wa > wb;
            return na*db < nb*da;
            });

        chmax(ans, sum);
        for(auto [n,d,w]:q){
            if(n >= 0){
                chmax(ans,sum);
            }
            sum += w;
            if(n >= 0){
                chmax(ans,sum);
            }
        }
    }

    cout << ans << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
