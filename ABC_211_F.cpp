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


bool op(bool a, bool b){
    return a|b;
}
bool ee(){
    return false;
}

bool mapping(bool f, bool x){
    if(f) return !x;
    return x;
}
bool composition(bool f, bool g){
    return f^g;
}

bool id(){
    return false;
}




ll op2(ll a,ll b){
    return a+b;
}
ll ee2(){
    return 0;
}
ll mapping2(ll f,ll x){
    return x+f;
}
ll composition2(ll f,ll g){
    return f+g;
}
ll id2(){
    return 0;
}









void solve(){
    ll N;
    cin >> N;

    vvec(Pll) vv(N);
    rep(i,N){
        ll M;
        cin >> M;
        vv[i].resize(M);
        rep(j,M) cin >> vv[i][j].first >> vv[i][j].second;
    }

    ll W = 100010;
    vvec(tri) lrd(W);
    lazy_segtree<bool, op, ee, bool, mapping, composition, id> lseg(W);

    for(const vec(Pll) v:vv){
        ll m = v.size();
        vec(tri) ylr;
        rep(i,m){
            ll j = (i+1)%m;
            ll l = v[i].first, r = v[j].first;
            if(l==r) continue;
            if(l>r) swap(l,r);
            ylr.emplace_back(v[i].second,l,r);
        }
        sort(all(ylr));

        for(auto [y,l,r]:ylr){
            if(lseg.prod(l,r)){
                lrd[y].emplace_back(l,r,-1);
            }else{
                lrd[y].emplace_back(l,r,1);
            }
            lseg.apply(l,r,true);
        }

        if(lseg.all_prod()){
            cerr << "dame" << endl;
            for(auto [y,l,r]:ylr){
                cerr << y << " " << l << " " << r << endl;
            }
        }
        // assert(lseg.all_prod() == false);
    }



    ll Q;
    cin >> Q;
    vvec(Pll) qx(W);
    rep(i,Q){
        ll x,y;
        cin >> x >> y;
        qx[y].emplace_back(x,i);
    }
    vec(ll) ans(Q);


    lazy_segtree<ll,op2,ee2,ll,mapping2,composition2,id2> lseg2(W);
    rep(y,W){
        for(auto [l,r,d]:lrd[y]){
            lseg2.apply(l,r,d);
        }
        for(auto [x,idx]:qx[y]){
            ans[idx] = lseg2.get(x);
        }
    }

    rep(i,Q) cout << ans[i] << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
