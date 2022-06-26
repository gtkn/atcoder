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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,M;
        cin >> N >> M;
        vec(ll) A(M),B(M);
        rep(i,M) cin >> A[i];
        rep(i,M) cin >> B[i];

        //dsu d(N+1);
        //rep(i,M) d.merge(A[i],B[i]);


        vvec(ll) g0(N+1);
        rep(i,N){
            g0[A[i]].push_back(B[i]);
            g0[B[i]].push_back(A[i]);
        }

        vector<set<ll>> g1(N+1);
        vec(bool) used(N+1);

        rep1(st,N){
            if(used[st]) continue;
            queue<ll> q;
            auto qpush = [&](ll to, ll fr){
                if(used[to]) return;
                used[to]=true;
                g1[fr].insert(to);
                q.push(to);
            };
            qpush(st,0);

            while(!q.empty()){
                ll now = q.front();
                q.pop();
                for(ll to:g0[now]) qpush(to,now);
            }
        }


        vec(ll) ans(M);
        rep(i,M){
            if( sfind( g1[A[i]], B[i]) ) ans[i]=0;
            else ans[i]=1;
        }
        for(ll ai:ans ) cout << ai; cout << endl;


    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
