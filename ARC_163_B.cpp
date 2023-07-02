//title
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

ll op(ll a,ll b){return a+b;}
ll ee(){return 0;}


struct Solver{
    void solve(){
        ll N,M;
        cin >> N >> M;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        // map<ll,ll> acnt;
        // for(ll i=2; i<N; i++) acnt[A[i]]++;

        // set<ll> s;
        // for(ll ai:A) s.insert(ai);

        // map<ll,ll> m;
        // ll nn = 0;
        // for(ll si:s) m[si] = nn++;


        ll a0=A[0],a1=A[1];
        vec(ll) B(N-2);
        rep(i,N-2) B[i]=A[i+2];
        sort(all(B));

        ll ans = llINF;
        rep(i,N-2){
            ll b0,b1;
            b0 = B[i];

            ll j = i+M-1;
            if(j >= N-2) break;
            b1 = B[j];

            ll tmp = 0;
            if(a0 > b0) tmp += a0-b0;
            if(a1 < b1) tmp += b1-a1;

            // cout << i << " , " << j << "!" << endl;
            // cout << b0 << " , " << b1 << ": " << tmp << endl;

            chmin(ans, tmp );

        }

        cout << ans << endl;


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
