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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

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
        vec(ll) B(N),C(M);
        rep(i,N) cin >> B[i];
        rep(i,M) cin >> C[i];

        sort(all(B), greater<ll>());

        vector<tuple<ll,ll,ll>> v = {{0,1,B[0]}};

        rep(i,N){
            if(i==0) continue;
            ll x_now,a_now,b_now;
            x_now = 0;
            a_now = i+1;
            b_now = a_now*B[i];
            while(!v.empty()){
                auto [x_pre,a_pre,b_pre]{v.back()};
                
                ll da,db;
                da = a_now-a_pre;
                db = b_pre-b_now;
                
                assert(da>0);
                
                if(db>=0){
                    x_now = db/da;
                    if(db%da>0) x_now++;
                }else{
                    x_now = db/da;
                }

                if(x_pre*a_pre+b_pre <= x_pre*a_now+b_now) v.pop_back();
                else break;

            }
            v.emplace_back(x_now,a_now,b_now);
        }

        // for(auto vi:v){
        //     cout << get<0>(vi) << " " << get<1>(vi) << " " << get<2>(vi) << " " << endl;
        // }

        for(ll ci:C){
            auto it = lower_bound(all(v),make_tuple(ci+1,0,0));
            it--;
            auto [x,a,b](*it);
            cout << a*ci+b << " ";
            // cout << ":" << ci << " , " << x <<" , " << a << " , " << b << endl;
        }
        cout << endl;


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
