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
        ll H,W,rs,cs;
        cin >> H >> W >> rs >> cs;
        ll N;
        cin >> N;


        map<ll,set<ll>> mr,mc;
        rep(_,N){
            ll ri,ci;
            cin >> ri >> ci;
            mr[ri].insert(ci);
            mc[ci].insert(ri);
        }

        for(auto mi:mr){
            mr[mi.first].insert(0);
            mr[mi.first].insert(W+1);
        }
        for(auto mi:mc){
            mc[mi.first].insert(0);
            mc[mi.first].insert(H+1);
        }

        ll Q;
        cin >> Q;
        while(Q--){
            char di;
            ll li;
            cin >> di >> li;

            if(di=='L'){
                if(!mr[rs].empty()){
                    auto itr = mr[rs].upper_bound(cs);
                    itr--;
                    ll x = *itr;
                    cs = max(x+1, cs-li);
                }else cs = max(1LL, cs-li);
            }
            if(di=='R'){
                if(!mr[rs].empty()){
                    auto itr = mr[rs].upper_bound(cs);
                    ll x = *itr;
                    cs = min(x-1, cs+li);
                }else cs = min(W, cs+li);
            }
            if(di=='U'){
                if(!mc[cs].empty()){
                    auto itr = mc[cs].upper_bound(rs);
                    itr--;
                    ll x = *itr;
                    rs = max(x+1, rs-li);
                }else rs = max(1LL, rs-li);
            }
            if(di=='D'){
                if(!mc[cs].empty()){
                    auto itr = mc[cs].upper_bound(rs);
                    ll x = *itr;
                    rs = min(x-1, rs+li);
                }else rs = min(H, rs+li);
            }

            cout << rs << " " << cs << endl;

        }








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
