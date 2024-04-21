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
        vec(Pdl) q;

        rep(i,N)if(i!=lf){
            if(V[i]==V[lf]){
                if(X[lf] <= X[i] && X[i] <= X[lf]+A) sum += W[i];
                continue;
            }

            double t = -1. * (X[lf]-X[i])/(V[lf]-V[i]);
            bool isin = (V[i]>V[lf]);
            q.emplace_back(t, (isin?1:-1)*W[i]);

            t = -1. * (X[lf]+A-X[i])/(V[lf]-V[i]);
            isin = (V[i]<V[lf]);
            q.emplace_back(t, (isin?1:-1)*W[i]);
        }

        sort(all(q),[](Pdl a, Pdl b){
            if(abs(a.first-b.first)<1e-12) return a.second > b.second;
            return a.first < b.first;
            });
        ll tmp = 0, maxtmp = 0;
        // cerr << lf << "---" << endl;
        for(auto [t,w]:q){
            // cerr << t << " " << w <<" " << tmp << endl;
            tmp += w;
            if(t > -1e-12){
                if(chmax(maxtmp,tmp)){
                    // cerr << lf << "," << t << " : " << sum+maxtmp << endl;

                }
            }
        }
        chmax(ans,sum+maxtmp);
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
