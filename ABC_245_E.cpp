//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (int i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目
#define vec(T) vector<T>
#define vvec(T) vector<vector<T>>
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
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

 
 
 
    void solve(){
        ll N,M;
        cin >> N >> M;
        vec(ll) A(N),B(N),C(M),D(M);
        rep(i,N) cin >> A[i];
        rep(i,N) cin >> B[i];
        rep(i,M) cin >> C[i];
        rep(i,M) cin >> D[i];

        vec(abc) v;
        rep(i,N) v.emplace_back(A[i],B[i],0);
        rep(i,M) v.emplace_back(C[i],D[i],1);

        sort(all(v),[](abc const& x, abc const& y){
            if(x.a!=y.a) return x.a<y.a;
            if(x.b!=y.b) return x.b<y.b;
            return x.c<y.c;
        });


        multiset<ll> s;
        while(!v.empty()){
            abc now=v.back();
            v.pop_back();

            if(now.c==0){
                auto itr = s.lower_bound(now.b);
                if(itr==s.end()){
                    cout << "No" << endl;
                    return;
                }
                s.erase(itr);
            }else{
                s.insert(now.b);
            }
        }
        cout << "Yes" << endl;


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
