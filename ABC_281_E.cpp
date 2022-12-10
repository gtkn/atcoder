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

#define dame { puts("-1"); return;}
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
        ll N,M,K;
        cin >> N >> M >> K ;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        multiset<ll> s0,s1;
        vec(ll) tmp;
        rep(i,M) tmp.push_back(A[i]);
        sort(all(tmp));
        rep(i,M){
            if(i<K) s0.insert(tmp[i]);
            else s1.insert(tmp[i]);
        }

        ll tot = 0;
        for(ll si:s0) tot+=si;
        s0.insert(0);
        s1.insert(llINF);

        rep(i,N-M+1){
            cout << tot << " ";

            ll ii = i+M;
            if(ii==N) break;


            if(A[i] > *(--s0.end())){
                s1.erase(s1.find(A[i]));
            }else{
                s0.erase(s0.find(A[i]));
                tot-=A[i];
            }

            if(A[ii] > *(--s0.end())){
                s1.insert(A[ii]);
            }else{
                s0.insert(A[ii]);
                tot+=A[ii];
            }

            while(s0.size()<K+1){
                ll x = *s1.begin();
                s1.erase(s1.find(x));
                s0.insert(x);
                tot+=x;
            }

            while(s0.size()>K+1){
                ll x = *(--s0.end());
                s0.erase(s0.find(x));
                tot-=x;
                s1.insert(x);
            }




        }

        cout << endl;

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
