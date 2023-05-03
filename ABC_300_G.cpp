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
        ll N,P;
        cin >> N >> P;

        vec(bool) isso(P+1, true);
        isso[0]=false;
        isso[1]=false;
        for(ll i=2;i<=P; i++){
            if(!isso[i]) continue;
            ll now = 2*i;
            while(now<=P){
                isso[now]=false;
                now+=i;
            }
        }

        vec(ll) so;
        rep1(i,P) if(isso[i]) so.push_back(i);

        // cout << so.size() << endl;
        // for(ll si:so) cout << si << " "; cout << endl;

        ll M = so.size();
        // vec(ll) cnt(M);
        // rep(i,M){
        //     ll now = 1;
        //     while(now<=N){
        //         cnt[i]++;
        //         now *= so[i];
        //     }
        // }
        
        vec(ll) u={1},v={1};

        auto f=[](vec(ll) &w, ll p, ll n){
            ll sz = w.size();
            rep(i,sz){
                ll now = w[i]*p;
                while(now<=n){
                    w.push_back(now);
                    now*=p;
                }
            }
        };


        for(ll si:so){
            ll un,vn;
            un = u.size(); vn=v.size();
            
            if(un<vn) f(u,si,N);
            else f(v,si,N);
        }

        sort(all(u));
        sort(all(v));

        ll ans = 0;
        for(ll ui:u){
            ll th = N/ui;
            auto it = upper_bound(all(v),th);
            ans += distance(v.begin(), it);
        }

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
