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

struct Solver{

    void bit_hakidasi(vec(ll) &A){
        ll rnk = 0;
        ll N = A.size();
        repr(k,60){
            ll tmp = -1;
            for(ll i=rnk; i<N; i++){
                if(bit(A[i],k)){
                    tmp = A[i];
                    break;
                }
            }
            if(tmp==-1) continue;

            if(A[rnk]!=tmp) A[rnk]^=tmp;
            for(ll i=rnk+1; i<N; i++) chmin(A[i],A[i]^A[rnk]);
            rnk++;
        }

    }

 
    void solve(){
        ll N;
        cin >> N;
        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        ll odd=0;
        for(ll ai:A) odd^=ai;
        ll evn = ~odd;

        rep(i,N) A[i] &= evn;

        bit_hakidasi(A);

        ll r=0;
        for(ll ai:A) chmax(r,r^ai);
        cout << r*2 + odd << endl;

        // for(ll ai:A) cout << ai << " "; cout << endl;
        // cout << b << ", " << r << endl;


        // vec(ll) AA=A;
        // ll r = 0;
        // repr(k,61){
        //     ll tmp = 0;
        //     rep(i,N){
        //         if(!bit(A[i],k)) continue;
        //         if(tmp==0) swap(tmp,A[i]);
        //         else A[i] ^= tmp;
        //     }
        //     if(tmp!=0) r^=tmp;
        // }

        // ll b=0;
        // for(ll ai:A) b^=ai;
        // b^=r;

        // // for(ll ai:A) cout << ai << " "; cout << endl;
        // // cout << b << ", " << r << endl;
        // ll ans = b+r;

        // cout << ans << endl;


        // vec(ll) AA=A;
        // repr(k,61){
        //     ll tmp = 0;
        //     rep(i,N){
        //         if(!bit(A[i],k)) continue;
        //         if(tmp==0) tmp=A[i];
        //         else A[i] ^= tmp;
        //     }
        // }

        // ll r=0;
        // for(ll ai:A) chmax(r,r^ai);

        // ll b=0;
        // for(ll ai:AA) b^=ai;
        // b^=r;

        // for(ll ai:A) cout << ai << " "; cout << endl;
        // cout << b << ", " << r << endl;


        // ll ans = b+r;

        // cout << ans << endl;




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
