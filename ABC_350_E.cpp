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
using Pdd = pair<double,double>;

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
    ll N,A,X,Y;
    cin >> N >> A >> X >> Y;

    double xx = 1.*X;
    double yy = 1.*Y*6/5;
    double q = 1./5;


    vec(double) qv={1.};
    vec(double) xv={xx};
    vec(ll) bv={A};

    for(ll b=2; b<=6; b++){
        qv.push_back(q);
        xv.push_back(yy);
        bv.push_back(b);
    }
    

    map<ll,double> dp_c, dp_p;
    dp_c[0] = 0; dp_p[0]=1;
    set<ll> used;
    used.insert(0);
    

    auto f = [&](auto f, ll n)->void{
        used.insert(n);
        double c1=0,c2=0,p1=0,p2=0;

        // 1
        {
            ll n1 = n/A;
            if(used.find(n1)==used.end()){
                f(f,n1);
            }
            c1 = dp_c[n1]*1. + 1.*xx*dp_p[n1];
            p1 = dp_p[n1]*1.;
        }
        // 2
        for(ll b=2; b<=6; b++){
            ll n2 = n/b;
            if(used.find(n2)==used.end()){
                f(f,n2);
            }
            c2 += dp_c[n2]*q + q*yy*dp_p[n2];
            p2 += dp_p[n2]*q;
        }

        if(c1 > c2){
            swap(c1,c2);
            swap(p1,p2);
        }

        dp_c[n] = c1;
        dp_p[n] = p1;

        // cerr << "update: " << n << " " << dp_c[n] << " " << dp_p[n] << endl;
    };

    f(f,N);
    printf("%.10f\n", dp_c[N]);

    




    // map<ll,double> dp_c, dp_p;
    // priority_queue<ll> pq;

    
    // while(!pq.empty()){
    //     ll n = pq.top(); pq.pop();
    //     double p = dp_p[n];
    //     double c = dp_c[n];

    //     for(ll b=2; b<=6; b++){
    //         double dc1,dc2, dp1,dp2;
    //         if(b==A){
    //             dc1 = c*1. + 1.*xx*p;
    //             dp1 = p*1.;
    //         }else{
    //             dc1 = llINF;
    //             dp1 = 0;                
    //         }

    //         dc2 = c*q + q*yy*p;
    //         dp2 = p*q;

    //         if(dp1 < dp2){
    //             swap(dc1,dc2);
    //             swap(dp1,dp2);
    //         }

    //         dp_c[n/b] += dc2;
    //         dp_p[n/b] += dp2;
    //     }
    // }

    // printf("%.10f\n", dp_c[0]);




    // double ans = llINF;

    // auto f = [&](auto f,ll n, double p, double c)->void{
    //     if(n==0){
    //         chmin(ans, c);
    //         return;
    //     }

    //     rep(i,6){
    //         double q = qv[i];
    //         double x = xv[i];
    //         ll b = bv[i];
    //         f(f, n/b, p*q, q*c+q*x*p);
    //     }
    // };
    // f(f,N, 1., 0.);

    // printf("%.10f\n", ans);




    // map<ll,double> dp_c, dp_p;
    // priority_queue<Pdl, vector<Pdl>, greater<Pdl>> pq;
    // auto push = [&](double c, double p, ll x){
    //     if(dp_c.find(x)!=dp_c.end() && dp_c[x] <= c) return;
    //     dp_c[x] = c;
    //     dp_p[x] = p;
    //     cerr << "update: " << c << " " << p << " " << x << endl;
    //     if(x==0) return;
    //     pq.push({c,x});

    // };
    // push(0,1,N);

    // while(!pq.empty()){
    //     auto [c,x] = pq.top(); pq.pop();
    //     if(dp_c[x] < c) continue;
    //     c = dp_c[x];
    //     double p = dp_p[x];

    //     {
    //         double nc = c*1. + 1.*xx*p;
    //         double np = p*1.;
    //         ll nx = x/A;
    //         push(nc,np,nx);
    //     }
    //     for(ll b=2; b<=6; ++b){
    //         double nc = c*q + q*yy*p;
    //         double np = p*q;
    //         ll nx = x/b;
    //         push(nc,np,nx);
    //     }
    // }

    // printf("%.10f\n", dp_c[0]);





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
