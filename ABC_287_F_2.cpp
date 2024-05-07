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
using mint = modint998244353;


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
    ll N;
    cin >> N;

    vvec(ll) g(N);
    rep(_,N-1){
        ll a,b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    auto f = [&](auto f, ll now, ll frm)->vvec(mint){
        vvec(mint) dp_now(2,vec(mint)(2));
        dp_now[0][0] = 1;
        dp_now[1][1] = 1;
        
        for(ll nxt:g[now])if(nxt!=frm){
            vvec(mint) dp_nxt = f(f,nxt,now);

            ll n_now = dp_now[0].size();
            ll n_nxt = dp_nxt[0].size();
            vvec(mint) dp_tmp(2, vec(mint)(n_now+n_nxt-1));
            rep(i,n_now)rep(j,n_nxt){
                dp_tmp[0][i+j] += dp_now[0][i] * dp_nxt[0][j];
                dp_tmp[0][i+j] += dp_now[0][i] * dp_nxt[1][j];
                dp_tmp[1][i+j] += dp_now[1][i] * dp_nxt[0][j];
                if(i+j>0) dp_tmp[1][i+j-1] += dp_now[1][i] * dp_nxt[1][j];
            }
            swap(dp_now,dp_tmp);
        }

        // cerr << now << "---" << endl;
        // for(mint x:dp_now[0]) cerr << x.val() << " "; cerr << endl;
        // for(mint x:dp_now[1]) cerr << x.val() << " "; cerr << endl;

        return dp_now;
    };

    vvec(mint) res = f(f,0,0);

    rep1(i,N){
        mint ans = res[0][i] + res[1][i];
        cout << ans.val() << endl;
    }






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
