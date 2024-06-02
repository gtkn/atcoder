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
constexpr ll llINF = 3e18;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

/***
 * 区間和、区間変更のlsegはそのままだとダメなのでSを定義する
 * Sを定義したときはlseg作った後に初期化が必要
***/


ll op2(ll a,ll b){
    return a+b;
}
ll ee2(){
    return 0;
}




struct S{
    ll sz;
    ll val;
};
struct F{ll k;};

S op(S l,S r){
    return S{l.sz+r.sz, l.val+r.val};
}
S ee(){
    return S{0,0};
}

S mapping(F f, S x){
    if(f.k>=0) return S{ x.sz, f.k*x.sz };
    return x;
}
F composition(F f,F g){
    if(f.k>=0) return f;
    return g;
}
F id(){return F{-1};}





void solve(){
    ll Q,K;
    cin >> Q >> K;

    vec(ll) t(Q),x(Q);
    rep(i,Q) cin >> t[i] >> x[i];


    set<ll> st;
    for(ll xi:x) st.insert(xi);
    st.insert(-llINF);
    st.insert(llINF);
    ll nn = 0;
    map<ll,ll> mp;
    for(ll xi:st) mp[xi] = nn++;
    vec(ll) pm(nn);
    for(ll xi:st) pm[mp[xi]] = xi;

    lazy_segtree<S,op,ee,F,mapping,composition,id> lseg(nn);
    // set<ll> S;
    // S.insert(-llINF);
    // S.insert(llINF);
    rep(i,nn) lseg.set(i,S{1,0});

    segtree<ll,op2,ee2> seg(nn);
    seg.set(0,1);
    seg.set(nn-1,1);    






    rep(i,Q){
        ll xi = x[i];
        ll y = mp[xi];

        if(t[i]==1){
            ll l,r;

            ll tmpl=0,tmpr=y;
            while(tmpr-tmpl>1){
                ll mid = (tmpl+tmpr)/2;
                if(seg.prod(mid,y)==0) tmpr = mid;
                else tmpl = mid;
            }
            l = tmpl;

            tmpl = y+1, tmpr = nn;
            while(tmpr-tmpl>1){
                ll mid = (tmpl+tmpr)/2;
                if(seg.prod(y+1,mid)==0) tmpl = mid;
                else tmpr = mid;
            }
            r = tmpl;

            if(seg.get(y)==0){
                seg.set(y,1);
                if(abs(pm[r]-xi)<=K) lseg.apply(y,r,F{1});
                if(abs(xi-pm[l])<=K) lseg.apply(l,y,F{1});
            }else{
                seg.set(y,0);
                if(abs(pm[r]-pm[l])>K) lseg.apply(l,r,F{0});
            }
        }else{
            ll y = mp[xi];

            ll l = y, r = nn;
            while(r-l>1){
                ll mid = (l+r)/2;
                if(lseg.prod(y,mid).val==mid-y) l = mid;
                else r = mid;
            }
            ll th1 = r;

            l = 0, r = y;
            while(r-l>1){
                ll mid = (l+r)/2;
                if(lseg.prod(mid,y).val==y-mid) r = mid;
                else l = mid;
            }
            ll th0 = r;


            ll res = seg.prod(th0,th1);
            cout << res << endl;
        }

        // cerr << "---" << i << "---" << endl;
        // cerr << t[i] << " " << x[i] << endl;
        // rep(i,nn) cerr << seg.get(i) << " "; cerr << endl;
        // rep(i,nn) cerr << pm[i] << " "; cerr << endl;
        // rep(i,nn) cerr << lseg.get(i).val << " "; cerr << endl;
        // cerr << endl;


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
