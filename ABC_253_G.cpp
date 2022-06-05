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
        ll N,L,R;
        cin >> N >> L >> R;

        L--; R--;

        vec(ll) A(N);
        rep(i,N) A[i] = i;

        vec(ll) v(N);
        rep1(i,N-1) v[i] = v[i-1] + (N-i);           
        
        ll xl,xr;
        rep(i,N-1){
            if(v[i]<= L && L<v[i+1]) xl=i;
            if(v[i]<= R && R<v[i+1]) xr=i;
        }

        //cout << xl << " , " << xr << endl;

        if(xl==xr){
            ll x = xl;
            for(ll i=L; i<=R; i++){
                ll y = x + (i-v[x]) + 1;
                swap(A[x],A[y]);
            }
            for(ll ai:A) cout << ai+1 << " ";
            cout << endl;
            return;
        }

        ll x;
        x = xl;
        for(ll i=L; i<v[x+1]; i++){
            ll y = x + (i-v[x]) + 1;
            swap(A[x],A[y]);
        }


        ll xm = xl+1;
        ll w = xr-xm;
        vec(ll) tmp = A;
        rep(i,w) A[xm+i] = tmp[N-1-i];
        for(ll i=xm+w; i<N; i++) A[i] = tmp[i-w];

        x = xr;
        for(ll i=v[xr]; i<=R; i++){
            ll y = x + (i-v[x]) + 1;
            swap(A[x],A[y]);
        }


        for(ll ai:A) cout << ai+1 << " ";
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
