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
// using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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

Pll op(Pll a, Pll b){
    if(a.first == b.first){
        return {a.first, a.second+b.second};
    }else{
        if(a.first < b.first) return a;
        else return b;
    }
}

Pll ee(){return {llINF,0};}

Pll mapping(ll f, Pll x){
    return {x.first+f, x.second};
}

ll composition(ll f, ll g){
    return f+g;
}

ll id(){return 0;}






void solve(){
    ll N;
    cin >> N;

    vec(ll) A(N+2);
    rep1(i,N) cin >> A[i];

    ll nn = 200020;
    vvec(ll) vv(nn,{0});
    rep1(i,N) vv[A[i]].push_back(i);
    rep(i,nn) vv[i].push_back(N+1);

    vvec(tri) query(N+2);
    rep(i,nn){
        ll m = vv[i].size();
        rep(j,m-2){
            query[vv[i][j]+1].push_back( {vv[i][j+1]+1, vv[i][j+2]+1, 1}  );
            query[vv[i][j+1]+1].push_back( {vv[i][j+1]+1, vv[i][j+2]+1, -1}  );
        }
    }

    lazy_segtree<Pll, op, ee, ll, mapping, composition, id> seg( vec(Pll)(N+2,{0,1}) );
    
    ll ans = 0;
    rep(i,N+2){
        for(auto q: query[i]){
            // cerr << q[0] << ' ' << q[1] << ' ' << q[2] << endl;
            seg.apply(q[0],q[1],q[2]);
        }
        Pll now = seg.all_prod();
        if(now.first == 0) ans += (N+2 - now.second);
        // cerr << i << " ---- " << ans << endl;
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
