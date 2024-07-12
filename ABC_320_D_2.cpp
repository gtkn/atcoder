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


void solve(){
    ll N,M;
    cin >> N >> M;
    vec(ll) A(M),B(M),X(M),Y(M);

    rep(i,M) cin >> A[i] >> B[i] >> X[i] >> Y[i];

    // dsu uf(N);
    // rep(i,M){
    //     uf.merge(A[i]-1,B[i]-1);
    // }

    // if(uf.groups().size()!=1){
    //     cout << "undecidable" << endl;
    //     return;
    // }



    vvec(tri) g(N+1);
    rep(i,M){
        g[A[i]].emplace_back(B[i],X[i],Y[i]);
        g[B[i]].emplace_back(A[i],-X[i],-Y[i]);
    }

    vec(Pll) ans(N+1);
    vec(bool) used(N+1);

    queue<ll> q;
    q.push(1);

    while(!q.empty()){
        ll now = q.front();
        q.pop();
        if(used[now]) continue;
        used[now] = true;

        for(auto [to,x,y]:g[now]){
            ans[to] = {ans[now].first+x,ans[now].second+y};
            q.push(to);
        }    
    }

    rep1(i,N){
        if(used[i]){
            cout << ans[i].first << " " << ans[i].second << endl;
        }else{
            cout << "undecidable" << endl;
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
