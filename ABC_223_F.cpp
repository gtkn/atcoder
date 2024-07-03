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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

ll op(ll a,ll b){
    return min(a,b);
}
ll ee(){
    return llINF;
}

ll mapping(ll f,ll x){
    return f+x;
}
ll composition(ll f,ll g){
    return f+g;
}
ll id(){
    return 0;
}


void solve(){
    ll N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vec(ll) v(N);
    rep(i,N){
        if(S[i]=='(') v[i]=1;
        else v[i]=-1;
    }

    vec(ll) cum(N+1);
    rep1(i,N){
        cum[i] = cum[i-1]+v[i-1];
    }

    lazy_segtree<ll,op,ee,ll,mapping,composition,id> lseg(cum);


    while(Q--){
        ll t,l,r;
        cin >> t >> l >> r;
        if(t==1){
            ll d = v[r-1] - v[l-1];
            lseg.apply(l,r,d);
            swap(v[l-1],v[r-1]);
        }else{
            bool isok = true;
            ll al = lseg.get(l-1);
            if(al != lseg.get(r)) isok = false;
            if(lseg.prod(l-1,r+1) - al < 0) isok = false;
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
