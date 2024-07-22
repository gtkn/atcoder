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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;


    auto f1 = [&](ll bmax)->ll{
        // assert(bmax<1e8);
        ll res = 0;
        for(ll b = 2; b<=bmax; b++){
            ll tmp = N;
            bool isok = true;
            ll cnt = 0;
            while(tmp>0){
                ll r = tmp%b;
                if(r>1){
                    isok=false;
                    break;
                }
                tmp/=b;
                cnt++;
            }
            if(isok && cnt>8) res++;
        }
        return res;
    };

    auto g = [](ll b, ll z)->ll{
        ll res = 0;
        vec(ll) v;
        while(z){
            v.push_back(z&1);
            z>>=1;
        }
        reverse(all(v));
        for(bool vi:v){
            if(res>llINF/b) return llINF;
            res = res*b+vi;
        }
        return res;
    };


    auto f2 = [&](ll kmax)->ll{
        ll res = 0;
        for(ll z = 2; z < (1<<kmax); z++){
            ll l = 2, r = N+1;
            while(r-l>1){
                ll m = (l+r)/2;
                if( g(m,z)>N ) r=m;
                else l = m;
            }
            if(g(l,z)==N){
                res++;
            }
        }
        return res;
    };


    auto h = [&]()->ll{
        ll res=2;
        for(ll x=2; x<N; x++){
            ll tmp = 1;
            rep(_,8){
                if(tmp>N/x){
                    tmp = llINF;
                    break;
                }
                tmp *= x;
            }
            if(tmp<=N) res = x;
            else break;
        }
        return res;
    };



    ll ans = 0;
    ans += f2(8);
    ans += f1(h());
    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
