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


ll opa(ll a,ll b){
    return a+b;
}
ll eea(){
    return 0;
}

ll opb(ll a,ll b){
    return a*b;
}
ll eeb(){
    return 1;
}




void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];

    segtree<ll,opa,eea> sega(A);
    // segtree<ll,opb,eeb> segb(B);


    set<ll> st;
    rep(i,N) if(B[i]>1) st.insert(i);
    st.insert(N);


    ll Q;
    cin >> Q;
    while(Q--){
        ll t;
        cin >> t;

        if(t==1){
            ll i,x;
            cin >> i >> x;
            i--;
            sega.set(i,x);
            A[i] = x;
        }
        if(t==2){
            ll i,x;
            cin >> i >> x;
            i--;
            ll y = B[i];
            if(y>1 && x==1) st.erase(i);
            if(y==1 && x>1) st.insert(i);
            // segb.set(i,x); 
            B[i] = x;
        }
        if(t==3){
            ll l,r;
            cin >> l >> r;
            l--; r--;

            ll v = A[l];
            while(l<r){
                ll m = *st.upper_bound(l);
                chmin(m,r);
                v += sega.prod(l+1,m);
                v = max(v+A[m], v*B[m]);
                l = m;
                // if(l==r) break;
            }
            cout << v << endl;


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
