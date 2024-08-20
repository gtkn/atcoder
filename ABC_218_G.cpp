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
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vvec(ll) g(N);
    rep(_,N-1){
        ll u,v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    auto f = [&](auto f, ll now, ll frm, ll dep, ll cnt0, ll cnt1, ll max0, ll min1, ll th)->bool{
        if(A[now]<=th){
            chmax(max0,A[now]);
            cnt0++;
        }else{
            chmin(min1,A[now]);
            cnt1++;
        }

        vec(bool) memo;
        for(ll nxt:g[now])if(nxt!=frm){
            memo.push_back(f(f,nxt,now,dep+1,cnt0,cnt1,max0,min1,th));
        }

        if(memo.size()==0){
            // cerr << now <<" " << cnt0 << " " << cnt1 << " " << max0 << " " << min1 << endl;
            if(cnt0!=cnt1){
                return cnt0 < cnt1;
            }
            return (max0 + min1)/2 > th;
        }

        if(dep&1){
            for(bool b:memo){
                if(!b) return false;
            }
            return true;
        }else{
            for(bool b:memo){
                if(b) return true;
            }
            return false;
        }

        return false;
    };


    

    ll l = 0, r = llINF;
    while(r-l>1){
        ll mid = (l+r)/2;
        // cerr << "th = " << mid << endl;
        if(f(f,0,0,0,0,0,-llINF,llINF,mid)){
            l = mid;
        }else{
            r = mid;
        }
    }

    cout << r << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}