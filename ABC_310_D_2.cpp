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
    ll N,T,M;
    cin >> N >> T >> M;

    vvec(ll) ab(N);
    rep(_,M){
        ll a,b;
        cin >> a >> b;
        --a; --b;
        ab[b].push_back(a);
    }

    ll ans = 0;
    vvec(bool) mem(T,vec(bool)(N));
    vec(ll) num(T);

    auto f = [&](auto f, ll now)->void{
        if(now==N){
            if(num[T-1]>0) ans++;
            // rep(i,T){
            //     rep(j,N) if(mem[i][j]) cerr << j << " ";
            //     cerr << " / " ;
            // }
            // cerr << endl;
            return;
        }
        rep(i,T){
            bool isok = true;
            for(ll a:ab[now])if(mem[i][a]) isok=false;
            if(!isok) continue;

            mem[i][now] = true;
            num[i]++;
            f(f,now+1);
            mem[i][now] = false;
            num[i]--;

            if(num[i]==0) break;
        }
    };

    f(f,0);
    
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
