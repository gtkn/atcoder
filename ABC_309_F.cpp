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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

ll op(ll a,ll b){return min(a,b);}
ll ee(){return llINF;}


struct Solver{
 
    void solve(){
        ll N;
        cin >> N;

        vvec(ll) hwd(N,vec(ll)(3));
        rep(i,N)rep(j,3) cin >> hwd[i][j];

        set<ll> s;
        rep(i,N)rep(j,3) s.insert(hwd[i][j]);

        map<ll,ll> m;
        ll nn = 0;
        for(ll si:s) m[si]=nn++;


        vvec(Pll) vv(nn);
        rep(i,N){
            vec(ll) tmp = hwd[i];
            rep(j,3) tmp[j] = m[tmp[j]];
            sort(all(tmp));

            vv[tmp[0]].emplace_back(tmp[1],tmp[2]);
        }

        segtree<ll,op,ee> seg(nn);
        string ans = "No";
        rep(a,nn){
            for(Pll bc:vv[a]){
                auto [b,c] = bc;
                // cout << a << " , " << b << " , " << c << endl;
                if( seg.prod(0,b) < c) ans = "Yes";
            }
            for(Pll bc:vv[a]){
                auto [b,c] = bc;
                seg.set(b, min(c,seg.get(b)) );
            }            
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
