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
    ll N;
    cin >> N;
    vec(string) S(N), T(N);
    rep(i,N) cin >> S[i];
    rep(i,N) cin >> T[i];

    
    auto f = [](vec(string) s)->vvec(bool){
        ll n = s.size();
        ll left=llINF,top=llINF,right=0,bottom=0;

        rep(i,n)rep(j,n){
            if(s[i][j]=='#'){
                chmin(left,j);
                chmin(top,i);
                chmax(right,j);
                chmax(bottom,i);
            }
        }

        ll h = bottom-top+1;
        ll w = right-left+1;
        vvec(bool) res(h,vec(bool)(w,false));
        rep(i,h)rep(j,w){
            if(s[top+i][left+j]=='#') res[i][j] = true;
        }

        return res;
    };


    vvec(bool) ss = f(S);
    vvec(bool) tt = f(T);

    auto rot = [](vvec(bool) s)->vvec(bool){
        ll h = s.size();
        ll w = s[0].size();
        vvec(bool) res(w,vec(bool)(h,false));
        rep(i,h)rep(j,w){
            res[j][h-1-i] = s[i][j];
        }
        return res;
    };

    auto same = [](vvec(bool) s, vvec(bool) t)->bool{
        ll h = s.size();
        ll w = s[0].size();
        if(h!=t.size() || w!=t[0].size()) return false;
        rep(i,h)rep(j,w){
            if(s[i][j]!=t[i][j]) return false;
        }
        return true;
    };

    rep(_,4){
        if(same(ss,tt)) sayyes;
        ss = rot(ss);
    }
    sayno;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
