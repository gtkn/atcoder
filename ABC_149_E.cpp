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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;

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
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,M;
        cin >> N >> M;
        vec(ll) A(N);
        rep(i,N) cin >> A[i];
        sort(all(A));

        ll nn = 200010;
        vec(ll) v(nn);
        for(ll ai:A) v[ai]++;
        vec(ll) c(nn);
        repr(i,nn-1) c[i] = c[i+1]+v[i]; 

        ll ok=0,ng=nn;
        while(ng-ok>1){
            ll mid = (ok+ng)/2;
            ll cnt = 0;
            for(ll ai:A){
                ll th = max(mid-ai, 0LL);
                cnt += c[th];
                // ll th = mid-ai;
                // auto itr = lower_bound(all(A),th);
                // cnt += N-distance(A.begin(),itr);
            }
            if(cnt>=M) ok=mid;
            else ng = mid;
        }


        // vec(ll) cum(N+1);
        // rep(i,N) cum[i+1] = cum[i]+A[i];

        ll ans = 0;

        vec(ll) c2(nn);
        repr(i,nn-1) c2[i] = c2[i+1]+v[i]*i;

        for(ll ai:A){
            // ll th = ok-ai;
            // auto itr = upper_bound(all(A),th);
            // ll x = distance(A.begin(),itr);
            // ans += cum[N]-cum[x] + (N-x)*ai;
            // M -= (N-x);

            ll th = max(ok-ai, 0LL)+1;
            ans += c2[th] + c[th]*ai;
            M-=c[th];
        }

        ans += M*ok;


        cout << ans << endl;

    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
