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
    ll N,M,Q;
    cin >> N >> M >> Q;
    vec(ll) A(M),B(M),C(M);
    rep(i,M) cin >> A[i] >> B[i] >> C[i];
    rep(i,M) A[i]--, B[i]--;

    vvec(Pll) g(N);
    rep(i,M){
        g[A[i]].push_back({B[i],C[i]});
        g[B[i]].push_back({A[i],-C[i]});
    }

    vec(ll) X(Q),Y(Q);
    rep(i,Q) cin >> X[i] >> Y[i];
    rep(i,Q) X[i]--, Y[i]--;

    dsu uf(N);
    rep(i,M) uf.merge(A[i],B[i]);


    auto grps = uf.groups();
    ll nn = grps.size();
    vec(ll) ids(N);
    rep(i,nn){
        for(auto v:grps[i]){
            ids[v] = i;
        }
    }

    vec(bool) isinf(nn);

    vec(ll) dp(N,-llINF);

    auto f = [&](ll st)->void{
        // cerr << st << " start" << endl;
        priority_queue<Pll> pq; // {point,vertex}
        dp[st] = 0;
        pq.push({0,st});

        bool isok = true;

        while(!pq.empty()){
            auto [d,now] = pq.top(); pq.pop();
            if(d<dp[now]) continue;
            for(auto [nxt,c]:g[now]){
                if(dp[nxt] != -llINF && dp[nxt] != dp[now]+c){
                    isok = false;
                }else if(chmax(dp[nxt],dp[now]+c)){
                    pq.push({dp[nxt],nxt});
                }
            }
        }

        if(!isok){
            isinf[ids[st]] = true;
        }

    };


    rep(i,N) if(dp[i] == -llINF) f(i);
    



    rep(i,Q){
        if(!uf.same(X[i],Y[i])){
            cout << "nan" << endl;
            continue;
        }
        if(isinf[ids[X[i]]]){
            cout << "inf" << endl;
            continue;
        }

        ll res = dp[Y[i]]-dp[X[i]];
        cout << res << endl;
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
