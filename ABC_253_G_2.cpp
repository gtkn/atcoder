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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,L,R;
    cin >> N >> L >> R;
    L--;

    vec(ll) A(N);
    rep(i,N) A[i] = i;


    vec(Pll) ids(N);
    {
        ll tmp = 0;
        rep(x,N){
            ids[x].first = tmp;
            tmp += N-x-1;
            ids[x].second = tmp;
        }
    }

    // rep(x,N){
    //     cerr << x << " : " << ids[x].first << " " << ids[x].second << endl;
    // }


    auto f = [&](ll idx)->Pll{
        auto itr = upper_bound(all(ids), Pll(idx,llINF) );
        itr--;
        Pll p = *itr;
        ll x = distance(ids.begin(),itr);
        ll d = idx - ids[x].first;
        ll y = x+1+d;
        // cerr << idx << " " << p.first <<" " << p.second << " , " <<  x << " " << d << " "<< y << endl;
        return {x,y};
    };


    rep(x,N){
        if(ids[x].first <= L && ids[x].second >=R){
            auto [xl,yl] = f(L);
            auto [xr,yr] = f(R-1);
            assert(xl==xr && xl==x && yl<=yr);
            for(ll y=yl; y<=yr; y++){
                swap(A[x],A[y]);
            }
            rep(i,N) cout << A[i]+1 << " "; cout << endl;
            return;
        }
    }


    ll a=-1,b=0;
    rep(x,N){
        if(ids[x].first <= L && L < ids[x].second){
            auto [xl,yl] = f(L);
            // cerr << x << " : " << xl << " , " << yl << endl;
            assert(xl==x);
            for(ll y=yl; y<N; y++) swap(A[x],A[y]);
        }
        if(L < ids[x].first && ids[x].second < R){
            if(a<0) a = x;
            b++;
        }
        if(ids[x].first < R && R <= ids[x].second){
            vec(ll) aa = A;
            rep(d,b) aa[a+d] = A[N-1-d];
            for(ll ii = a+b; ii<N; ii++) aa[ii] = A[ii-b];
            A = aa;
            auto [xr,yr] = f(R-1);
            // cerr << x << " " << xr << endl;
            assert(xr==x);
            for(ll y = x+1; y <= yr; y++) swap(A[x],A[y]);
        }
    }

    rep(i,N) cout << A[i]+1 << " "; cout << endl;
    

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
