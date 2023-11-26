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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


void solve(){
    ll H,W,N;
    cin >> H >> W >> N;

    set<Pll> ab;
    rep(_,N){
        ll a,b;
        cin >> a >> b;
        ab.emplace(a,b);
    }

    vector<set<Pll>> vs(10);

    auto f = [&](Pll p)->void{
        for(ll h=p.first-2; h <=p.first; h++){
            for(ll w=p.second-2; w <=p.second; w++){
                ll cnt = 0;
                for(ll x=h; x<h+3;x++)for(ll y=w; y<w+3; y++){
                    if(x<=0 || x>H || y<=0 || y>W){
                        cnt=-llINF;
                    }else{
                        if(ab.count({x,y})) cnt++;
                    }
                }
                if(cnt>=0){
                    vs[cnt].emplace(h,w);
                    // cout << p.first << ", " << p.second <<" : " << h << ", " << w << " ; " << cnt << endl;
                }
            }          
        }
    };

    for(Pll abi:ab) f(abi);

    vec(ll) ans(10);
    rep1(i,9) ans[i] = vs[i].size();

    ans[0] = (H-2)*(W-2);
    rep1(i,9) ans[0] -= ans[i];

    rep(i,10) cout << ans[i] << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
