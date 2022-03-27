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
 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,M;
        cin >> N >> M;
        vec(ll) A(N),B(N),C(M),D(M);
        rep(i,N) cin >> A[i];
        rep(i,N) cin >> B[i];
        rep(i,M) cin >> C[i];
        rep(i,M) cin >> D[i];

        vec(Pll) vn,vm;
        rep(i,N) vn.emplace_back(A[i],B[i]);
        rep(i,M) vm.emplace_back(C[i],D[i]);

        sort(all(vn));
        sort(all(vm));

        sort(all(A),greater<ll>());
        multiset<ll> rem;

        for(ll x:A){
            multiset<ll> now;
            while(!vn.empty() && vn.back().first>=x){
                now.insert(vn.back().second);
                vn.pop_back();
            }
            
            while( !vm.empty() && vm.back().first>=x ){
                rem.insert(vm.back().second);
                vm.pop_back();
            }

            for(ll y:now){
                auto itr = lower_bound(all(rem),y);
                if(itr==rem.end()){
                    cout << "No" << endl;
                    return;
                }
                //cout << x << " : " << y << ", " << *itr << endl;
                rem.erase(*itr);
            }
        }
        cout << "Yes" << endl;




        /*
        set<ll> sx,sy;
        rep(i,N) sx.insert(A[i]);
        rep(i,N) sy.insert(B[i]);
        rep(i,M) sx.insert(C[i]);
        rep(i,M) sy.insert(D[i]);

        map<ll,ll> mx,my;
        ll cnt=0;
        for(ll si:sx) mx[si]=cnt++;
        cnt=0;
        for(ll si:sy) my[si]=cnt++;

        map<ll,vector<ll>> mn,mm;
        rep(i,N) mn[mx[A[i]]].push_back(my[B[i]]);
        rep(i,M) mm[mx[C[i]]].push_back(my[D[i]]);

        vec(ll) vx;
        for(ll si:sx) vx.push_back(si);
        sort(all(vx),greater<ll>());
        */
            







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
