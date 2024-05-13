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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


mt19937_64 rng(time(0));
constexpr ll BN = 5;
ll mods[BN] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
ll base[BN];

struct Hash{
    ll h1,h2,pw;
};
using S = array<Hash, BN>;

S op(S lhs,S rhs){
    S res;
    rep(i,BN){
        res[i].h1 = ( lhs[i].h1 * rhs[i].pw  + rhs[i].h1 )%mods[i];
        res[i].h2 = ( rhs[i].h2 * lhs[i].pw  + lhs[i].h2 )%mods[i];
        res[i].pw = ( lhs[i].pw * rhs[i].pw )%mods[i];
    }
    return res;
}
S ee(){
    S res;
    rep(i,BN) res[i] = {0,0,1};
    return res;
}
S gen(char c){
    S res;
    rep(i,BN){
        res[i].h1 = res[i].h2 = c; // そのままでOK
        res[i].pw = base[i];
    }
    return res;
}


void solve() {
    ll N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;

    rep(i,BN) base[i] = rand() % mods[i];


    vec(S) v(N);
    rep(i,N) v[i] = gen(s[i]);

    segtree<S, op, ee> seg(v);

    while(Q--){
        ll t; cin >> t;
        if(t==1){
            ll x; char c;
            cin >> x >> c;
            seg.set(x-1, gen(c));
        }else{
            ll l,r;
            cin >> l >> r;
            l--;
            S res = seg.prod(l,r);

            bool isok=true;
            for(Hash h:res){
                if(h.h1!=h.h2) isok=false;
            }
            if(isok) sayyn;
        }
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
