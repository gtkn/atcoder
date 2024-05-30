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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N, M, K;
    cin >> N >> M >> K;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    if(M==1){
        rep(i,N) cout << A[i] << " "; cout << endl;
        return;
    }


    set<Pll> st0,st1;
    ll res = 0;
    vec(ll) ans;

    auto add = [&](ll a,ll id)->void{
        if(st0.size() == 0){
            st0.insert({a,id});
            return;
        }

        auto it = st0.rbegin();
        ll b = it->first;
        ll jd = it->second;

        if(a<b){
            st0.erase({b,jd});
            st0.insert({a,id});
            st1.insert({b,jd});
            res -= b;
            res += a;
        }else{
            st1.insert({a,id});
        }
    };

    auto del = [&](ll a,ll id)->void{
        if(sfind(st0,Pll(a,id))){
            st0.erase({a,id});
            res -= a;
            if(st1.size() > 0){
                auto it = st1.begin();
                ll b = it->first;
                ll jd = it->second;
                st1.erase({b,jd});
                st0.insert({b,jd});
                res += b;
            }
        }else{
            st1.erase({a,id});
        }
    };  


    vec(Pll) v(M);
    rep(i,M) v[i] = {A[i],i};
    sort(all(v));
    rep(i,K) st0.insert(v[i]);
    rep(i,K) res += v[i].first;
    for(ll i=K; i<M; ++i) st1.insert(v[i]);


    ans.push_back(res);

    for(ll i=M; i<N; ++i){
        del(A[i-M],i-M);
        add(A[i],i);
        ans.push_back(res);

        // cerr << "---" << i << endl;
        // cerr << "st0" << endl;
        // for(auto x: st0) cerr << x.first << " "; cerr << endl;
        // cerr << "st1" << endl;
        // for(auto x: st1) cerr << x.first << " "; cerr << endl;

    }


    for(auto x: ans) cout << x << " "; cout << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
