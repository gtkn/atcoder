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

    ll nn = 5050;

    //---転倒数-fenwicktree--
    ll inversions(vector<ll>& A){
        ll ans=0;
        fenwick_tree<int> ft(nn);
        for(auto ai:A){
            ans += ft.sum(ai,nn);
            ft.add(ai,1);
        }
        return ans;
    }

 
    void solve(){
        ll N;
        cin >> N;


        vec(ll) A(N),B(N);
        rep(i,N) cin >> A[i];
        rep(i,N) cin >> B[i];

        vec(ll) cnt(nn);
        bool f = false;
        rep(i,N) cnt[A[i]]++;
        rep(i,nn) if(cnt[i]>=2) f=true;
        rep(i,N) cnt[B[i]]--;

        rep(i,nn){
            if(cnt[i]!=0){
                // cout << i << " : " << cnt[i] << endl;
                cout << "No" << endl;
                return;
            }
        }


        ll aa = inversions(A);
        ll bb = inversions(B);

        // cout << aa << " , " << bb << endl;

        string ans = "Yes";
        if(abs(aa-bb)&1) ans="No";
        if(f) ans = "Yes";

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
