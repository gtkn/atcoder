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
// using mint = modint;
// mint::set_mod(P);


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


struct S{
    mint val, sum;
    S(mint val=0, mint sum=0):val(val),sum(sum){}
};

struct F{
    ll add;
    F(ll add=0):add(add){}
};


S op(S a, S b){
    return S(a.val+b.val, a.sum+b.sum);
}
S ee(){
    return S(0,0);
}

S mapping(F f, S x){
    return S(x.val+x.sum*f.add, x.sum);
}

F composition(F f, F g){
    return F(f.add+g.add);
}

F id(){
    return F(0);
}







void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    // mint pnum = 0;
    // ll M = 200020;
    // fenwick_tree<ll> fw_cnt(M);
    // fenwick_tree<ll> fw_sum(M);

    // rep(i,N){
    //     mint k = (i+1);

    //     ll l = fw_cnt.sum(0,A[i]);

    //     pnum += 2*l*A[i];
    //     pnum += 2*fw_sum.sum(A[i],M);
    //     pnum += A[i];

    //     fw_cnt.add(A[i],1);
    //     fw_sum.add(A[i],A[i]);

    //     mint res = pnum/k/k;
    //     cout << res.val() << endl;

    // }



    vec(Pll) aa(N);
    rep(i,N) aa[i] = {A[i],i};

    vec(Pll) tmp = aa;
    sort(all(tmp));
    map<Pll,ll> mp;
    rep(i,N) mp[tmp[i]] = i;

    lazy_segtree<S,op,ee,F,mapping,composition,id> lseg(N);

    mint atot = 0;
    // set<ll> used;

    ll M = 200020;
    fenwick_tree<ll> fw_cnt(M);


    rep(i,N){
        ll x = mp[aa[i]];
        mint ai = A[i];
        mint n = (i+1);

        lseg.apply(x,N,F(1));
        // ll l = distance(used.begin(),used.lower_bound(x));
        ll l = fw_cnt.sum(0,x);
        lseg.set(x,S(ai*l, ai));
        // used.insert(x);
        fw_cnt.add(x,1);

        atot += ai;

        mint res = lseg.prod(0,N).val * 2 + atot;
        res /= n*n;

        cout << res.val() << endl;

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
