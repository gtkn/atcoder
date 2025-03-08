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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,M;
    cin >> N >> M;

    vec(ll) X(M),Y(M),Z(M);
    rep(i,M){
        cin >> X[i] >> Y[i] >> Z[i];
        --X[i]; --Y[i];
    }

    vvec(Pll) g(N);
    rep(i,M){
        g[X[i]].emplace_back(Y[i],Z[i]);
        g[Y[i]].emplace_back(X[i],Z[i]);
    }



    vec(ll) A(N,-1);
    bool isok = true;

    ll nn = 32;

    rep(st,N){
        if(A[st]!=-1) continue;

        vec(ll) ps;
        queue<ll> q;
        auto push = [&](ll pos, ll val)->void{
            if(A[pos]==-1){
                A[pos] = val;
                ps.push_back(pos);
                q.push(pos);
            }else{
                if(A[pos]!=val){
                    isok = false;
                }
            }
        };

        push(st,0);
        while(!q.empty()){
            ll now = q.front(); q.pop();
            // cerr << "now: " << now << endl;
            for(auto [nxt,zz]:g[now]){
                push(nxt,A[now]^zz);
            }
        }

        vec(ll) cnt(nn);
        for(ll pi:ps){
            ll vi = A[pi];
            rep(i,nn){
                if(bit(vi,i)) cnt[i]++;
            }
        }

        ll sz = ps.size();
        ll mask = 0;
        rep(i,nn){
            if(cnt[i]>sz-cnt[i]) mask |= (1<<i);
        }

        // cerr << "---" << endl;
        // cerr << "sz; " << sz << endl;
        // cerr << "mask: " << mask << endl;
        // for(ll pi:ps) cerr << pi << " " << A[pi] << endl;


        for(ll pi:ps) A[pi] ^= mask;
    }


    if(!isok) dame;
    rep(i,N) cout<<A[i]<<" "; cout << endl;








}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
