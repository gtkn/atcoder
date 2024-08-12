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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,K;
    cin >> N >> K;
    vec(string) S(N);
    rep(i,N) cin >> S[i];

    // ll tmp = 1;
    // rep(i,8){
    //     tmp *= 64-i;
    //     tmp /= i+1;
    // }
    // cerr << tmp << endl;
    // return;

    vvec(bool) vv(N,vec(bool)(N));
    rep(i,N)rep(j,N) vv[i][j] = (S[i][j]=='#');

    ll ans = 0;

    vvec(bool) used(N,vec(bool)(N));
    vec(Pll) res;
    set<vector<Pll>> used_res;

    auto f = [&](auto f)->void{
        if(res.size()==K){
            vec(Pll) tmp = res;
            sort(all(tmp));
            if(!sfind(used_res,tmp)){
                ans++;
                used_res.insert(tmp);
            }
            return;
        }

        for(Pll now:res){
            for(Pll d:dhw){
                ll ni = now.first+d.first, nj = now.second+d.second;
                if(ni<0||ni>=N||nj<0||nj>=N) continue;
                if(vv[ni][nj]) continue;
                if(used[ni][nj]) continue;
                used[ni][nj] = true;
                res.push_back({ni,nj});
                f(f);
                res.pop_back();
                used[ni][nj] = false;
            }
        }
    };



    rep(i,N)rep(j,N){
        if(vv[i][j]) continue;
        used[i][j] = true;
        res.push_back({i,j});
        f(f);
        used[i][j] = false;
        res.pop_back();
        vv[i][j] = true;
        // cerr << i << " " << j << " : " << ans << endl;
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
