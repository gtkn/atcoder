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
    ll N,M,L;
    cin >> N >> M >> L;

    vec(ll) a(N),b(M);
    rep(i,N) cin >> a[i];
    rep(i,M) cin >> b[i];

    vec(ll) c(L),d(L);
    rep(i,L) cin >> c[i] >> d[i];
    rep(i,L) c[i]--;
    rep(i,L) d[i]--;

    set<Pll> cd;
    rep(i,L) cd.emplace(c[i],d[i]);


    vec(Pll) aa(N),bb(M);
    rep(i,N) aa[i] = {a[i],i};
    rep(i,M) bb[i] = {b[i],i};

    sort(all(aa));
    sort(all(bb));


    ll ans = 0;

    queue<Pll> q;
    q.emplace(N-1,M-1);

    set<Pll> used;

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();


        if(cd.count( {aa[x].second, bb[y].second }  )){
            if(x>0){
                if(!used.count({x-1,y})){
                    q.emplace(x-1,y);
                    used.emplace(x-1,y);
                }
            }
            if(y>0){
                if(!used.count({x,y-1})){
                    q.emplace(x,y-1);
                    used.emplace(x,y-1);
                }
            }

        }else{
            chmax(ans, aa[x].first+bb[y].first );
        }
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
